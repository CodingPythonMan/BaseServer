#pragma once
#include "ObjectPool.h"

template<typename T>
class SharedObject : public std::enable_shared_from_this<T>
{
protected:
	friend ObjectPool<T>;

public:
	SharedObject() = default;
	virtual ~SharedObject() = default;
	
	virtual void	Reset() = 0;

	static void		ReservePool(size_t size)
	{
		return ObjectPool<T>::GetInstance().Reserve(size);
	}
};