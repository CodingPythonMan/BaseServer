#pragma once
#include <WS2tcpip.h>
#include <windows.h>

class NetworkHost;

enum class EContextType
{
	NONE = 0,
	CONNECT,
};

class IOContext	: public OVERLAPPED
{
public:
	void			Ready(EContextType type);
	bool			Write(void* src, int srcSize);

private:
	EContextType	mType;
};