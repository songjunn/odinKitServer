#include "Player.h"
#include "RoleTemplate.h"
#include "gtime.h"
#include "error.h"
#include "NoticeModule.h"
#include "DataModule.h"
#include "MessageTypeDefine.pb.h"
#include "MessagePlayer.pb.h"


void CPlayer::Release()
{
	DataModule.Delete(m_GameObj->getId());
	m_GameObj = NULL;

	CFighter::Release();
	m_EventUnit.Release();
}

void CPlayer::Init()
{
	CFighter::Init();

	m_type = Role_Type_Player;
	m_GateSocket = -1;
	m_GoldCoin = 0;
	m_SilverCoin= 0;
	m_ThirdCoin = 0;
	m_Exp = 0;
	m_ExpMax = 0;
	m_Stamina = 0;
	m_StaminaMax = 0;
	m_Merit = 0;
	m_ChatCampTime = 0;
	m_ChatPrivateTime = 0;
	m_ChatWorldTime = 0;
	m_ChatKnightsTime = 0;
	m_UserID = 0;
	m_OnlineFlag = Online_Flag_Null;
	m_LoadTime = 0;
	m_LoginTime = 0;
	m_LogoutTime = 0;
	m_KnightState = 1;
	m_StateExp = 0;
	m_WorshipCount = 0;
	m_FreeCount = 0;
	m_StateGreen = 1;
	m_StateBlue = 0;
	m_StatePurple = 0;
	m_StateOrange = 0;
	m_MaxBagCapacity = 0;
	m_VipLevel = 0;
	m_RechargeSum = 0;

	m_BattleCamp = INVALID_VALUE;		
	m_BattleWpID = INVALID_VALUE;		
	m_BattleActions = INVALID_VALUE;	
	m_BattleBuyActions = INVALID_VALUE;
	m_BattleActionTime = INVALID_VALUE;
	m_BattleActionCDTime = INVALID_VALUE;
	m_BattleRewardDialy = INVALID_VALUE;
	m_BattleRewardDialyWp = INVALID_VALUE;

	m_ExpAddition = 0;
	m_MeritAddition = 0;
	m_SilverAddition = 0;
	m_StateExpAddition = 0;

	m_SingleDoStateA = 0;
	m_SingleGetStateA = 0;
	m_SingleDoStateB = 0;
	m_SingleGetStateB = 0;
	m_MultiDoState = 0;
	m_MultiGetState = 0;
	m_FirstChargeTime = 0;

	m_ExtBagPage = 0;		
	m_BuyStamina = 0;		
	m_BossInspireFree = 0;		
	m_AdvancedTrain = 0;	
	m_SignInFree = 0;		
	m_SkillResetFree = 0;	

	m_BossInspire = 0;

	m_LastTimePot = 0;
	m_LeftTimeLen = 0;
	m_RandHeroCount = 0;

	m_LastTeaseTime = 0;
	m_LeftTeaseLen = 0;
	m_TeaseSilver = 0;
	m_TeaseCount = 0;
	m_QueenMood = 0;

	m_CarnageSceneTop = 1;
	m_CarnageAchieveMax = 0;
	m_CarnageResetCnt = 0;
	m_CarnageChlgCnt = 0;

	m_EventUnit.Initialize(this);
}

bool CPlayer::OnMsg(PACKET_COMMAND* pack)
{
	if( !pack )
		return false;

	return false;
}

void CPlayer::Copy(const CPlayer& player)
{
	CFighter::Copy(player);
}

