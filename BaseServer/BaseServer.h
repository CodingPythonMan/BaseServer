#pragma once
class BaseServer
{
public:
	BaseServer();
	virtual ~BaseServer();

public:
	bool Initialize();
	bool Run();
};