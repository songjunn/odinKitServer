#include "DBOperate.h"
#include "MainServer.h"
#include "mongo_interface.h"

GuestID g_LoadGuestFactID(int worldID)
{
    mongo::Query query;
	mongo::auto_ptr<mongo::DBClientCursor> cursor;
	MainServer.GetMongoDBClient()->Select(cursor, "guest", query.sort(BSON("guestid"<<-1)));

	if( cursor.get() && cursor->more() )
	{
	    return MainServer.GetMongoDBClient()->GetFieldI64(cursor->next(), "guestid");
	}
	else
	{
		return g_MakeInitGuestID(worldID);
	}
}

bool g_GetGuestByDevice(const char* device, GuestID& gid)
{
    mongo::auto_ptr<mongo::DBClientCursor> cursor;
	MainServer.GetMongoDBClient()->Select(cursor, "guest", QUERY("device"<<device));

	if( cursor.get() && cursor->more() )
	{
	    gid = MainServer.GetMongoDBClient()->GetFieldI64(cursor->next(), "guestid");
		return true;
	}
	return false;
}

bool g_SaveGuest(const char* device, GuestID gid)
{
    mongo::Query query;
	mongo::BSONObjBuilder obj;
	obj.append("guestid", gid);
	obj.append("device", device);
	MainServer.GetMongoDBClient()->Execute(Opr_Insert, "guest", query, obj.obj());

	return true;
}
