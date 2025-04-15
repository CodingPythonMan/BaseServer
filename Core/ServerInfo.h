#pragma once

struct ServerInfo
{
	std::string		Name;
	int				ServerID;
	std::string		BindAddress;
	int				BindPort;
	bool			Nagle;
	int				MaxConnection;
};

struct ConnectInfo
{
	std::string		Name;
	int				ServerID;
	std::string		Address;
	int				Port;
};