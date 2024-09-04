#pragma once
#include <Windows.h>
#include <unordered_map>
#include "DefineType.h"
#include "Session.h"
#include "NetworkJob.h"
#include "LockQueue.h"

class NetworkService
{
public:
	NetworkService();
	virtual ~NetworkService();

	bool						CreateThread();

private:
	void						RunThread();
	void						SetTerminate();

	Session*					FindSession(const SessionID& sessionID);


	static unsigned int WINAPI	ExecuteThread(void* arg);

private:
	void						OnConnect(NetworkJob& job);

private:
	HANDLE					m_handle;
	volatile bool			m_isTerminate;

	std::unordered_map<SessionID, Session*>		m_sessionMap;
	std::unordered_map<SessionID, bool>			m_isPacketRecvMap;

	LockQueue<NetworkJob>						m_networkJobQueue;
};