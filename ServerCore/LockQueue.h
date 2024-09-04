#pragma once
#include <queue>
#include <mutex>

template<typename T>
class LockQueue
{
public:
	LockQueue() {}
	~LockQueue() { Clear(); }

	std::recursive_mutex m_lock;
	std::queue<T*> m_queue;

	size_t Size()
	{
		std::lock_guard<std::recursive_mutex> guard(m_lock);
		return m_queue.size();
	}

	void Clear()
	{
		T* data = nullptr;

		std::lock_guard<std::recursive_mutex> guard(m_lock);

		while (false == m_queue.empty())
		{
			data = m_queue.front();
			m_queue.pop();
			delete data;
		}
	}

	void Push(T* data)
	{
		if (data == nullptr)
		{
			return;
		}

		std::lock_guard<std::recursive_mutex> guard(m_lock);
		m_queue.push(data);
	}

	T* Pop()
	{
		T* data = nullptr;
		{
			std::lock_guard<std::recursive_mutex> guard(m_lock);

			if (false == m_queue.empty())
			{
				data = m_queue.front();
				m_queue.pop();
			}
		}

		return data;
	}

	T* Peek()
	{
		T* temp = nullptr;
		{
			std::lock_guard<std::recursive_mutex> guard(m_lock);
			if (m_queue.empty() == false)
			{
				temp = m_queue.front();
			}
		}

		return temp;
	}

	void GetList(std::vector<T*>& list)
	{
		std::lock_guard<std::recursive_mutex> guard(m_lock);

		while (false == m_queue.empty())
		{
			list.push_back(m_queue.front());
			m_queue.pop();
		}
	}
};