bool CPlayer::OnCreate(int templateid)
{
	CRoleTemplate* temp = RoleTemplateMgr.GetObj( templateid );
	if( !temp )
	{
		Log.Error("[CPlayer] Invalid Player Template:%d", templateid);
		return false;
	}

	CMetadata* json = DataModule.GetObj( GetID() );
	if( json )
		m_GameObj = json;
	else
		m_GameObj = DataModule.createMetadata("player", GetID());

	SetTemplateID(templateid);
	SetFieldInt(Role_Attrib_TemplateID, templateid);
	SetFieldInt(Role_Attrib_Vocation, temp->m_Career);
	SetFieldInt(Role_Attrib_Sex, temp->m_Sex);
	SetFieldInt(Role_Attrib_BaseStrength, temp->m_Strength);
	SetFieldInt(Role_Attrib_BaseIntellect, temp->m_Intelli);
	SetFieldInt(Role_Attrib_BaseTechnique, temp->m_Technic);
	SetFieldInt(Role_Attrib_BaseAgility, temp->m_Agility);
	SetFieldInt(Role_Attrib_Hp, temp->m_Hp);
	SetFieldInt(Role_Attrib_BaseHpMax, temp->m_Hp);
	SetFieldInt(Role_Attrib_BasePhysiDamage, temp->m_PhysiDamage);
	SetFieldInt(Role_Attrib_BaseMagicDamage, temp->m_MagicDamage);
	SetFieldInt(Role_Attrib_BaseStuntDamage, temp->m_StuntDamage);
	SetFieldInt(Role_Attrib_BasePhysiDefense, temp->m_PhysiDefense);
	SetFieldInt(Role_Attrib_BaseMagicDefense, temp->m_MagicDefense);
	SetFieldInt(Role_Attrib_BaseStuntDefense, temp->m_StuntDefense);
	SetFieldInt(Role_Attrib_BaseHit, temp->m_Hit);
	SetFieldInt(Role_Attrib_BaseJouk, temp->m_Jouk);
	SetFieldInt(Role_Attrib_BaseCrit, temp->m_Crit);
	SetFieldInt(Role_Attrib_BaseTenacity, temp->m_Tenacity);
	SetFieldInt(Role_Attrib_BaseParry, temp->m_Parry);
	SetFieldInt(Role_Attrib_BaseTreat, temp->m_Treat);
	SetFieldInt(Role_Attrib_Counter, temp->m_Counter);
	SetFieldInt(Role_Attrib_MoraleRevert, temp->m_MoraleRevert);
	SetFieldInt(Role_Attrib_HpRevert, temp->m_HpRevert);
	SetFieldInt(Role_Attrib_AttackSkill, temp->m_AttackID);
	SetFieldInt(Role_Attrib_UseStuntSkill, temp->m_StuntID);
	SetFieldInt(Role_Attrib_UseFinalSkill, temp->m_FinalID);
	SetFieldInt(Role_Attrib_StarsID, temp->m_StarsID);
	SetFieldInt(Role_Attrib_Hotohori, temp->m_Hotohori);
	SetFieldInt(Role_Attrib_InitStuntID, temp->m_StuntID);

	SetFieldInt(Role_Attrib_MoraleAttack, temp->m_MoraleAttack);
	SetFieldInt(Role_Attrib_MoraleBeAttack, temp->m_MoraleBeAttack);
	SetFieldInt(Role_Attrib_MoraleRound, temp->m_MoraleRound);

	for(int i=0; i<Combat_Place_Destory; ++i)
	{
		m_Place[i] = temp->m_Place[i];
	}

	return true;
}

