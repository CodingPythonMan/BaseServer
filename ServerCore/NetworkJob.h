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

// ����ȭ ����
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

	// ���� ���. BroadCast �� ��, �ٸ� �������Ե� �ѷ��� �� �����Ƿ� �ִ´�.
	volatile long		m_referenceCount;

	char*				m_buffer;

	int					m_writePos;
	int					m_readPos;

	int					m_bufferSize;
};