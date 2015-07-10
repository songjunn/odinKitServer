#ifndef COMMON_PACKETDEFINE_H
#define COMMON_PACKETDEFINE_H

//消息编号命名格式
//流向前缀_功能前缀_功能描述
//流向前缀：
//CentralServer:C
//DataServer:D
//GameServer:G
//GateServer:A
//LoginServer:L
//Servers:S
//Payment: T
//Client:P
//功能前缀：
//请求：REQUEST
//应答：RESPONSE
//通知：NOTIFY

enum PakcetDefineType
{
	//server发起的消息
	SERVER_MESSAGE_BEGIN = 0,

	S2C_REQUEST_REGISTER_SERVER = 1,//注册服务器：服务器ID，类型，端口，ip
	C2S_NOTIFY_SYNC_SERVER,			//通知服务器去连接其它服务器：服务器ID，类型，端口，ip
	A2L_NOTIFY_GATE_INIT,			//GateServer同步初始化信息
	A2L_NOTIFY_SYNC_GATELOAD,		//GateServer同步负载情况：在线人数
	S2P_NOTIFY_SYNC_ERROR,			//发送错误码
	D2G_NOTIFY_WORLD_DATA,			//同步道游戏世界初始数据
	N2S_NOTIFY_CONTROL_ACCEPT,		// net -> server :create socket
	N2S_NOTIFY_CONTROL_CLOSE,		// net -> server :close socket
	P2A_RESPONSE_USER_HEART,		//心跳包响应
	D2G_REQUEST_WORLD_DATA,			//请求道游戏世界初始数据
	D2G_RESPONSE_WORLD_DATA,		//同步道游戏世界初始数据
	L2P_NOTIFY_SW_CHECKER,			//返回顺网信息

	//登陆消息
	L2A_REQUEST_USER_PRLOGIN = 100,	//账号预登陆：账号ID，登陆session密钥
	A2D_REQUEST_USER_LOGIN,			//账号登陆：账号ID，账号名
	A2G_NOTIFY_PLAYER_LOGOUT,		//角色登出GameServer：角色ID
	D2G_REQUEST_LOGIN_GAMEWORLD,	//角色登陆GameServer：角色ID，场景ID，坐标
	D2G_NOTIFY_PLAYER_ATTRINT,		//同步角色属性int
	D2G_NOTIFY_PLAYER_ATTRI64,		//同步角色属性int64
	D2G_NOTIFY_PLAYER_LOADOVER,		//角色数据加载完毕：角色ID
	G2D_REQUEST_PLAYER_DATA,		//向数据中心请求加载角色数据
	L2P_NOTIFY_CONNECT_GATESVR,		//通知客户端连接网关：账号ID，session，ip，端口
	D2P_NOTIFY_PLAYER_COUNT,		//同步角色数量：账号ID，角色数量
	G2P_NOTIFY_PLAYER_ATTRIBUTE,	//同步角色属性
	D2G_NOTIFY_PLAYER_NAME,			//同步角色名字
	G2D_REQUEST_CHECK_NAME,			//检查重名
	G2D_RESPONSE_CHECK_NAME,		//检查重名反馈
	D2G_RESPONSE_PLAYER_DATA,		//加载离线角色数据响应
	G2A_NOTIFY_USER_DISPLACE,		//顶号
	G2D_REQUEST_GAMEOBJ_DATA,		//向数据中心请求加载obj数据

	//任务
	G2P_NOTIFY_TASK_ADDK = 200,		// 任务模块：通知客户端增加一个任务
	G2P_RESPONSE_TASK_FINISH,		// 任务模块：完成任务应答
	G2P_RESPONSE_TASK_RESET,		// 任务模块：重置任务应答
	G2P_NOTIFY_TASK_LIST,
	D2G_NOTIFY_TASK_SYNC,			// sync to dataserver
	G2D_NOTIFY_TASK_ADD,			// add task 
	G2D_NOTIFY_TASK_DEL,			// to db del task
	G2D_NOTIFY_TASK_UPDATE,			// update task
	G2D_NOTIFY_FINISH_ADD,			// add finish
	G2D_NOTIFY_UNRECEIVE_ADD,		// add unreceive
	G2D_NOTIFY_UNRECEIVE_DEL,		// del unreceive
	G2P_NOTIFY_TASK_DEL,			// to client del task

