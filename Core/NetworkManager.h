#pragma once
#include "RefSingleton.h"
#include <WS2tcpip.h>
#include <windows.h>
#include <string>

class NetworkEvent;

class NetworkManager : public RefSingleton<NetworkManager>
{
public:
	bool		Connect(NetworkEvent* networkEvent, std::string ip, int port, OUT int& hostID);

};