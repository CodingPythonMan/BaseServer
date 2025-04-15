#pragma once
#include <string>
#include "DelayChecker.h"

enum class EServerConnectState
{
	Disconnect = 0,
	Connecting,
	Connected,
};

class ServerConnectInfo
{
public:
	int mServerID = 0;
	std::string mHostIP = "";
	int mHostPort = 0;

private:
	EServerConnectState mState = EServerConnectState::Disconnect;
	int mHostID = 0;

	DelayChecker mChecker;

public:
	ServerConnectInfo() = default;
	virtual ~ServerConnectInfo() = default;

	bool IsConnected() const;
	bool IsConnecting();

	void SetState(EServerConnectState state);

	void SetHostID(int id) { mHostID = id; }
	int GetHostID() const { return mHostID; }
};