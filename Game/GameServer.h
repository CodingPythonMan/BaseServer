#pragma once
class GameServer
{
public:
	GameServer() = default;
	virtual ~GameServer();

	bool		Initialize();
	bool		Run();

	void		ShowPacket();
	void		ShowPool();
};