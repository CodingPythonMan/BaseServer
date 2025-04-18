#pragma once
#include "NetworkEvent.h"

class LogConnectEvent : public NetworkEvent
{
public:
	LogConnectEvent() = default;
	virtual ~LogConnectEvent() = default;

public:
	virtual void OnReceive(int hostID, int messageID, char* message, int messageSize) override;
	virtual void OnConnect(int hostID, std::string& ip, int port) override;
	virtual void OnAccept(int hostID, std::string& ip, int port) override;
	virtual void OnDisconnect(int hostID, std::string& ip, int port) override;
};