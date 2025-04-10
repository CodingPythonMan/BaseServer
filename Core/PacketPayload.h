#pragma once
#include <WS2tcpip.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

// 구조체 패딩 제거
#pragma pack(push, 1)

struct PacketPayload
{
	struct Header
	{
		INT32 mBodyLen; // sizeof(msgID) + 유효 msgBytes
	};

	struct Body
	{
		INT32	mMsgID;
		UINT8	mMsgBytes[1024 * 8];
	};

	Header	mHeader;
	Body	mBody;

	void SetMessageID(int msgID);
	void SetMessageLength(size_t msgLen);

	int GetMessageID() const;

	size_t GetMessageLength() const;
	size_t GetMaxMessageLength() const;

	size_t GetBodyLength() const;
	size_t GetPayloadLength() const;

	const UINT8* GetMessageBytes() const;

	UINT8* GetMessageBytes();
	UINT8* GetBody();
};

#pragma pack(pop)