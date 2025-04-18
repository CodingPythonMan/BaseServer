#include "NetworkHost.h"
#include "NetworkEvent.h"
#include "IOContext.h"
#include <MSWSock.h>
#include "TimeUtil.h"

void NetworkHost::SetEvent(NetworkEvent* networkEvent)
{
	mNetworkEvent = networkEvent;
}

void NetworkHost::SetIP(std::string ip)
{
	mIP = ip;
}

void NetworkHost::SetPortNum(int port)
{
	mPort = port;
}

void NetworkHost::SetIsRecv(bool check)
{
	mIsRecv = check;
}

SOCKET NetworkHost::GetSocket()
{
	return mSocket;
}

int NetworkHost::GetHostID()
{
	return mHostID;
}

bool NetworkHost::IsAlive()
{
	if (mSocket != INVALID_SOCKET
		|| mNetworkTaskCount > 0
		|| mSendTaskCount > 0)
	{
		return true;
	}

	return false;
}

void NetworkHost::Update(int64_t tick)
{
	if (mSocket == INVALID_SOCKET)
	{
		return;
	}

	switch (mType)
	{
	case EHostType::LISTENER:
		_UpdateListener(tick);
		break;
	case EHostType::ACCEPTOR:
		_UpdateAcceptor(tick);
		break;
	case EHostType::CONNECTOR:
		_UpdateConnector(tick);
		break;
	}
}

bool NetworkHost::Disconnect()
{
	if (mSocket == INVALID_SOCKET)
	{
		return false;
	}

	::closesocket(mSocket);
	mSocket = INVALID_SOCKET;

	return true;
}

bool NetworkHost::Connect(IOContext& context)
{
	if (mSocket == INVALID_SOCKET)
	{
		printf("mSocket is invalid!\n");
		return false;
	}

	static LPFN_CONNECTEX ConnectEx = nullptr;
	if (ConnectEx == nullptr)
	{
		GUID guid = WSAID_CONNECTEX;
		DWORD bytes = 0;

		if (::WSAIoctl(mSocket, SIO_GET_EXTENSION_FUNCTION_POINTER, &guid, sizeof(guid),
			&ConnectEx, sizeof(ConnectEx), &bytes, nullptr, nullptr) != 0)
		{
			printf("mSocket is invalid!\n");
			return false;
		}
	}

	SOCKADDR_IN local = {};
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = INADDR_ANY;

	if (::bind(mSocket, (SOCKADDR*)&local, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		printf("bind is failed ! :%d", ::WSAGetLastError());
		return false;
	}

	SOCKADDR_IN remote;
	::memset(&remote, 0, sizeof(remote));
	remote.sin_family = AF_INET;
	::InetPtonA(AF_INET, mIP.c_str(), &remote.sin_addr);
	remote.sin_port = htons(mPort);

	context.Ready(EContextType::CONNECT);
	context.IncreaseReferenceCount();

	if (ConnectEx(mSocket, (sockaddr*)&remote, sizeof(remote), nullptr, 0, nullptr, &context) == FALSE)
	{
		int error = ::WSAGetLastError();
		if (error != WSA_IO_PENDING)
		{
			context.DecreaseReferenceCount();
			return false;
		}
	}

	return true;
}

bool NetworkHost::Listen()
{
	mType = EHostType::LISTENER;

	SOCKADDR_IN addr;
	::memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	::InetPtonA(AF_INET, mIP.c_str(), &addr.sin_addr);
	addr.sin_port = htons(mPort);

	if (::bind(mSocket, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		printf("bind is failed!:%d", ::WSAGetLastError());
		return false;
	}

	linger Linger;
	Linger.l_onoff = 1;
	Linger.l_linger = 0;
	setsockopt(mSocket, SOL_SOCKET, SO_LINGER, (char*)&Linger, sizeof(Linger));

	if (::listen(mSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		printf("listen is failed!:%d", ::WSAGetLastError());
		return false;
	}

	return true;
}

void NetworkHost::OnDisconnect()
{
	if (mNetworkEvent == nullptr)
	{
		return;
	}

	mNetworkEvent->OnDisconnect(mHostID, mIP, mPort);

	mNetworkEvent = nullptr;
}

void NetworkHost::OnConnect(EHostType type)
{
	// Nagle 은 이 곳에서 설정하는게 아니다! Listen 에 설정하도록!

	// 이벤트 호출
	if (nullptr != mEvent)
	{
		// Timeout 설정
		int64_t tick = TimeUtil::GetTick64();
		mTimeoutTick = tick + mEvent->GetTimeoutTick();
		mAliveTick = tick + NETWORK_ALIVE_TICK;

		if (EHostType::ACCEPTOR == type)
		{
			mEvent->OnAccept(mHostID, mIP, mPort);
		}
		else if (EHostType::CONNECTOR == type)
		{
			mEvent->OnConnect(mHostID, mIP, mPort);
		}
	}

	mType = type;
}

void NetworkHost::StartNetworkTask()
{
	::InterlockedIncrement(&mNetworkTaskCount);
}

void NetworkHost::FinishNetworkTask(bool validSocket)
{
	::InterlockedDecrement(&mNetworkTaskCount);

	if (validSocket == true)
	{
		return;
	}

	Disconnect();
}

bool NetworkHost::_Accept(IOContext& context)
{
	if (mSocket == INVALID_SOCKET)
	{
		return false;
	}

	// 소켓 생성
	SOCKET sock = ::WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, nullptr, 0, WSA_FLAG_OVERLAPPED);
	if (sock == INVALID_SOCKET)
	{
		return false;
	}

	// Connect
	context.IncreaseReferenceCount();
	context.Ready(EContextType::ACCEPT);
	context.Write(&sock, sizeof(sock));

	// accept 요청
	DWORD bytes = 0;
	if (::AcceptEx(mSocket, sock, context.GetStart(), 0, sizeof(SOCKADDR_IN) + 16, sizeof(SOCKADDR_IN) + 16, &bytes, &context) == FALSE)
	{
		int error = ::WSAGetLastError();
		if (error != WSA_IO_PENDING)
		{
			printf("failed - AcceptEx:%d\n", error);
			closesocket(sock);
			context.DecreaseReferenceCount();
			return false;
		}
	}

	return true;
}

void NetworkHost::_UpdateListener(int64_t tick)
{
	int acceptCount = ACCEPT_WAIT_COUNT - mNetworkTaskCount;
	if (acceptCount <= 0)
	{
		return;
	}

	for (int i = 0; i < acceptCount; i++)
	{
		IOContext* context = new IOContext;
		if (context == nullptr)
		{
			printf("failed - context\n");
			continue;
		}

		StartNetworkTask();

		if (false == _Accept(*context))
		{
			// Accept 가 실패하더라도 ListenSocket 은 listen 상태 유지.
			FinishNetworkTask(true);
		}

		delete context;
	}
}

void NetworkHost::_UpdateAcceptor(int64_t tick)
{

}

void NetworkHost::_UpdateConnector(int64_t tick)
{

}