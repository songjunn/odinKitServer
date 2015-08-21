#pragma once
#include "attrs.h"
#include "gamedef.h"


static CUtlMap<int, int>		 player_attr_type_table;
static CUtlMap<CUtlSymbol, int>	 player_attr_name_table;
static const attrs::CAttr player_attrs[] =
{
	{ Role_Attrib_Null,			"Null" },
	{ Role_Attrib_ID,			"playerid" },
	{ Role_Attrib_UserID,		"userid" },
	{ Role_Attrib_Name,			"name" },
	{ Role_Attrib_SceneID,		"sceneID" },
	{ Role_Attrib_Position,		"position" },
	{ Role_Attrib_TemplateID,	"templateID" },
	{ Role_Attrib_Vocation,		"vocation" },
	{ Role_Attrib_Sex,			"sex" },
	{ Role_Attrib_Level,		"level" },
	{ Role_Attrib_Exp,			"exp" },
	{ Role_Attrib_GoldCoin,		"goldcoin" },
	{ Role_Attrib_SilverCoin,	"silvercoin" },
	{ Role_Attrib_Fighting,		"fighting" },
	{ Role_Attrib_CreateTime,	"createtime" },
	{ Role_Attrib_LoginTime,	"logintime"},
	{ Role_Attrib_LogoutTime,	"logouttime" },
};