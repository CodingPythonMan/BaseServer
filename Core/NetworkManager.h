#pragma once
#include "RefSingleton.h"
#include <string>
#include <atomic>

class NetworkEvent;
class IOContext;
class NetworkHost;
class NetworkHandler;
class IocpWorker;

class NetworkManager : public RefSingleton<NetworkManager>
{
public:
	NetworkManager() = default;
	virtual ~NetworkManager() = default;

	bool		Connect(NetworkEvent* networkEvent, std::string ip, int port, int& hostID);
	bool		Listen(NetworkEvent* networkEvent, std::string ip, int port);

	bool		IsInitialized() const;

	void		StartThread();

	bool		RegisterSocket(NetworkHost* host);

private:
	bool		_HandleContext(IOContext* context, NetworkHost* host);

private:
	std::atomic_bool	mIsInitialized = false;

	NetworkHandler*		mNetworkHandler = nullptr;
	IocpWorker*			mIocpWorker = nullptr;
};