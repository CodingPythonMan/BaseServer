#pragma once
#include <string>

class NetworkEvent
{
public:
	NetworkEvent();
	virtual ~NetworkEvent();

public:
	virtual void OnReceive(int hostId, int messageID, char* message, int messageSize) = 0;
	virtual void OnConnect(int hostid, std::string& ip, int port) = 0;
	virtual void OnAccept(int hostid, std::string& ip, int port) = 0;
	virtual void OnClose(int hostid, std::string& ip, int port) = 0;
};