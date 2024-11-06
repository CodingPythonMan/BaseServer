#pragma once
#include "DefineType.h"
#include <ws2tcpip.h>
#include <string>
#include "NetworkEvent.h"

#pragma comment(lib, "ws2_32.lib")

enum class ESocketClose : int
{
	Reset = 0,
	SocketTimeout = 1,
	TooManyPacket = 2,
	FailInit = 3,
	FailSend = 4,

	AddMapFail = 5,
	SocketCreateFail = 6,
	RegisterRecvFail = 7,
	ListenFail = 8,
	ProcessClose = 9,
};

class Session
{
public:
	Session();
	virtual ~Session();

	bool					m_isRecv;

public:
	inline SessionID		GetID() const { return m_sessionID; }
	inline void				SetEvent(NetworkEvent* networkEvent) { m_networkEvent = networkEvent; }
	inline void				SetIP(std::string ip) { m_ip = ip; }
	inline void				SetPort(int port) { m_port = port; }

	bool					Close(ESocketClose closeType);

private:
	SessionID				m_sessionID;
	SOCKET					m_socket;

	std::string				m_ip;
	int						m_port;
	NetworkEvent*			m_networkEvent;
};