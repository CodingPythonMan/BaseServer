#include "NetworkJob.h"
#include "DefineConst.h"

NetworkJob::NetworkJob()
{
	m_type = EJobType::None;
	m_referenceCount = 0;
	m_writePos = 0;
	m_readPos = 0;
	m_bufferSize = 0;

	m_buffer = new char[NETWORK_BUFFER_SIZE];
}

NetworkJob::~NetworkJob()
{
	delete[] m_buffer;
}

char* NetworkJob::GetData()
{
	if (m_buffer == nullptr)
	{
		return nullptr;
	}

	if (m_writePos > m_bufferSize)
	{
		return nullptr;
	}

	return m_buffer + m_readPos;
}

int NetworkJob::GetDataSize()
{
	if (m_writePos <= 0 || m_writePos <= m_readPos)
	{
		return 0;
	}

	return m_writePos - m_readPos;
}

char* NetworkJob::GetEmpty()
{
	if (m_buffer == nullptr)
	{
		return nullptr;
	}

	Align();

	if (m_writePos > m_bufferSize)
	{
		return nullptr;
	}

	return m_buffer + m_writePos;
}

void NetworkJob::Ready(EJobType type)
{
	// OVERLAPPED 의 멤버 함수들
	Internal = 0;
	InternalHigh = 0;
	Offset = 0;
	OffsetHigh = 0;
	hEvent = 0;

	m_type = type;
}

void NetworkJob::Align()
{
	// 함수 뜻 그대로 0을 readPos 로 두고 그 기준으로 쓰기 위한 정렬
	if (m_readPos <= 0)
	{
		return;
	}

	if (m_readPos < m_writePos)
	{
		memmove(m_buffer, m_buffer + m_readPos, m_writePos - m_readPos);
		m_writePos -= m_readPos;
	}
	else
	{
		m_writePos = 0;
	}
	m_readPos = 0;
}

bool NetworkJob::Write(void* src, int srcSize)
{
	// session 주소를 주로 버퍼에 쓰는 편이다.
	if (src == nullptr || srcSize <= 0)
	{
		return false;
	}

	if (srcSize > m_bufferSize)
	{
		return false;
	}

	memcpy_s(GetEmpty(), m_bufferSize - m_writePos, static_cast<char*>(src), srcSize);
	m_writePos += srcSize;

	return false;
}

bool NetworkJob::Read(void* dest, int destSize)
{
	char* src = GetData();
	int srcSize = GetDataSize();

	if (src == nullptr || srcSize < destSize)
	{
		return false;
	}

	memcpy_s((char*)dest, destSize, src, destSize);
	m_readPos += destSize;

	return true;
}

void NetworkJob::ResetBuffer()
{
	m_writePos = 0;
	m_readPos = 0;
}