int* CPlayer::_FindFieldInt(int i)
{
	int* field = CFighter::_FindFieldInt(i);
	if( field )
		return field;

	switch(i)
	{
	case Role_Attrib_BattleCamp:		return &m_BattleCamp;
	case Role_Attrib_BattleWpID:		return &m_BattleWpID;
	case Role_Attrib_BattleActions:		return &m_BattleActions;
	case Role_Attrib_BattleBuyActions:	return &m_BattleBuyActions;
	case Role_Attrib_ExpAddition:		return &m_ExpAddition;
	case Role_Attrib_MeritAddition:		return &m_MeritAddition;
	case Role_Attrib_SilverAddition:	return &m_SilverAddition;
	case Role_Attrib_StateExpAddition:	return &m_StateExpAddition;
	case Role_Attrib_BossInspire:		return &m_BossInspire;
	case Role_Attrib_FreeCount:			return &m_FreeCount;
	case Role_Attrib_BattleActionCDTime:return &m_BattleActionCDTime;
	case Role_Attrib_BattleRewardDialy:	return &m_BattleRewardDialy;
	case Role_Attrib_BattleRewardDialyWp:return &m_BattleRewardDialyWp;
	case Role_Attrib_SingleDoStateA:	return &m_SingleDoStateA;
	case Role_Attrib_SingleGetStateA:	return &m_SingleGetStateA;
	case Role_Attrib_SingleDoStateB:	return &m_SingleDoStateB;
	case Role_Attrib_SingleGetStateB:	return &m_SingleGetStateB;
	case Role_Attrib_MultiDoState:		return &m_MultiDoState;
	case Role_Attrib_MultiGetState:		return &m_MultiGetState;

	case Role_Attrib_ExtBagPage:		return &m_ExtBagPage;
	case Role_Attrib_BuyStamina:		return &m_BuyStamina;
	case Role_Attrib_BossInspireFree:	return &m_BossInspireFree;
	case Role_Attrib_AdvancedTrain:		return &m_AdvancedTrain;
	case Role_Attrib_SignInFree:		return &m_SignInFree;
	case Role_Attrib_SkillResetFree:	return &m_SkillResetFree;
	case Role_Attrib_RandHeroCount:		return &m_RandHeroCount;
	case Role_Attrib_TeaseSilver:		return &m_TeaseSilver;
	case Role_Attrib_TeaseCount:		return &m_TeaseCount;
	case Role_Attrib_QueenMood:			return &m_QueenMood;
	case Role_Attrib_CarnageSceneTop:	return &m_CarnageSceneTop;
	case Role_Attrib_CarnageAchiveMax:	return &m_CarnageAchieveMax;
	case Role_Attrib_CarnageResetCnt:	return &m_CarnageResetCnt;
	case Role_Attrib_CarnageChlgCnt:	return &m_CarnageChlgCnt;

	default:	return NULL;
	}

	return NULL;
}

int64* CPlayer::_FindFieldI64(int i)
{
	int64* field = CFighter::_FindFieldI64(i);
	if( field )
		return field;

	switch(i)
	{
	case Role_Attrib_BattleActionTime:	return &m_BattleActionTime;
	case Role_Attrib_ChatCampTime:		return &m_ChatCampTime;
	case Role_Attrib_ChatPrivateTime:	return &m_ChatPrivateTime;
	case Role_Attrib_ChatWorldTime:		return &m_ChatWorldTime;
	case Role_Attrib_ChatKnightsTime:	return &m_ChatKnightsTime;
	case Role_Attrib_RechargeSum:		return &m_RechargeSum;
	case Role_Attrib_FirstChargeTime:	return &m_FirstChargeTime;
	case Role_Attrib_RandHeroLastTime:	return &m_LastTimePot;
	case Role_Attrib_RandHeroLeftTime:	return &m_LeftTimeLen;
	case Role_Attrib_LastTeaseTime:		return &m_LastTeaseTime;
	case Role_Attrib_LeftTeaseLen:		return &m_LeftTeaseLen;

	default:	return NULL;
	}

	return NULL;
}

void CPlayer::_SetXmlFieldInt(int i, int value)
{
	switch(i)
	{
	case Role_Attrib_TemplateID:		m_GameObj->setFieldInt("template", value);					break;
	case Role_Attrib_Quality:			m_GameObj->setFieldObjInt("attr", "quality", value);		break;
	case Role_Attrib_QualityProgress:	m_GameObj->setFieldObjInt("attr", "qualitypro", value);		break;
	case Role_Attrib_Level:				m_GameObj->setFieldObjInt("attr", "level", value);			break;
	case Role_Attrib_GoldCoin:			m_GameObj->setFieldObjInt("attr", "gold", value);			break;
	case Role_Attrib_SilverCoin:		m_GameObj->setFieldObjInt("attr", "silver", value);			break;
	case Role_Attrib_Credit:			m_GameObj->setFieldObjInt("attr", "credit", value);			break;
	case Role_Attrib_Stamina:			m_GameObj->setFieldObjInt("attr", "stamina", value);		break;
	case Role_Attrib_UseStuntSkill:		m_GameObj->setFieldObjInt("attr", "stunt", value);			break;
	case Role_Attrib_KnightState:		m_GameObj->setFieldObjInt("attr", "knight", value);			break;
	case Role_Attrib_Merit:				m_GameObj->setFieldObjInt("attr", "merit", value);			break;
	case Role_Attrib_BagMaxCapacity:	m_GameObj->setFieldObjInt("attr", "bagmax", value);			break;
	case Role_Attrib_Vip:				m_GameObj->setFieldObjInt("attr", "viplevel", value);		break;
	case Role_Attrib_TrainStrength:		m_GameObj->setFieldObjInt("train", "strength", value);		break;
	case Role_Attrib_TrainIntellect:	m_GameObj->setFieldObjInt("train", "intellect", value);		break;
	case Role_Attrib_TrainTechnique:	m_GameObj->setFieldObjInt("train", "technique", value);		break;
	case Role_Attrib_TrainAgility:		m_GameObj->setFieldObjInt("train", "agility", value);		break;
	case Role_Attrib_WorshipCount:		m_GameObj->setFieldObjInt("worship", "count", value);		break;
	case Role_Attrib_FreeCount:			m_GameObj->setFieldObjInt("worship", "free", value);		break;
	case Role_Attrib_StateGreen:		m_GameObj->setFieldObjInt("worship", "green", value);		break;
	case Role_Attrib_StateBlue:			m_GameObj->setFieldObjInt("worship", "blue", value);		break;
	case Role_Attrib_StatePurple:		m_GameObj->setFieldObjInt("worship", "purple", value);		break;
	case Role_Attrib_StateOrange:		m_GameObj->setFieldObjInt("worship", "orange", value);		break;
	default:	break;
	}
}

