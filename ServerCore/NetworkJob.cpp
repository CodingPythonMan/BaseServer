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
