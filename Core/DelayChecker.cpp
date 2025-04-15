#include "DelayChecker.h"
#include "TimeUtil.h"

void DelayChecker::SetDelayTick(int64_t delayTick)
{
	mMinTime = TimeUtil::GetTick64() + delayTick;
	mActivated.store(false);// �ð��� ���� �ϸ� �ٽ� üũ�� �ؾ� �ϹǷ� Ȱ��üũ ����
}

void DelayChecker::Check()
{
	// ȣ���ϸ� ���
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

	// �ּ� �����ð� ����
	if (mMinTime < TimeUtil::GetTick64())
	{
		return false;	// Time Over
	}

	return true;
}