	//战斗
	G2P_NOTIFY_COBBAT_START = 300,	// 战斗模块：同步战斗开始信息
	G2P_NOTIFY_COMBAT_REPORT,		// 战斗模块：同步战报信息
	G2P_NOTIFY_COMBAT_RESULT,		// 战斗模块：同步战斗结果
	G2P_NOTIFY_COMBAT_AWARD,		// 战斗模块：同步战斗奖励
	G2P_NOTIFY_FIGHT_AWARD,			// 战斗模块：同步绝杀模式战斗奖励
	G2P_NOTIFY_WIPE_AWARD,			// 战斗模块：同步扫荡奖励

	//道具
	G2P_NOTIFY_ITEM_GAIN = 400,		// 道具模块：同步获得道具
	G2P_NOTIFY_ITEM_DELETE,			// 道具模块：同步销毁道具
	G2P_NOTIFY_ITEM_ATTRINT,		// 道具模块：同步道具属性
	G2P_NOTIFY_ITEM_ATTRI64,		// 道具模块：同步道具属性
	G2P_RESPONSE_ITEM_EQUIP,		// 道具模块：穿装响应
	G2P_RESPONSE_ITEM_UNEQUIP,		// 道具模块：卸装响应
	G2P_RESPONSE_ITEM_INTENSIFY_FLAG, 	//装备强化响应标识
	G2P_RESPONSE_ITEM_INLAYCRYSTAL_FLAG, 		//镶嵌魂晶响应
	G2P_RESPONSE_ITEM_INLAYJADE_FLAG, 			//镶嵌魂玉响应
	G2P_RESPONSE_ITEM_SLOTTING_FLAG, 			//打孔响应	
	G2P_RESPONSE_ITEM_UPGRADE_FLAG,				//装备升级响应标识		//镶嵌魂晶响应
    G2P_RESPONSE_ITEM_INLAYJADEALLRESPONSE, 	//一键强化应答
	
	G2P_RESPONSE_ITEM_INTENSIFYJADE_FLAG,		//强化 魂玉 响应 标识
	G2P_RESPONSE_ITEM_INTENSIFYCRYSTAL_FLAG,	//强化 魂晶 响应 标识
	G2P_RESPONSE_ITEM_RECASTCRYSTAL_FLAG,		//重铸魂晶响应 标识	

	G2P_RESPONSE_ITEM_COMMONRESPONSE,  //通用响应，装备
	G2P_RESPONSE_SOUL_COMMONRESPONSE,  //通用响应，魂石
	
	G2P_RESPONSE_LOAD_ITEMS,  //加载 商店 道具  响应

	G2P_RESPONSE_NET_TEST	= 500,	// net test

	//副本
	D2P_NOTIFY_CITY_INFO = 600,		// 副本模块：同步副本信息
	G2P_NOTIFY_CITY_HELPER,			// 副本模块：同步助阵信息
	G2P_NOTIFY_CITY_PARAMS,			// 副本模块：同步相关参数
	D2G_NOTIFY_ZONE_INFO,			// 副本模块：同步区域信息

	//英雄
	D2P_NOTIFY_HERO_GAIN = 700,		// 英雄模块：添加英雄
	D2P_NOTIFY_HERO_ATTRINT,		// 英雄模块：同步英雄信息
	D2P_NOTIFY_HERO_ATTRI64,		// 英雄模块：同步英雄信息
	D2P_RESPONSE_HERO_INHERIT,		// 英雄模块：继承结果

	//阵型
	D2P_NOTIFY_FORMAT_INFO = 800,	// 阵型模块：加载
	D2P_NOTIFY_FORMAT_DEBUT,		// 阵型模块：出阵信息
	G2P_RESPONSE_FORMAT_UP,			// 阵型模块：升级成功

	// for friend
	G2P_RESPONSE_FRIENDS_ADD	= 900,	// friends response: add friend
	G2P_RESPONSE_FRIENDS_DEL	= 901,	// friends response: del friend
	G2P_NOTIFY_FRIENDS_ADD		= 902,	// friends request: notify client friend
	G2P_NOTIFY_FRIENDS_STATE	= 903,	// friends notify: friend state(up|down)
	G2D_REQUEST_FRIENDS_DATA	= 904,	// friend request data 
	D2G_RESPONSE_FRIENDS_DATA	= 905,	// friend response data 
	G2P_RESPONSE_FRIENDS_LOAD	= 906,	// friend response load
	D2G_NOTIFY_FRIENDS_SYNC		= 907,	// friend sync data to client
	G2D_NOTIFY_FRIEND_ADD		= 908,	// friend add friend 
	G2D_NOTIFY_FRIEND_DEL		= 909,	// friend del friend 
	G2P_RESPONSE_FRIEND_SYNC	= 910,	// friend sync data to client
	G2P_NOTIFY_FRIENDS_ADD_REQUEST = 911, // friend add request
	G2D_NOTIFY_FRIENDS_ADD_REQUEST = 912, // friend add request
	G2D_NOTIFY_FRIENDS_DEL_REQUEST = 913, // friend del request

