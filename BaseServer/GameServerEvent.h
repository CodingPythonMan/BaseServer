#pragma once
#include "NetworkEvent.h"

class GameServerEvent : public NetworkEvent
{
public:
	GameServerEvent();
	virtual ~GameServerEvent();

public:
	void OnReceive(int hostId, int messageID, char* message, int messageSize) override;
	void OnConnect(int hostid, std::string& ip, int port) override;
	void OnAccept(int hostid, std::string& ip, int port) override;
	void OnClose(int hostid, std::string& ip, int port) override;
};