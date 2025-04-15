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

	bool IsAvailable() const;	// ��� �����ص� �Ǵ� ��������?

private:
	std::atomic_bool mActivated = false;	// Ȱ��ȭ ����

	int64_t mMinTime = 0;
};