	// for chat 
	G2P_NOTIFY_CHAT_PRIVATE		= 1000,	// chat NOTIFY: private
	G2P_NOTIFY_CHAT_WORLD		= 1001,	// chat NOTIFY: world
	G2P_NOTIFY_CHAT_CAMP		= 1002,	// chat NOTIFY: camp
	G2P_NOTIFY_CHAT_KNIGHTS		= 1003,	// chat NOTIFY: Knights
	G2P_RESPONSE_CHAT_ERROR		= 1004,	// chat NOTIFY: Error 

	//train
	G2P_RESPONSE_TRAIN_DO = 1100,		//训练
	G2P_RESPONSE_TRAIN_SAVED,			//训练保存完毕

	//stars
	G2P_NOTIFY_STARS_INFO = 1200,		//星盘

	//skill
	G2P_NOTIFY_SKILL_SPECINFO = 1300,	//同步特性技能

	//reward
	G2P_NOTIFY_REWARD = 1400,			//奖励
	G2P_NOTIFY_DIRECT = 1401,			// direct reward

	// arena
	G2P_RESPONSE_ARENA_STAGE_DATA	 	= 1500,	// response arena stage data
	G2P_RESPONSE_ARENA_CHANGE_OPP 		= 1501,	// response change opponent
	//G2P_RESPONSE_ARENA_ORDER_DATA 	= 1502, 	// response arena order data
	G2P_RESPONSE_ARENA_ADD_CHALLENGE	 = 1503, // response add challenge times
	G2P_NOTIFY_ARENA_KNIGHT_APPEAR 		= 1504, //  notify appear a knight
	G2P_RESPONSE_ARENA_CHALLENGE  		= 1505, //  response challenge 
	G2D_REQUEST_ARENA_SAVE_DATA			= 1506, // save data
	D2G_NOTIFY_ARENA_SYNC_DATA			= 1507, // sync data
	G2D_REQUEST_ARENA_WAITING_ADD		= 1508, // add waiting player
	G2D_REQUEST_ARENA_WAITING_DEL		= 1509, // del waiting player
	G2D_REQUEST_ARENA_WAITING_DEL_ALL	= 1510, // del all waiting player
	G2D_REQUEST_ARENA_CURRENT_ADD		= 1511, // add current player
	G2D_REQUEST_ARENA_CURRENT_DEL		= 1512, // del current player
	G2D_REQUEST_ARENA_CURRENT_UPDATE	= 1513, // update current player
	G2D_REQUEST_ARENA_CURRENT_DEL_ALL	= 1514, // del all curent
	G2P_NOTIFY_ARENA_DATA				= 1515, // arena data 
	G2P_NOTIFY_ARENA_STAGE_REWARD 		= 1516, // arena stage reward 
	G2D_NOTIFY_ARENA_MODULE_REFRESH_CURRENT 	= 1517, // arena module notify refresh
	D2G_NOTIFY_ARENA_MODULE_SYNC_DATA			= 1518,	// arena module sync data
	G2P_RESPONSE_ARENA_CHALLENGE_KNIGHT = 1519, //  response challenge  knight
	G2P_NOTIFY_ARENA_REFRESH			= 1520, //  notify arena refresh 

	//签到
	D2G_NOTIFY_SIGNIN_ATTR = 1600,  //签到数据同步
	G2P_RESPOND_COMPSIGNIN,			// 补签			
	G2P_RESPOND_EXCHGSIGNIN,		// 签到界面兑换物品

	// 国战
	G2P_NOTIFY_BATTLE_WPINFO = 1700,	//同步国战路点信息
	G2D_NOTIFY_BATTLE_JOINER,			//同步参与者信息
	G2D_NOTIFY_BATTLE_WINNER,			//同步胜利者信息
	G2D_NOTIFY_BATTLE_INIT,				//初始化国战数据
	G2P_NOTIFY_BATTLE_SINGLEREWARD,		//同步单场奖励
	G2P_NOTIFY_BATTLE_DOUBLEWIN,		//同步连胜排行

