#pragma once
#include "RefSingleton.h"

class Environment : public RefSingleton<Environment>
{
private:
	int		mMaxConnectionCount = 0;

public:
	int		mServerID = 0;

public:
	bool	SetMaxConnection(const int count);
};