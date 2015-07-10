#pragma once
#include "Singleton.h"
#include "ObjMgr.h"

struct CWorld
{
	int worldID;
	int serverID;
	int	port;
	char ip[32];
};

class CWorldConfig : public CObjMgr< CWorld, int >, public Singleton< CWorldConfig >
{
public:
	CWorldConfig();
	~CWorldConfig();

	bool	LoadCSVData(const char* csvfile);
	void	ConnectAllWorld();

protected:
	
};

#define WorldConfig CWorldConfig::getSingleton()