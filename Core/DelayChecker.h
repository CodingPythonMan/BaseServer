#pragma once
#include <stdint.h>
#include <atomic>

class DelayChecker
{
public:
	DelayChecker() = default;
	~DelayChecker() = default;

	void SetDelayTick(int64_t delayTick);
	void Check();
	bool IsActivated() const;

	bool IsAvailable() const;	// 계속 실행해도 되는 상태인지?

private:
	std::atomic_bool mActivated = false;	// 활성화 여부

	int64_t mMinTime = 0;
};

