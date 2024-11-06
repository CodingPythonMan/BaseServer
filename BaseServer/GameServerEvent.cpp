#include "GameServerEvent.h"

GameServerEvent::GameServerEvent()
{
}

GameServerEvent::~GameServerEvent()
{
}

void GameServerEvent::OnReceive(int hostId, int messageID, char* message, int messageSize)
{
}

void GameServerEvent::OnConnect(int hostid, std::string& ip, int port)
{
}

void GameServerEvent::OnAccept(int hostid, std::string& ip, int port)
{
}

void GameServerEvent::OnClose(int hostid, std::string& ip, int port)
{
}