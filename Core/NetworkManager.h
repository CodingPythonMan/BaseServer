#pragma once
#include "RefSingleton.h"
#include <string>
#include <atomic>

class NetworkEvent;
class IOContext;
class NetworkHost;
class NetworkHandler;

class NetworkManager : public RefSingleton<NetworkManager>
{
public:
	NetworkManager() = default;
	virtual ~NetworkManager() = default;

	bool		Connect(NetworkEvent* networkEvent, std::string ip, int port, int& hostID);

	bool		IsInitialized() const;

private:
	bool		_HandleContext(IOContext* context, NetworkHost* host);

private:
	std::atomic_bool	mIsInitialized = false;

	NetworkHandler*		mNetworkHandler;
};