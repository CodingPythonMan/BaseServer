#pragma once
#include <cstdint>
#include <functional>

class TickRunner
{
public:
	struct sTickData
	{
		int			mIndex = 0;
		int64_t		mNextTick = 0;
		int64_t		mInternalTick = 0;
		std::function<void()>	mFunc{};
	};

	TickRunner() = default;
	virtual ~TickRunner();

	void					RegisterRunner(int intervalTick, std::function<void()> func);
	void					Update();

private:
	int64_t					mTickUpdate = 0;
	std::vector<sTickData>	mTickDataList;

	int						mCurrentIndex = 0;

};