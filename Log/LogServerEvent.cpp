#include "LogServerEvent.h"

void LogServerEvent::OnReceive(int hostID, int messageID, char* message, int messageSize)
{
}

void LogServerEvent::OnConnect(int hostID, std::string& ip, int port)
{
	printf("[HostID : %d] Log Connect %s, %d\n", hostID, ip.c_str(), port);
}

void LogServerEvent::OnAccept(int hostID, std::string& ip, int port)
{
}

void LogServerEvent::OnDisconnect(int hostID, std::string& ip, int port)
{
	printf("[HostID : %d] Log Disconnect %s, %d\n", hostID, ip.c_str(), port);
}