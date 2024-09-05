#pragma once

#include <mutex>

// ## 을 붙여주는 이유는 변수명을 다양화하기 위해서 붙여주는 것이다.
#define LockGuard(x) std::lock_guard<std::mutex> __LOCK_GUARD__##x(x)