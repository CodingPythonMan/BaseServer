#pragma once

#include <mutex>

// ## �� �ٿ��ִ� ������ �������� �پ�ȭ�ϱ� ���ؼ� �ٿ��ִ� ���̴�.
#define LockGuard(x) std::lock_guard<std::mutex> __LOCK_GUARD__##x(x)