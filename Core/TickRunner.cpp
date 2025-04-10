#include "TickRunner.h"
#include "TimeUtil.h"

TickRunner::~TickRunner()
{
	mTickDataList.clear();
}

void TickRunner::RegisterRunner(int intervalTick, std::function<void()> func)
{
	mCurrentIndex++;

	sTickData data;
	data.mIndex = mCurrentIndex;
	data.mNextTick = TimeUtil::GetTick64() + intervalTick;
	data.mInternalTick = intervalTick;
	data.mFunc = func;

	mTickDataList.push_back(data);
}

void TickRunner::Update()
{

}
