#include "IOContext.h"

IOContext::IOContext()
{
	mBuffer = new char[BUFFER_SIZE];
}

IOContext::~IOContext()
{
	delete[] mBuffer;
}

void IOContext::Ready(EContextType type)
{
	Internal = 0;
	InternalHigh = 0;
	Offset = 0;
	OffsetHigh = 0;
	hEvent = 0;

	mType = type;
}

bool IOContext::Write(void* src, int srcSize)
{
	if (src == nullptr || srcSize <= 0)
	{
		return false;
	}

	if (srcSize > mBufferSize)
	{
		return false;
	}

	::memcpy_s(GetStart(), mBufferSize - mWriteSize, static_cast<char*>(src), srcSize);
	mWriteSize += srcSize;

	return true;
}

char* IOContext::GetData()
{
	if (mWriteSize <= 0
		|| mWriteSize <= mReadSize)
	{
		return nullptr;
	}

	if (nullptr == mBuffer)
	{
		return nullptr;
	}

	if (mWriteSize > mBufferSize)
		return nullptr;

	return mBuffer + mReadSize;
}

void IOContext::Align()
{
	if (mReadSize <= 0)
	{
		return;
	}

	if (mReadSize < mWriteSize)
	{
		memmove(mBuffer, mBuffer + mReadSize, mWriteSize - mReadSize);
		mWriteSize -= mReadSize;
	}
	else
	{
		mWriteSize = 0;
	}

	mReadSize = 0;
}

char* IOContext::GetStart()
{
	if (nullptr == mBuffer)
	{
		return nullptr;
	}

	Align();

	if (mWriteSize > mBufferSize)
	{
		return nullptr;
	}

	return mBuffer + mWriteSize;
}
