#pragma once

template<typename T>
class Singleton
{
public:
	static void CreateInstance()
	{
		m_instance = new T();
	}

	static T* GetInstance()
	{
		return m_instance;
	}

	static void DeleteInstance()
	{
		if (m_instance != nullptr)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	static void SetInstance(T* instance)
	{
		m_instance = instance;
	}

protected:
	static T*	m_instance;
};

template<typename T>
T* Singleton<T>::m_instance = nullptr;