void CPlayer::_SetXmlFieldI64(int i, int64 value)
{
	switch(i)
	{
	case Role_Attrib_UserID:			m_GameObj->setFieldI64("userid", value);					break;
	case Role_Attrib_LoginTime:			m_GameObj->setFieldObjI64("login", "logintime", value);		break;
	case Role_Attrib_LogoutTime:		m_GameObj->setFieldObjI64("login", "logouttime", value);	break;
	case Role_Attrib_Exp:				m_GameObj->setFieldObjI64("attr", "exp", value);			break;
	case Role_Attrib_KnightStateExp:	m_GameObj->setFieldObjI64("attr", "knightexp", value);		break;
	default:	break;
	}
}

int CPlayer::_GetXmlFieldInt(int i)
{
	switch(i)
	{	
	case Role_Attrib_TemplateID:		return m_GameObj->getFieldInt("template");
	case Role_Attrib_Quality:			return m_GameObj->getFieldObjInt("attr", "quality");		
	case Role_Attrib_QualityProgress:	return m_GameObj->getFieldObjInt("attr", "qualitypro");	
	case Role_Attrib_Level:				return m_GameObj->getFieldObjInt("attr", "level");		
	case Role_Attrib_GoldCoin:			return m_GameObj->getFieldObjInt("attr", "gold");			
	case Role_Attrib_SilverCoin:		return m_GameObj->getFieldObjInt("attr", "silver");			
	case Role_Attrib_Credit:			return m_GameObj->getFieldObjInt("attr", "credit");			
	case Role_Attrib_Stamina:			return m_GameObj->getFieldObjInt("attr", "stamina");		
	case Role_Attrib_UseStuntSkill:		return m_GameObj->getFieldObjInt("attr", "stunt");
	case Role_Attrib_KnightState:		return m_GameObj->getFieldObjInt("attr", "knight");			
	case Role_Attrib_Merit:				return m_GameObj->getFieldObjInt("attr", "merit");			
	case Role_Attrib_BagMaxCapacity:	return m_GameObj->getFieldObjInt("attr", "bagmax");			
	case Role_Attrib_Vip:				return m_GameObj->getFieldObjInt("attr", "viplevel");
	case Role_Attrib_TrainStrength:		return m_GameObj->getFieldObjInt("train", "strength");		
	case Role_Attrib_TrainIntellect:	return m_GameObj->getFieldObjInt("train", "intellect");		
	case Role_Attrib_TrainTechnique:	return m_GameObj->getFieldObjInt("train", "technique");		
	case Role_Attrib_TrainAgility:		return m_GameObj->getFieldObjInt("train", "agility");		
	case Role_Attrib_WorshipCount:		return m_GameObj->getFieldObjInt("worship", "count");		
	case Role_Attrib_FreeCount:			return m_GameObj->getFieldObjInt("worship", "free");		
	case Role_Attrib_StateGreen:		return m_GameObj->getFieldObjInt("worship", "green");		
	case Role_Attrib_StateBlue:			return m_GameObj->getFieldObjInt("worship", "blue");		
	case Role_Attrib_StatePurple:		return m_GameObj->getFieldObjInt("worship", "purple");		
	case Role_Attrib_StateOrange:		return m_GameObj->getFieldObjInt("worship", "orange");		
	default:	break;
	}
	return INVALID_VALUE;
}

