#pragma once
#include "SharedObject.h"

class InternalData
{
public:
	InternalData() = default;
	virtual ~InternalData()
	{
		Release();
	}

	virtual void Release() {};
};

class InternalPacket : public SharedObject<InternalPacket>
{
public:
	int mHostID = 0;
	int mMsgID = 0;

	std::unique_ptr<InternalData> mData;

	int mWorkerID = 0;
	int mServerID = 0;

	void Reset()
	{
		mData = nullptr;

		mHostID = 0;
		mMsgID = 0;
		mWorkerID = 0;
		mServerID = 0;
	}
};