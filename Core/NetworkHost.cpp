#include "NetworkHost.h"

void NetworkHost::SetEvent(NetworkEvent* networkEvent)
{
	mNetworkEvent = networkEvent;
}

void NetworkHost::SetIP(std::string ip)
{
	mIP = ip;
}

void NetworkHost::SetPort(int port)
{
	mPort = port;
}

int NetworkHost::GetHostID()
{
	return mHostID;
}