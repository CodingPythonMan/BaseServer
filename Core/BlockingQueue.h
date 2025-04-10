#pragma once
#include <mutex>
#include <deque>

template <typename T>
class BlockingQueue
{
private:
	std::recursive_mutex mLock;
	std::deque<T> mQueue;

public:
	void Clear()
	{
		std::lock_guard<std::recursive_mutex> guard(mLock);
		mQueue.clear();
	}

	size_t Getcount()
	{
		std::lock_guard<std::recursive_mutex> guard(mLock);
		return mQueue.size();
	}
	
	void Push(T object)
	{
		std::lock_guard<std::recursive_mutex> guard(mLock);
		mQueue.push_back(object);
	}

	T Pop()
	{
		T object = T();

		std::lock_guard<std::recursive_mutex> guard(mLock);
		if (false == mQueue.empty())
		{
			object = mQueue.front();
			mQueue.pop_front();
		}

		return object;
	}

	void Swap(std::deque<T>& outList)
	{
		std::lock_guard<std::recursive_mutex> guard(mLock);
		mQueue.swap(outList);
	}

	void Get(std::deque<T>& outList, const size_t& getSize)
	{
		outList.clear();

		std::lock_guard<std::recursive_mutex> guard(mLock);
		if (mQueue.size() <= getSize)
		{
			mQueue.swap(outList);
		}
		else
		{
			outList.assign(mQueue.begin(), mQueue.begin() + getSize);
			mQueue.erase(mQueue.begin(), mQueue.begin() + getSize);
		}
	}
};