	// 世界boss
	G2P_RESPONSE_BOSS_INSPIRE = 1800,	//世界boss：鼓舞
	G2P_RESPONSE_BOSS_COOLDOWN,			//世界boss：冷却
	G2P_NOTIFY_BOSS_INFO,				//世界boss：总战斗信息
	G2P_NOTIFY_ATTACK_INFO,				//世界boss：单人战斗信息
	G2P_NOTIFY_REWARD_KILL,				//世界boss：击杀奖励信息
	G2P_NOTIFY_REWARD_RANKING,			//世界boss：排名奖励信息

	// order
	G2D_REQUEST_ORDER_UPDATE_PLAYER = 1900, // update player data
	G2D_REQUEST_ORDER_INSERT_PLAYER	= 1901, // insert player
	G2D_REQUEST_ORDER_DELETE_PLAYER = 1902, // delete player
	G2D_REQUEST_ORDER_MOVE_FRONT	= 1903, // move player front
	G2D_REQUEST_ORDER_MOVE_BACK		= 1904, // move player back
	D2G_NOTIFY_ORDER_ARENA_PLAYER_DATA	= 1905,	// notify GameServer player data
	G2P_RESPONSE_ORDER_RANK		 = 1906, // order range
	G2P_RESPONSE_ORDER_DATA 	= 1907, 	// response order data

	// event
	G2B_NOTIFY_EVENT = 2000,			// 同步游戏事件

	// buff
	D2G_NOTIFY_BUFFER = 2100,			// 同步身上的buff

	// 连续登录活动
	G2P_RESPONSE_ACTIVITY_LOGIN = 2200,	// 反馈给客户端
	D2G_NOTIFY_ACTIVITY_LOGIN,			// 数据同步

	// 充值相关活动
	G2P_RESPONSE_ACTIVITY_CHARGE = 2300,// 返赠给玩家奖品

	//远征活动
	D2G_NOTIFY_EXPEDITION_HERO	= 2400, // 同步远征英雄数据
	D2G_NOTIFY_EXPEDITION_INFO,			// 远征活动相关数据
	G2P_RESPONSE_EXPEDITION_AWARD,		// 远征活动奖励
	G2P_RESPONSE_EXPEDITION_AUTOAWARD,	// 远征自动挑战奖励

	//斗酒
	G2P_RESPONSE_RANDHERO_GAINHERO = 2500,


	//Payment
	G2T_REQUEST_PAYMENT_VERIFY			= 2600, 
	T2G_RESPONSE_PAYMENT_VERIFY			= 2601, 
	G2P_RESPONSE_PAYMENT_VERIFY			= 2602, 
	G2D_REQUEST_PAYMENT_SAVE_TRANSACTION= 2603,
	D2G_RESPONSE_PAYMENT_SAVE_TRANSACTION= 2604,

	//女王调教
	G2P_RESPONSE_QUEENTEASE		= 2700,

	//每天充值
	G2P_NOTIFY_DAYCHARGE	= 2800,

	//顺网充值
	S2S_NOTIFY_SWCHARGE	= 2900,

	// set fields value
	G2D_GAMEOBJ_CREATE = 10000,
	G2D_GAMEOBJ_REMOVE,
	G2D_GAMEOBJ_OBJFIELD_SET,
	G2D_GAMEOBJ_MAPFIELD_SET,
	G2D_GAMEOBJ_MAPFIELD_ADD,
	G2D_GAMEOBJ_MAPFIELD_DEL,
	G2D_GAMEOBJ_SYNC,
	G2D_GAMEOBJ_SYNC_OBJFIELD,
	G2D_GAMEOBJ_SYNC_MAPFIELD,
	G2D_GAMEOBJ_SYNC_FINISH,


	SERVER_MESSAGE_END = 29999,

	//client发起的消息
	CLIENT_MESSAGE_BEGIN = 30000,

	//登陆
	P2L_REQUEST_USER_CHECK = 30001,	//账号验证：账号名，账号密码(md5加密)
	P2L_REQUEST_GUEST_CHECK,		//游客验证：设备ID
	P2A_REQUEST_USER_LOGIN,			//账号登陆：账号ID，session密钥
	P2A_REQUEST_USER_LOGOUT,		//账号登陆：null
	P2A_REQUEST_PLAYER_LOGIN,		//角色登陆
	P2D_REQUEST_PLAYER_CREATE,		//创建角色：账号ID，角色名
	P2D_REQUEST_PLAYER_DELETE,		//删除角色：角色ID
	P2A_REQUEST_USER_HEART,			//心跳包

