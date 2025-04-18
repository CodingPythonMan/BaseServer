#pragma once
#include <memory>

class NetworkEvent;

class Server
{
public:
	Server() = default;
	virtual ~Server() = default;

	bool		Start();

	void		BindEvent(std::shared_ptr<NetworkEvent> networkEvent);
	
private:
	std::shared_ptr<NetworkEvent>	mEvent;
};