#include "WorldConfig.h"
#include "CSVParser.h"
#include "LoginServer.h"


CWorldConfig::CWorldConfig()
{
}

CWorldConfig::~CWorldConfig()
{
}

bool CWorldConfig::LoadCSVData(const char* csvfile)
{
	CCSVParser file;
	if( !csvfile || !file.Load(csvfile) )
	{
		Log.Error("加载%s失败...", csvfile);
		return false;
	}

	int index = 0;
	int count = file.Line();

	if( !Initialize("WorldConfig", count) )
		return false;

	for(int i = 0;i<count; ++i, index=0)
	{
		int id = 0;
		file.GetAttribute(i, index++, id);

		CWorld* world = Create( id );
		if( !world )
			return false;

		world->worldID = id;
		file.GetAttribute(i, index++, world->serverID);
		file.GetAttribute(i, index++, world->ip, 32);
		file.GetAttribute(i, index++, world->port);
	}

	return true;
}

void CWorldConfig::ConnectAllWorld()
{
	int worldID = m_list.Head();
	while( CWorld* world = GetObj(worldID) )
	{
		worldID = m_list.Next(worldID);

		LoginServer.createLinker(CBaseServer::Linker_Server_Central, world->serverID, world->port, world->ip, NULL, NULL, world->worldID, true);
	}
}
