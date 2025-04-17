#include "NetworkManager.h"
#include "NetworkHost.h"
#include "IOContext.h"
#include "NetworkHandler.h"
#include "IocpWorker.h"

bool NetworkManager::Connect(NetworkEvent* networkEvent, std::string ip, int port, int& hostID)
{
	NetworkHost* host = new NetworkHost;
	host->SetEvent(networkEvent);
	host->SetIP(ip);
	host->SetPortNum(port);

	IOContext* context = new IOContext();
	hostID = host->GetHostID();

	context->Ready(EContextType::CONNECT);
	context->Write(&host, sizeof(host));

	return _HandleContext(context, host);
}

bool NetworkManager::Listen(NetworkEvent* networkEvent, std::string ip, int port)
{
	NetworkHost* host = new NetworkHost;
	host->SetEvent(networkEvent);
	host->SetIP(ip);
	host->SetPortNum(port);

	IOContext* context = new IOContext;
	if (context == nullptr)
	{
		delete host;
		return false;
	}

	context->Ready(EContextType::LISTEN);
	context->Write(&host, sizeof(host));

	return _HandleContext(context, host);
}

bool NetworkManager::IsInitialized() const
{
	return mIsInitialized.load();
}

void NetworkManager::StartThread()
{
	if (mNetworkHandler == nullptr || mIocpWorker == nullptr)
	{
		printf("NetworkHandler, IocpWorker is null\n");
		return;
	}

	mNetworkHandler->CreateThread();
	mIocpWorker->CreateThread();

	mIsInitialized.store(true);
}

bool NetworkManager::_HandleContext(IOContext* context, NetworkHost* host)
{
	if (nullptr == context)
	{
		return false;
	}

	if (mNetworkHandler->PushThread(context) == false)
	{
		printf("Failed - PushThread\n");
		delete context;
		delete host;
		return false;
	}

	return true;
}