	//任务
	P2G_REQUEST_TASK_FINISH = 30100,// 任务模块：完成任务请求
	P2G_REQUEST_TASK_RESET,			// 任务模块：重置任务请求

	//战斗
	P2G_REQUEST_ATTACK_MONSTER = 30200,	// 战斗模块：发起请求战斗
	P2G_REQUEST_CITY_PRIZE,				// 战斗模块：副本抽奖
	P2G_REQUEST_HELPER_INFO,			// 战斗模块：请求助阵信息
	P2G_REQUEST_HELPER_SELECT,			// 战斗模块：选择助阵者
	P2G_REQUEST_RESET_CHALGCOUNT,		// 战斗模块：重置挑战次数
	P2G_REQUEST_BUY_ACTION,				// 购买行动力
	P2G_REQUEST_CITY_GETBOX,			// 获得区域宝箱

	//道具
	P2G_REQUEST_ITEM_USE = 30300,	// 道具模块：使用道具请求
	P2G_REQUEST_ITEM_SELL,			// 道具模块：出售道具请求
	P2G_REQUEST_ITEM_EQUIP,			// 道具模块：穿装请求
	P2G_REQUEST_ITEM_UNEQUIP,		// 道具模块：卸装请求
	P2G_REQUEST_ITEM_INTENSIFY,     //装备强化请求
	P2G_REQUEST_ITEM_INLAYCRYSTAL,	//镶嵌魂晶请求
	P2G_REQUEST_ITEM_INLAYJADE,		//镶嵌魂玉请求
	G2P_RESPONSE_ITEM_INLAYJADEALL, 			//一键镶嵌请求
	P2G_REQUEST_ITEM_SLOTTING,		//打孔请求
	P2G_REQUEST_ITEM_UPGRADE,		//装备升级请求	
	P2G_REQUEST_ITEM_INTENSIFYJADE,		//装备强化 魂玉 请求	
	P2G_REQUEST_ITEM_INTENSIFYCRYSTAL, //装备强化 魂晶 请求	
	P2G_REQUEST_ITEM_RECASTCRYSTAL, 	//重铸魂晶 请求 
	P2G_REQUEST_ITEM_UNLOADAllSOUL,		//拆卸魂石请求
	P2G_REQUEST_ITEM_UNLOADSOUL,		//拆卸魂石请求
	P2G_REQUEST_ITEM_INTENSIFYMITHRIL,	//强化秘银
	P2G_REQUEST_ITEM_QUICKINTENSE,		//一键强化
	P2G_REQUEST_ITEM_QUICKINTENSEALL,		//一键强化该角色所有装备

	P2G_REQUEST_LOAD_ITEMS,  	//商店系统    加载道具请求
	P2G_REQUEST_BUY_ITEMS,		//商店系统    购买商品请求

	//英雄
	P2G_REUQEST_HERO_RECRUIT = 30400,	// 英雄模块：招募
	P2G_REUQEST_HERO_RECALL,			// 英雄模块：召回
	P2G_REUQEST_HERO_LEAVE,				// 英雄模块：离队
	P2G_REUQEST_HERO_QUALITY,			// 英雄模块：提品
	P2G_REUQEST_HERO_PROGRESS,			// 英雄模块：提品进度
	P2G_REUQEST_HERO_INHERIT,			// 英雄模块：继承
	P2G_REUQEST_HERO_RAND,				// 斗酒获得英雄

	//阵型
	P2G_REQUEST_FORMAT_LEVELUP = 30500,	// 阵型模块：升级
	P2G_REQUEST_FORMAT_DEBUT,			// 阵型模块：上阵

	// for friends
	P2G_REQUEST_FRIENDS_ADD			= 30600,	// friends request: add friend
	P2G_REQUEST_FRIENDS_DEL			= 30601,	// friends request: del friend
	P2G_REQUEST_FRIENDS_LOAD		= 30602,	// friend request load
	P2G_REQUEST_FRIENDS_DEL_REQUEST = 30603, // friend request: del request

	// for chat
	P2G_REQUEST_CHAT_PRIVATE	= 30700,	// chat request: private
	P2G_REQUEST_CHAT_WORLD		= 30701,	// chat request: world
	P2G_REQUEST_CHAT_CAMP		= 30702,	// chat request: camp
	P2G_REQUEST_CHAT_KNIGHTS	= 30703,	// chat request: Knights

