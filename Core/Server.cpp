#include "Server.h"
#include "NetworkManager.h"
#include "NetworkEvent.h"
#include "ConfigParser.h"

bool Server::Start()
{
	NetworkManager::GetInstance().StartThread();
	const auto& mainInfo = ConfigParser::GetInstance().GetServerInfo();

	if (nullptr == mEvent)
	{
		printf("Event is not registered! \n");
		return false;
	}
	
	const auto& name = mainInfo.Name;
	const auto& address = mainInfo.BindAddress;
	const auto& port = mainInfo.BindPort;

	printf("server:%s host:%s port:%d\n", name.c_str(), address.c_str(), port);
	if (NetworkManager::GetInstance().Listen(mEvent.get(), address, port) == false)
	{
		return false;
	}

	return true;
}

void Server::BindEvent(std::shared_ptr<NetworkEvent> networkEvent)
{
	mEvent = networkEvent;
}