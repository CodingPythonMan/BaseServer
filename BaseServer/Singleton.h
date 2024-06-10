#pragma once

template<typename T>
class Singleton
{
public:
	static void CreateInstance()
	{
		_instance = new T();
	}

	static T* GetInstance()
	{
		return _instance;
	}

	static void DeleteInstance()
	{
		if (_instance != nullptr)
		{
			delete _instance;
			_instance = nullptr;
		}
	}

	static void SetInstance(T* instance)
	{
		_instance = instance;
	}

protected:
	static T* _instance;
};