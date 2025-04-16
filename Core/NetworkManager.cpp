#include "NetworkManager.h"
#include "NetworkHost.h"
#include "IOContext.h"
#include "NetworkHandler.h"

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


bool NetworkManager::IsInitialized() const
{
	return mIsInitialized.load();
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