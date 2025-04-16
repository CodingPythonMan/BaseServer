#include "NetworkHandler.h"
#include "IOContext.h"
#include "TimeUtil.h"
#include "NetworkHost.h"

bool NetworkHandler::PushThread(IOContext* context)
{
	if (context == nullptr)
	{
		return false;
	}

	mContextQueue.Push(context);

	return true;
}

void NetworkHandler::UpdateHost()
{
	int64_t tick = TimeUtil::GetTick64();

	// IsAlive �� ��Ŷ�� �� �� �̳��� �ְ� �޾Ҵ��� üũ�ؾ� �Ѵ�.
	auto iter = mHostMap.begin();
	while (iter != mHostMap.end())
	{
		auto host = iter->second;
		if (nullptr != host)
		{
			if (true == host->IsAlive())
			{
				host->Update(tick);
				iter++;
				continue;
			}

			host->Disconnect();
			delete host;
		}

		_RemoveHost(iter->first);

		iter = mHostMap.erase(iter);
	}
}

void NetworkHandler::_RemoveHost(const int hostID)
{

}