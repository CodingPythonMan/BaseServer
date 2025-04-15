#include "GameConnectEvent.h"

void GameConnectEvent::OnReceive(int hostID, int messageID, char* message, int messageSize)
{
}

void GameConnectEvent::OnConnect(int hostID, std::string& ip, int port)
{
	printf("[HostID : %d] Log Connect %s, %d\n", hostID, ip.c_str(), port);
}

void GameConnectEvent::OnAccept(int hostID, std::string& ip, int port)
{
}

void GameConnectEvent::OnDisconnect(int hostID, std::string& ip, int port)
{
	printf("[HostID : %d] Log Disconnect %s, %d\n", hostID, ip.c_str(), port);
}