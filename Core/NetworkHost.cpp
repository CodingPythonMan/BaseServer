#include "NetworkHost.h"
#include "NetworkEvent.h"
#include "IOContext.h"
#include <MSWSock.h>

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

void NetworkHost::Disconnect()
{
	if (mNetworkEvent == nullptr)
	{
		return;
	}

	mNetworkEvent->OnDisconnect(mHostID, mIP, mPort);

	mNetworkEvent = nullptr;
}

bool NetworkHost::_Accept(IOContext& context)
{
	if (mSocket == INVALID_SOCKET)
	{
		return false;
	}

	// 家南 积己
	SOCKET sock = ::WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, nullptr, 0, WSA_FLAG_OVERLAPPED);
	if (sock == INVALID_SOCKET)
	{
		return false;
	}

	// Connect
	context.IncreaseReferenceCount();
	context.Ready(EContextType::ACCEPT);
	context.Write(&sock, sizeof(sock));

	// accept 夸没
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

		::InterlockedIncrement(&mNetworkTaskCount);

		if (false == _Accept(*context))
		{

		}
	}
}

void NetworkHost::_UpdateAcceptor(int64_t tick)
{

}

void NetworkHost::_UpdateConnector(int64_t tick)
{

}