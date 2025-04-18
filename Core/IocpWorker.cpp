#include "IocpWorker.h"
#include <iostream>
#include <process.h>
#include "IOContext.h"

bool IocpWorker::CreateThread()
{
	auto iocp = ::CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);
	if (iocp == nullptr || iocp == INVALID_HANDLE_VALUE)
	{
		printf("failed - CreateIoCompletionPort:%d", ::GetLastError());
		return false;
	}
	mIocp = iocp;

	SYSTEM_INFO info;
	GetSystemInfo(&info);
	for (unsigned int n = 0; n < info.dwNumberOfProcessors; ++n)
	{
		auto handle = (HANDLE)_beginthreadex(nullptr, 0, _ExecuteThread, this, 0, nullptr);
		if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
		{
			return false;
		}

		mHandles.push_back(handle);
	}

	return true;
}

bool IocpWorker::RegisterSocket(NetworkHost* host)
{
	if (host == nullptr)
	{
		printf("RegisterSocket host is null!\n");
		return false;
	}

	SOCKET& sock = host->mSocket;
	if (sock == INVALID_SOCKET)
	{
		printf("Host is invalid socket!\n");
		return false;
	}

	if (::CreateIoCompletionPort(reinterpret_cast<HANDLE>(sock), mIocp,
		reinterpret_cast<ULONG_PTR>(host), 0) == nullptr)
	{
		printf("CreateIOCompletionPort is failed!");
		return false;
	}

	return true;
}

unsigned int __stdcall IocpWorker::_ExecuteThread(void* arg)
{
	auto& worker = *static_cast<IocpWorker*>(arg);
	worker._ProcessThread();
	return 0;
}

void IocpWorker::_ProcessThread()
{
	//스레드 작업 실행
	while (true)
	{
		//이벤트 대기
		bool result = true;
		DWORD transferred = 0;
		ULONG_PTR key = 0;
		LPOVERLAPPED overlapped = 0;

		DWORD dwLastError = 0;
		if (GetQueuedCompletionStatus(mIocp, &transferred, &key, &overlapped, INFINITE) == TRUE)
		{
			//스레드 종료 이벤트 체크
			if (key == 0
				&& transferred == 0
				&& overlapped == 0)
				break;
		}
		else
		{
			dwLastError = GetLastError();
			if (dwLastError != ERROR_NETNAME_DELETED)
			{
				printf("Result Failed (Code : %d [%x])\n", dwLastError, dwLastError);
				result = false;
			}
		}

		NetworkHost* host = reinterpret_cast<NetworkHost*>(key);
		IOContext* context = reinterpret_cast<IOContext*>(overlapped);
		if (host == nullptr || context == nullptr)
		{
			printf("failed - parameters\n");
			continue;
		}

		switch (context->GetType())
		{
		case EContextType::CONNECT:
			_ProcessConnect(*host, *context, result); 
			break;
		case EContextType::ACCEPT:	
			_ProcessAccept(*host, *context, result); 
			break;
		case EContextType::RECEIVE:
			_ProcessReceive(*host, *context, result, (int)transferred); 
			break;
		case EContextType::SEND:
			_ProcessSend(*host, *context, result, (int)transferred); 
			break;
		default:
			printf("failed - GetType:%d\n", context->GetType());
			break;
		}

		delete context;
	}
}

void IocpWorker::_ProcessConnect(NetworkHost& host, IOContext& context, bool result)
{
	if (result == false)
	{
		host.FinishNetworkTask(false);
		return;
	}

	host.OnConnect(EHostType::CONNECTOR);
}

void IocpWorker::_ProcessAccept(NetworkHost& host, IOContext& context, bool result)
{
}

void IocpWorker::_ProcessReceive(NetworkHost& host, IOContext& context, bool result, int transferred)
{
}

void IocpWorker::_ProcessSend(NetworkHost& host, IOContext& context, bool result, int transferred)
{
}
