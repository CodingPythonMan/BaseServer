#pragma once
#include <WS2tcpip.h>
#include <windows.h>

#define BUFFER_SIZE 10000

class NetworkHost;

enum class EContextType
{
	NONE = 0,
	CONNECT,
	ACCEPT,
};

class IOContext	: public OVERLAPPED
{
public:
	IOContext();
	virtual ~IOContext();

	void			Ready(EContextType type);
	bool			Write(void* src, int srcSize);

	char*			GetData();
	void			Align();

	char*			GetStart();

	long			IncreaseReferenceCount();
	long			DecreaseReferenceCount();

private:
	EContextType	mType = EContextType::NONE;
	size_t			mBufferSize = 0;
	char*			mBuffer = nullptr;

	int				mReadSize = 0;
	int				mWriteSize = 0;

	volatile long	mReferenceCount = 0;
};