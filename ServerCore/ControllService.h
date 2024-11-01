#pragma once
#include <unordered_map>
#include "DefineType.h"
#include "NetworkJob.h"
#include "LockQueue.h"

class ControllService
{
public:
	ControllService();
	virtual ~ControllService();

	bool						CreateThread();

private:
	void						RunThread();
	void						SetTerminate();

	Session*					FindSession(const SessionID& sessionID);
	bool						AddSession(Session* session);

	static unsigned int WINAPI	ExecuteThread(void* arg);

private:
	void						OnConnect(NetworkJob& job);

private:
	HANDLE					m_handle;
	volatile bool			m_isTerminate;

	std::unordered_map<SessionID, Session*>		m_sessionMap;
	std::unordered_map<SessionID, bool>			m_isPacketRecvMap;

	LockQueue<NetworkJob>						m_networkJobQueue;

	std::mutex									m_sessionIDLock;

	// 다른 서버는 따로 관리해야 한다.

};