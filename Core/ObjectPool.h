#pragma once
#include <stack>
#include <mutex>
#include <memory>

template <typename T>
class ObjectPool
{
private:
	ObjectPool() = default;
	void Release(std::shared_ptr<T> obj)
	{
		std::lock_guard<std::recursive_mutex> guard(mLock);

		obj->Reset();
		mPool.push(std::move(obj));
	}

public:
	static ObjectPool<T>& GetInstance()
	{
		static ObjectPool<T> instance;

		return instance;
	}


	void Reserve(size_t size)
	{
		std::lock_guard<std::recursive_mutex> guard(mLock);

		for (size_t i = 0; i < size; i++)
		{
			mPool.push(std::make_shared<T>());
		}

		mAllocCount += size;
	}

	size_t GetAllocCount()
	{
		std::lock_guard<std::recursive_mutex> guard(mLock);
		return mAllocCount;
	}

	size_t GetUsingCount()
	{
		std::lock_guard<std::recursive_mutex> guard(mLock);
		return mAllocCount - mPool.size();
	}

	std::shared_ptr<T> Acquire()
	{
		std::lock_guard<std::recursive_mutex> guard(mLock);

		if (mPool.empty())
		{
			mPool.push(std::make_shared<T>());
			mAllocCount++;
		}

		std::shared_ptr ptr{
			mPool.top().release(),
			[this](T* obj) { this->Release(std::unique_ptr<T>(obj)); }
		};

		mPool.pop();
		return ptr;
	}

private:
	std::stack<std::shared_ptr<T>>		mPool;
	std::recursive_mutex				mLock;

	size_t								mAllocCount = 0;
};