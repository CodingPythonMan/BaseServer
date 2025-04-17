#pragma once
#include <memory>

class NetworkEvent;

class Server
{
public:
	Server() = default;
	virtual ~Server() = default;

	bool		Start();
	
private:
	std::shared_ptr<NetworkEvent>	mEvent;
};