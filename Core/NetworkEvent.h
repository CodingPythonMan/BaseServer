#pragma once
#include <string>

class NetworkEvent
{
private:
	const int DEFAULT_TIME_MS = 60000;

public:
	NetworkEvent() = default;
	virtual ~NetworkEvent() = default;

	virtual void	OnReceive(int hostID, int messageID, char* message, int messageSize) = 0;
	virtual void	OnConnect(int hostID, std::string& ip, int port) = 0;
	virtual void	OnAccept(int hostID, std::string& ip, int port) = 0;
	virtual void	OnDisconnect(int hostID, std::string& ip, int port) = 0;

	void			SetTimeoutTick(int tick);
	int				GetTimeoutTick();

private:
	int				mTimeoutTick = DEFAULT_TIME_MS;
};