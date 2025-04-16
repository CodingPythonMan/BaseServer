#pragma once
#include <WS2tcpip.h>
#include <windows.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

#define ACCEPT_WAIT_COUNT 100

class NetworkEvent;
class IOContext;

enum class EHostType : int
{
	NONE = 0,
	LISTENER,
	ACCEPTOR,
	CONNECTOR,
};

class NetworkHost
{
public:
	void			SetEvent(NetworkEvent* networkEvent);
	void			SetIP(std::string ip);
	void			SetPortNum(int port);
	int				GetHostID();

	bool			IsAlive();
	void			Update(int64_t tick);

	void			Disconnect();

private:
	bool			_Accept(IOContext& context);
	void			_UpdateListener(int64_t tick);
	void			_UpdateAcceptor(int64_t tick);
	void			_UpdateConnector(int64_t tick);

private:
	NetworkEvent*	mNetworkEvent = nullptr;
	std::string		mIP;
	int				mPort = 0;

	int				mHostID = 0;

	volatile long	mNetworkTaskCount = 0;
	volatile long	mSendTaskCount = 0;
	SOCKET			mSocket = INVALID_SOCKET;

	EHostType		mType = EHostType::NONE;
};