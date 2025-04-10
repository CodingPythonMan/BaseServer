#include "PacketPayload.h"

void PacketPayload::SetMessageID(int msgID)
{
	// msgID를 빅 엔디안으로 변환
	mBody.mMsgID = htonl(msgID);
}

void PacketPayload::SetMessageLength(size_t msgLen)
{
	mHeader.mBodyLen = htonl(static_cast<UINT32>(sizeof(mBody.mMsgID)));
}

int PacketPayload::GetMessageID() const
{
	return ntohl(mBody.mMsgID);
}

size_t PacketPayload::GetMessageLength() const
{
	size_t bodyLen = GetBodyLength();
	return bodyLen - sizeof(mBody.mMsgID);
}

size_t PacketPayload::GetMaxMessageLength() const
{
	return sizeof(this->mBody.mMsgBytes);
}

size_t PacketPayload::GetBodyLength() const
{
	return ntohl(mHeader.mBodyLen);
}

size_t PacketPayload::GetPayloadLength() const
{
	return sizeof(mHeader) + GetBodyLength();
}

const UINT8* PacketPayload::GetMessageBytes() const
{
	return mBody.mMsgBytes;
}

UINT8* PacketPayload::GetMessageBytes()
{
	return reinterpret_cast<UINT8*>(&mBody.mMsgBytes);
}

UINT8* PacketPayload::GetBody()
{
	return reinterpret_cast<UINT8*>(&mBody);
}