#pragma once
#include "RefSingleton.h"
#include <string>

class NetworkEvent;

class NetworkManager : public RefSingleton<NetworkManager>
{
public:
	bool		Connect(NetworkEvent* networkEvent, std::string ip, int port, int& hostID);

};