int64 CPlayer::_GetXmlFieldI64(int i)
{
	switch(i)
	{
	case Role_Attrib_UserID:			return m_GameObj->getFieldI64("userid");					
	case Role_Attrib_LoginTime:			return m_GameObj->getFieldObjI64("login", "logintime");	
	case Role_Attrib_LogoutTime:		return m_GameObj->getFieldObjI64("login", "logouttime");	
	case Role_Attrib_Exp:				return m_GameObj->getFieldObjI64("attr", "exp");			
	case Role_Attrib_KnightStateExp:	return m_GameObj->getFieldObjI64("attr", "knightexp");		
	default:	break;
	}
	return INVALID_VALUE;
}

void CPlayer::SyncFieldToData(const char* field)
{
	DataModule.syncField(m_GameObj, GameServer.getServerSock(CBaseServer::Linker_Server_Data), field);
}

void CPlayer::SyncFieldIntToClient(int i, CPlayer* toPlayer)
{
	Message::PlayerAttrSync msg;
	msg.set_pid(GetID());
	_PackageMsgAttr32(msg, i);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_PLAYER_LOAD_DATA);

	if( toPlayer )
		SendObserveMsg( &pack, toPlayer );
	else
		SendClientMsg( &pack );
}

void CPlayer::SyncFieldI64ToClient(int i, CPlayer* toPlayer)
{
	Message::PlayerAttrSync msg;
	msg.set_pid(GetID());
	_PackageMsgAttr64(msg, i);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_PLAYER_LOAD_DATA);

	if (toPlayer)
		SendObserveMsg(&pack, toPlayer);
	else
		SendClientMsg(&pack);
}

void CPlayer::_PackageMsgAttr32(Message::PlayerAttrSync& msg, int i)
{
	Message::PlayerAttrSync::Attr * attr = msg.add_attr();
	attr->set_key(i);
	attr->set_val32(GetFieldInt(i));
}

void CPlayer::_PackageMsgAttr64(Message::PlayerAttrSync& msg, int i)
{
	Message::PlayerAttrSync::Attr * attr = msg.add_attr();
	attr->set_key(i);
	attr->set_val64(GetFieldI64(i));
}

void CPlayer::SyncAttribute(bool client, CPlayer* toPlayer)
{
	Message::PlayerAttrSync msg;
	msg.set_pid(GetID());
	_PackageMsgAttr32(msg, Role_Attrib_TemplateID);
	_PackageMsgAttr32(msg, Role_Attrib_Level);
	_PackageMsgAttr32(msg, Role_Attrib_Hp);
	_PackageMsgAttr32(msg, Role_Attrib_GoldCoin);
	_PackageMsgAttr32(msg, Role_Attrib_SilverCoin);
	_PackageMsgAttr32(msg, Role_Attrib_Merit);
	_PackageMsgAttr32(msg, Role_Attrib_Fighting);
	_PackageMsgAttr32(msg, Role_Attrib_Stamina);
	_PackageMsgAttr32(msg, Role_Attrib_StaminaMax);
	_PackageMsgAttr32(msg, Role_Attrib_Strength);
	_PackageMsgAttr32(msg, Role_Attrib_Intellect);
	_PackageMsgAttr32(msg, Role_Attrib_Technique);
	_PackageMsgAttr32(msg, Role_Attrib_Agility);
	_PackageMsgAttr32(msg, Role_Attrib_Hit);
	_PackageMsgAttr32(msg, Role_Attrib_Jouk);
	_PackageMsgAttr32(msg, Role_Attrib_Crit);
	_PackageMsgAttr32(msg, Role_Attrib_Tenacity);
	_PackageMsgAttr32(msg, Role_Attrib_Parry);
	_PackageMsgAttr32(msg, Role_Attrib_Treat);
	_PackageMsgAttr32(msg, Role_Attrib_PhysiDamage);
	_PackageMsgAttr32(msg, Role_Attrib_PhysiDefense);
	_PackageMsgAttr32(msg, Role_Attrib_MagicDamage);
	_PackageMsgAttr32(msg, Role_Attrib_MagicDefense);
	_PackageMsgAttr32(msg, Role_Attrib_StuntDamage);
	_PackageMsgAttr32(msg, Role_Attrib_StuntDefense);
	_PackageMsgAttr32(msg, Role_Attrib_BaseStrength);
	_PackageMsgAttr32(msg, Role_Attrib_BaseIntellect);
	_PackageMsgAttr32(msg, Role_Attrib_BaseTechnique);
	_PackageMsgAttr32(msg, Role_Attrib_BaseAgility);
	_PackageMsgAttr64(msg, Role_Attrib_Exp);

	PACKET_COMMAND pack;
	PROTOBUF_CMD_PACKAGE(pack, msg, Message::MSG_PLAYER_LOAD_DATA);

	if( client )
		SendClientMsg( &pack );
	if( toPlayer )
		SendObserveMsg( &pack, toPlayer );
}

