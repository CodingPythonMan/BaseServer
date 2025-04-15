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
	int64_t tick = TimeUtil::GetTick64();
	int64_t startTick = 0;
	int64_t gapTick = 0;

	for (auto& data : mTickDataList)
	{
		if (data.mNextTick > tick)
		{
			continue;
		}

		startTick = TimeUtil::GetTick64();
		// 콜백 함수 실행
		data.mFunc();
		gapTick = TimeUtil::GetTick64() - startTick;

		
	}

	mUpdateTick = TimeUtil::GetTick64() + INTERVAL_TICK;
}
