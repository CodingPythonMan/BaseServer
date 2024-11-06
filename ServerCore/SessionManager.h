#pragma once
#include "Singleton.h"
#include "Session.h"

class NetworkJob;

class SessionManager : public Singleton<SessionManager>
{
public:
	SessionManager();
	virtual ~SessionManager();

private:


public:
	bool		ReadyForListen(NetworkEvent* networkEvent, const std::string& address, const int port);
	
private:
	bool		DispatchController(NetworkJob* job, Session* session = nullptr);

};