	// train
	P2G_REQUEST_TRAIN_DO = 30800,		// 训练模块：训练
	P2G_REQUEST_TRAIN_SAVE,				// 训练模块：保存
	P2G_REQUEST_TRAIN_UNSAVE,			// 训练模块：取消

	// stars
	P2G_REQUEST_STARS_ACTIVE = 30900,	// 星盘模块：激活
	P2G_REQUEST_STARS_UPLEVEL,			// 星盘模块：升级
	P2G_REQUEST_STARS_INLAY,			// 星盘模块：镶嵌
	P2G_REQUEST_STARS_UNLAY,			// 星盘模块：拆下

	//skill
	P2G_REQUEST_SKILL_SELECT = 31000,	// 技能模块：选择绝技
	P2G_REQUEST_SKILL_RESET,			// 技能模块：重置特性

	//观察
	P2G_REQUEST_OBSERVE_PLAYER = 31100,	// 观察

	//reward
	P2G_REQUEST_REWARD_GET = 31200,		// 领取奖励

	// arena
	P2G_REQUEST_ARENA_STAGE_DATA = 31300,	// request arena stage data
	P2G_REQUEST_ARENA_CHANGE_OPP = 31301,	// request change opponent
	P2G_REQUEST_ARENA_CHALLENGE	 = 31302,	// request challenge 
	//P2G_REQUEST_ARENA_ORDER_DATA = 31303, 	// request arena order data
	P2G_REQUEST_ARENA_ADD_CHALLENGE = 31304, // request add challenge times
	P2G_REQUEST_ARENA_CHALLENGE_KNIGHT = 31305, // challenge knight 

	// 祭神
	P2G_REQUEST_WORSHIPING = 31400,		 	// 祭神
	// 签到
	P2G_REQUEST_DOSIGNIN,					// 签到
	// 扩充背包
	P2G_REQUEST_BAG_EXPAND,					// 扩充背包

	// 国战
	P2G_REQUEST_BATTLE_JOIN = 31500,	//请求参加国战
	P2G_REQUEST_BATTLE_MOVE,			//国战中请求移动
	P2G_REQUEST_BATTLE_ATTACK,			//国战中请求攻击
	P2G_REQUEST_BATTLE_DEFEND,			//国战中请求防御
	P2G_REQUEST_BATTLE_WPINFO,			//请求国战信息
	P2G_REQUEST_BATTLE_BUY_ACTION,		//请求购买战斗次数
	P2G_REQUEST_BATTLE_BUY_TIME,		//请求取消战斗冷却时间
	P2G_REQUEST_BATTLE_SINGLEREWARD_GET,//请求领取单场奖励
	P2G_REQUEST_BATTLE_SINGLEREWARD_DOUBLE,	//请求翻倍单场奖励
	P2G_REQUEST_BATTLE_DIALYREWARD_GET,	//请求领取每日结算奖励
	P2G_REQUEST_BATTLE_WINRANKING,		//请求连胜排行

	// order
	P2G_REQUEST_DATA_RANK		= 31600, 	// request range
	P2G_REQUEST_ORDER_DATA = 31601, 	// request order data

	// 世界boss
	P2G_REQUEST_BOSS_ATTACK = 31700,	//请求攻击boss
	P2G_REQUEST_BOSS_INSPIRE,			//请求鼓舞
	P2G_REQUEST_BOSS_COOLDOWN,			//请求清除冷却时间
	P2G_REQUEST_BOSS_JOIN,				//请求参加世界boss

	// 连续登录
	P2G_REQUEST_ACTIVITY_LOGIN = 31800, //连续登录活动请求

	// 充值相关活动
	P2G_REQUEST_ACTIVITY_CHARGE = 32900,//充值相关活动请求

	// 远征活动
	P2G_REQUEST_ACTIVITY_EXPEDITION = 33000,
	P2G_REQUEST_EXPEDITION_SWITCHPOS,
	
	// Payment
	P2G_REQUEST_PAYMENT_VERIFY		= 33100,

	// 女王调教
	P2G_REQUEST_QUEENTEASE		= 33200,

	// 屠戳秘境
	P2G_REQUEST_CARNAGE		= 33300,

	//每天充值
	P2G_REQUEST_DAYCHARGE	= 33400,

	// 调试
	P2G_REQUEST_DEBUG		= 60000,	// 调试消息
	P2G_REQUEST_NET_TEST	= 60001,	// net test

	
	CLIENT_MESSAGE_END,				//最大65535

};

#endif	//COMMON_PACKETDEFINE_H
