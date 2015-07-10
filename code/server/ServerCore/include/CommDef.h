#ifndef SERVERCORE_COMMDEF_H
#define SERVERCORE_COMMDEF_H


enum ServerType
{
	Svr_Central = 1,	//中央服务器
	Svr_Data,			//数据服务器
	Svr_World,			//世界服务器
	Svr_Login,			//登陆服务器
	Svr_Game,			//逻辑服务器
	Svr_GateWay,		//网关服务器
	Svr_DataAnalysis,	//数据分析服务器
	Svr_Payment,

};

#endif	//SERVERCORE_COMMDEF_H
