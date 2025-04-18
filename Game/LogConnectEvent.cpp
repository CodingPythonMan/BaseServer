#include "LogConnectEvent.h"

void LogConnectEvent::OnReceive(int hostID, int messageID, char* message, int messageSize)
{
}

void LogConnectEvent::OnConnect(int hostID, std::string& ip, int port)
{
	printf("[HostID : %d] Log Connect %s, %d\n", hostID, ip.c_str(), port);
}

void LogConnectEvent::OnAccept(int hostID, std::string& ip, int port)
{
}

void LogConnectEvent::OnDisconnect(int hostID, std::string& ip, int port)
{
	printf("[HostID : %d] Log Disconnect %s, %d\n", hostID, ip.c_str(), port);
}