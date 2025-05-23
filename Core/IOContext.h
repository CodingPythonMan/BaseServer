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
	RECEIVE,
	SEND,
	LISTEN,
	JOIN,
	DISCONNECT,
};

class IOContext	: public OVERLAPPED
{
public:
	IOContext();
	virtual ~IOContext();

	void			Ready(EContextType type);
	bool			Write(void* src, int srcSize);
	bool			Read(void* dest, int destSize);
	void			ResetBuffer();

	char*			GetData();
	int				GetDataSize();

	void			Align();

	char*			GetStart();

	long			IncreaseReferenceCount();
	long			DecreaseReferenceCount();

	EContextType	GetType();

private:
	EContextType	mType = EContextType::NONE;
	size_t			mBufferSize = 0;
	char*			mBuffer = nullptr;

	int				mReadPos = 0;
	int				mWritePos = 0;

	volatile long	mReferenceCount = 0;
};