void CPlayer::DataInit()
{
	//数据加载完成后，进行一些必要的初始化计算
	this->InitBaseAttr();
}

void CPlayer::DataSync()
{
	//向前端同步登录信息
	this->SyncAttribute();
}

void CPlayer::GainAp(int value)
{
	this->ChangeFieldInt(Role_Attrib_Stamina, value, true);
	this->SyncFieldToData("attr");
}

bool CPlayer::GainGold(int nGold, GOLD_REASON reason)
{
	if(nGold == 0) {
		Log.Error("CPlayer::GainGold nGold=0, Reason: %d, Player:"INT64_FMT, reason, GetID());
		return false;
	}

	int nHaveGold = GoldCoin();
	if(nGold < 0 && (nHaveGold + nGold < 0)) { // 金币不足
		Log.Error("Lack GoldCoin. Have %d, need %d, Reason: %d, player:"INT64_FMT, nHaveGold, nGold, reason, GetID());
		return false;
	}

	ChangeFieldInt(Role_Attrib_GoldCoin, nGold, true);
	this->SyncFieldToData("attr");

	if(GoldCoin() < 0) { // 金币上溢
		Log.Error("Serious Error. GoldCoin Overflow CurGold: %d, Reason: %d, player:"INT64_FMT, GoldCoin(), reason, GetID());
	}

	// 日志统计
	CEvent *evLog = MakeEvent(Event_Gold_Trade, GetID(), GetFieldI64(Role_Attrib_UserID), nGold, reason, GetName(), true);
	OnEvent(evLog);

	return true;
}

bool CPlayer::GainSilver(int nSilver, SILVER_REASON reason)
{
	if(nSilver == 0) {
		Log.Error("CPlayer::GainSilver nSilver=0, Reason: %d, Player:"INT64_FMT, reason, GetID());
		return false;
	}

	int nHaveSilver = SilverCoin();
	if(nSilver < 0 && (nHaveSilver + nSilver < 0)) { // 银币不足
		Log.Error("Lack SilverCoin. Have %d, need %d, Reason: %d, player:"INT64_FMT, nHaveSilver, nSilver, reason, GetID());
		return false;
	}

	ChangeFieldInt(Role_Attrib_SilverCoin, nSilver, true);
	this->SyncFieldToData("attr");

	if(SilverCoin() < 0) { // 银币上溢
		Log.Error("Serious Error. SilverCoin Overflow CurSilver: %d, Reason: %d, player:"INT64_FMT, SilverCoin(), reason, GetID());
	}

	// 日志统计
	CEvent *evLog = MakeEvent(Event_Silver_Trade, GetID(), GetFieldI64(Role_Attrib_UserID), nSilver, reason, GetName(), true);
	OnEvent(evLog);

	return true;
}

int CPlayer::GoldCoin()
{
	return GetFieldInt(Role_Attrib_GoldCoin);
}

int CPlayer::SilverCoin()
{
	return GetFieldInt(Role_Attrib_SilverCoin);
}

