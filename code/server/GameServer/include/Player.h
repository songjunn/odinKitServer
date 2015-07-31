#pragma once
#include "shared.h"
#include "Fighter.h"
#include "GameServer.h"
#include "EventUnit.h"

//class CFriendsUnit;
class CProp;
class CPlayer : public CFighter
{
public:
	CPlayer() {}
	virtual ~CPlayer() {}

	void	Init();
	void	Release();

	bool	OnMsg(PACKET_COMMAND* pack);

	virtual void	Copy(const CPlayer& player);

	inline	void	OnEvent(CEvent* ev)	{m_EventUnit.OnEvent(ev);}

	inline	void	SetGateSocket(SOCKET socket)		{m_GateSocket = socket;}
	inline	SOCKET	GetGateSocket()						{return m_GateSocket;}

	inline  void	SendClientMsg(PACKET_COMMAND* pack)	{ if (pack) { pack->SetTrans(GetID()); GETSERVERNET(&GameServer)->sendMsg(m_GateSocket, pack); _SendFormat(pack); } }
	inline	void	SendDataMsg(PACKET_COMMAND* pack){ if (pack) { pack->SetTrans(GetID()); GETSERVERNET(&GameServer)->sendMsg(GameServer.getServerSock(CBaseServer::Linker_Server_Data), pack); } _SendFormat(pack); }
	inline	void	SendObserveMsg(PACKET_COMMAND* pack, CPlayer* player) { if (pack && player) { pack->SetTrans(player->GetID()); GETSERVERNET(&GameServer)->sendMsg(player->m_GateSocket, pack); } _SendFormat(pack); }

	void _SendFormat(PACKET_COMMAND *pack){Log.Debug("%s", pack->toFormat());}
	inline CPlayer* GetPlayer() {return this;}

	bool	OnCreate(int templateid);

	void	DataInit();
	void	DataSync();

	void	SyncAttribute(bool client = true, CPlayer* toPlayer = NULL);
	void 	SyncTask();

	void	GainAp(int value);
	bool	GainGold(int nGold, GOLD_REASON reason);
	bool	GainSilver(int nSilver, SILVER_REASON reason);

	bool	OnRecharge(int yuan, GOLD_REASON reason);

	int		GoldCoin();
	int		SilverCoin();

	inline void	SetOnline(int flag) {m_OnlineFlag = (m_OnlineFlag == Online_Flag_On ? m_OnlineFlag : flag);}
	inline int	GetOnline()	{return m_OnlineFlag;}

	inline void	SetLoadTime(TMV time) {m_LoadTime = time;}
	inline TMV	GetLoadTime() {return m_LoadTime;}

	void	SyncFieldToData(const char* field = NULL);
	void	SyncFieldIntToClient(int i, CPlayer* toPlayer = NULL);
	void	SyncFieldI64ToClient(int i, CPlayer* toPlayer = NULL);

protected:
	int*	_FindFieldInt(int i);
	int64*	_FindFieldI64(int i);

	void	_SetXmlFieldInt(int i, int value);
	void	_SetXmlFieldI64(int i, int64 value);

	int		_GetXmlFieldInt(int i);
	int64	_GetXmlFieldI64(int i);
public:
	CEventUnit			m_EventUnit;

private:
	SOCKET		m_GateSocket;
	int			m_OnlineFlag;
	TMV			m_LoadTime;

	int64		m_Exp;
	int64		m_ExpMax;
	int			m_GoldCoin;
	int			m_SilverCoin;
	int			m_ThirdCoin;
	int			m_Stamina;
	int			m_StaminaMax;
	int			m_Merit;
	int			m_Credit;
	UserID		m_UserID;
	TMV			m_LoginTime;
	TMV			m_LogoutTime;
	int			m_VipLevel;
	int64		m_RechargeSum;

	TMV			m_ChatPrivateTime;
	TMV			m_ChatWorldTime;
	TMV			m_ChatCampTime;
	TMV			m_ChatKnightsTime;
	int			m_KnightState;
	int64		m_StateExp;

	//国战属性
	int			m_BattleCamp;				//阵营
	int			m_BattleWpID;				//路点
	int			m_BattleActions;			//剩余战斗次数
	int			m_BattleBuyActions;			//购买战斗次数
	TMV			m_BattleActionTime;			//上次战斗时间
	int			m_BattleActionCDTime;		//战斗冷却时间
	int			m_BattleRewardDialy;		//每日结算奖励
	int			m_BattleRewardDialyWp;		//每日结算奖励占领路点数

	//祭神属性
	int			m_WorshipCount;
	int			m_FreeCount;
	int 		m_StateGreen;
	int 		m_StateBlue;
	int 		m_StatePurple;
	int 		m_StateOrange;

	int			m_MaxBagCapacity;			//当前背包最大容量 wenc 

	//加成属性
	int			m_ExpAddition;
	int			m_MeritAddition;
	int			m_SilverAddition;
	int			m_StateExpAddition;

	int			m_BossInspire;				//世界boss鼓舞等级

	//充值活动
	int			m_SingleDoStateA;			//单次充值活动A达成状态
	int			m_SingleGetStateA;			//单次充值活动A领取状态
	int			m_SingleDoStateB;			//单次充值活动B达成状态
	int			m_SingleGetStateB;			//单次充值活动B领取状态
	int			m_MultiDoState;				//累积充值活动达成状态
	int			m_MultiGetState;			//累积充值活动领取状态
	TMV			m_FirstChargeTime;			//首次充值时间

	//vip相关
	int			m_ExtBagPage;				//额外扩充背包页数
	int			m_BuyStamina;				//每日购买行动力次数
	int			m_BossInspireFree;			//世界boss免费鼓舞次数
	int			m_AdvancedTrain;			//每日高级训练免费次数
	int			m_SignInFree;				//每日免费补签次数
	int			m_SkillResetFree;			//每日免费洗特性次数

	//斗酒
	int64		m_LastTimePot;				//最近一次免费斗酒时间
	int64		m_LeftTimeLen;				//距下一次免费斗酒时长(不存盘)
	int			m_RandHeroCount;			//斗酒次数

	//女王调教
	int64		m_LastTeaseTime;			//最近一次免费调教时间
	int64		m_LeftTeaseLen;				//距下一次免费调教时长(不存盘)
	int			m_TeaseSilver;				//今日调教获得的银币
	int			m_TeaseCount;				//花费金币调教次数
	int			m_QueenMood;				//女王心情(不存盘)

	//屠戳秘境
	int			m_CarnageSceneTop;			//已通过的最高关卡
	int			m_CarnageAchieveMax;		//最高纪录
	int			m_CarnageResetCnt;			//重置次数
	int			m_CarnageChlgCnt;			//挑战次数
};
