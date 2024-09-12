#pragma once
#include "Session.h"

enum class EJobType
{
	None = 0,
	Connect = 1,
	Listen = 2,
	Join = 3,
	Waiting = 4,
	Close = 5,
	Accept = 6,
	Receive = 7,
	Send = 8,
	Encrypt = 9,
};

// 직렬화 버퍼
class NetworkJob : public OVERLAPPED
{
public:
	NetworkJob();
	virtual ~NetworkJob();

	EJobType			GetType() { return m_type; }

	char*				GetData();
	int					GetDataSize();

	bool				Read(void* dest, int destSize);

private:
	EJobType			m_type;

	// 참조 계수. BroadCast 할 때, 다른 유저에게도 뿌려할 수 있으므로 넣는다.
	volatile long		m_referenceCount;

	char*				m_buffer;

	int					m_writePos;
	int					m_readPos;

	int					m_bufferSize;
};