#include "DelayChecker.h"
#include "TimeUtil.h"

void DelayChecker::SetDelayTick(int64_t delayTick)
{
	mMinTime = TimeUtil::GetTick64() + delayTick;
	mActivated.store(false);// 시간을 세팅 하면 다시 체크를 해야 하므로 활성체크 오프
}

void DelayChecker::Check()
{
	// 호출하면 통과
	mActivated.store(true);
}

bool DelayChecker::IsActivated() const
{
	return mActivated.load();
}

bool DelayChecker::IsAvailable() const
{
	if (true == mActivated.load())
		return true;

	// 최소 유지시간 적용
	if (mMinTime < TimeUtil::GetTick64())
	{
		return false;	// Time Over
	}

	return true;
}
