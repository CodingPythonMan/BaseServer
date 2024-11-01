#pragma once
#include "Singleton.h"
#include <string>
#include "Session.h"

class SessionManager : public Singleton<SessionManager>
{
public:

	bool		ReadyForListen(const std::string& address, const int port);

};

