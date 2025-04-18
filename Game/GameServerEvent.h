#pragma once
#include "NetworkEvent.h"

class GameServerEvent : public NetworkEvent
{
public:
	GameServerEvent() = default;
	virtual ~GameServerEvent() = default;

	void	OnReceive(int hostID, int messageID, char* message, int messageSize);
	void	OnConnect(int hostID, std::string& ip, int port);
	void	OnAccept(int hostID, std::string& ip, int port);
	void	OnDisconnect(int hostID, std::string& ip, int port);
};