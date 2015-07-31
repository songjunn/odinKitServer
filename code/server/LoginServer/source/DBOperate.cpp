#include "DBOperate.h"
#include "LoginServer.h"

GuestID g_LoadGuestFactID(int worldID)
{
    mongo::Query query;
	mongo::auto_ptr<mongo::DBClientCursor> cursor;
	GETMONGODB(&LoginServer)->select(cursor, "guest", query.sort(BSON("guestid" << -1)));

	if( cursor.get() && cursor->more() )
	{
		GuestID uid = INVALID_VALUE;
		GETMONGODB(&LoginServer)->getBsonFieldI64(cursor->next(), "guestid", uid);
		return uid;
	}
	else
	{
		return g_MakeInitGuestID(worldID);
	}
}

bool g_GetGuestByDevice(const char* device, GuestID& gid)
{
    mongo::auto_ptr<mongo::DBClientCursor> cursor;
	GETMONGODB(&LoginServer)->select(cursor, "guest", QUERY("device" << device));

	if( cursor.get() && cursor->more() )
	{
		return GETMONGODB(&LoginServer)->getBsonFieldI64(cursor->next(), "guestid", gid);
	}
	return false;
}

bool g_SaveGuest(const char* device, GuestID gid)
{
    mongo::Query query;
	mongo::BSONObjBuilder obj;
	obj.append("guestid", gid);
	obj.append("device", device);
	GETMONGODB(&LoginServer)->execute(CMongoDB::Mongo_Insert, "guest", query, obj.obj());

	return true;
}
