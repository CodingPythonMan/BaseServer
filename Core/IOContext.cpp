#include "IOContext.h"

IOContext::IOContext()
{
	mBuffer = new char[BUFFER_SIZE];
	mBufferSize = BUFFER_SIZE;
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

	::memcpy_s(GetStart(), mBufferSize - mWritePos, static_cast<char*>(src), srcSize);
	mWritePos += srcSize;

	return true;
}

bool IOContext::Read(void* dest, int destSize)
{
	if (dest == nullptr || destSize <= 0)
	{
		return false;
	}

	char* src = GetData();
	int srcSize = GetDataSize();

	if (src == nullptr || srcSize < destSize)
	{
		return false;
	}

	memcpy_s(static_cast<char*>(dest), destSize, src, destSize);
	mReadPos += destSize;

	return true;
}

void IOContext::ResetBuffer()
{
	mReadPos = 0;
	mWritePos = 0;
}

char* IOContext::GetData()
{
	if (mWritePos <= 0
		|| mWritePos <= mReadPos)
	{
		return nullptr;
	}

	if (nullptr == mBuffer)
	{
		return nullptr;
	}

	// WriteSize 쓰는게 더 크는 것도 말이 안된다.
	if (mWritePos > mBufferSize)
	{
		return nullptr;
	}

	return mBuffer + mReadPos;
}

int IOContext::GetDataSize()
{
	if (mWritePos <= 0 || mWritePos <= mReadPos)
	{
		return 0;
	}

	if (mWritePos > mBufferSize)
	{
		return 0;
	}

	return mWritePos - mReadPos;
}

void IOContext::Align()
{
	if (mReadPos <= 0)
	{
		return;
	}

	if (mReadPos < mWritePos)
	{
		memmove(mBuffer, mBuffer + mReadPos, mWritePos - mReadPos);
		mWritePos -= mReadPos;
	}
	else
	{
		mWritePos = 0;
	}

	mReadPos = 0;
}

char* IOContext::GetStart()
{
	if (nullptr == mBuffer)
	{
		return nullptr;
	}

	Align();

	if (mWritePos > mBufferSize)
	{
		return nullptr;
	}

	return mBuffer + mWritePos;
}

long IOContext::IncreaseReferenceCount()
{
	return InterlockedIncrement(&mReferenceCount);
}

long IOContext::DecreaseReferenceCount()
{
	return InterlockedDecrement(&mReferenceCount);
}

EContextType IOContext::GetType()
{
	return mType;
}
