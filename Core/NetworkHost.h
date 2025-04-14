#pragma once
#include <string>

class NetworkEvent;

class NetworkHost
{
public:
	void			SetEvent(NetworkEvent* networkEvent);
	void			SetIP(std::string ip);
	void			SetPort(int port);
	int				GetHostID();

private:
	NetworkEvent*	mNetworkEvent;
	std::string		mIP;
	int				mPort;

	int				mHostID;
};

