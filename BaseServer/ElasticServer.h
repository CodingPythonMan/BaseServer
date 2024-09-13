#pragma once
class ElasticServer
{
public:
	ElasticServer();
	virtual ~ElasticServer();

public:
	bool Initialize();
	bool Run();
};