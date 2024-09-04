#pragma once
#include <windows.h>

enum class EJobType
{
	NONE = 0,
	CONNECT = 1,
	LISTEN = 2,
	JOIN = 3,
	WAITING = 4,
	CLOSE = 5,
	ACCEPT = 6,
	RECEIVE = 7,
	SEND = 8,
	ENCRYPT = 9,
};

class NetworkJob : public OVERLAPPED
{
public:
	EJobType GetType() { return m_type; }

private:
	EJobType			m_type;
};

