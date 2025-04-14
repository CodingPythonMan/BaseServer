#include "NetworkManager.h"
#include "NetworkHost.h"
#include "IOContext.h"

bool NetworkManager::Connect(NetworkEvent* networkEvent, std::string ip, int port, OUT int& hostID)
{
	NetworkHost* host = new NetworkHost;
	host->SetEvent(networkEvent);
	host->SetIP(ip);
	host->SetPort(port);

	IOContext* context = new IOContext();
	hostID = host->GetHostID();

	context->Ready(EContextType::CONNECT);
	context->Write(&host, sizeof(host));

	return true;
}