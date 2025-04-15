#include "NetworkHost.h"

void NetworkHost::SetEvent(NetworkEvent* networkEvent)
{
	mNetworkEvent = networkEvent;
}

void NetworkHost::SetIP(std::string ip)
{
	mIP = ip;
}

void NetworkHost::SetPortNum(int port)
{
	mPort = port;
}

int NetworkHost::GetHostID()
{
	return mHostID;
}