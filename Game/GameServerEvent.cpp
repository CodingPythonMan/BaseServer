#include "GameServerEvent.h"

void GameServerEvent::OnReceive(int hostID, int messageID, char* message, int messageSize)
{
}

void GameServerEvent::OnConnect(int hostID, std::string& ip, int port)
{
}

void GameServerEvent::OnAccept(int hostID, std::string& ip, int port)
{
}

void GameServerEvent::OnDisconnect(int hostID, std::string& ip, int port)
{
}