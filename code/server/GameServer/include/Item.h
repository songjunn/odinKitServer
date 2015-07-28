#pragma once
#include "IBaseObj.h"
#include "ItemTemplate.h"


class CPlayer;
class CItem : public IBaseObj
{
public:
	CItem() {}
	virtual ~CItem() {}

	void	Init();
	void	Release();
	bool	OnCreate(int templateid);

	bool	OnCost(int num=1);
	bool	OnUse();
	bool	OnStack(CItem* item);

	void	SedEffect(int index, CEffect eff);
	bool	GetEffect(int index, CEffect& eff);

	inline	bool	IsEquipable()	{return g_IsItemEquipment(m_Type);}		//是否可装备
	inline	bool	IsUseble()		{return g_IsItemFunction(m_Type);}		//是否可使用
	inline	bool	IsStackable()	{return GetFieldInt(Item_Attrib_StackMax) > 1;}	//是否可堆叠

	void	SendClientMsg(PACKET_COMMAND* pack);
	void	SendDataMsg(PACKET_COMMAND* pack);

	void	SyncFieldToData(const char* field = NULL);
	void	SyncFieldIntToClient(int i, CPlayer* toPlayer = NULL);
	void	SyncFieldI64ToClient(int i, CPlayer* toPlayer = NULL);

	void	SyncFieldInt(int i, bool client = false, bool data = false, CPlayer* toPlayer = NULL);
	void	SyncFieldI64(int i, bool client = false, bool data = false, CPlayer* toPlayer = NULL);

	char*	GetName() { return m_name; }
	const CEffect &GetUseEffect() { return m_EffectUse; }

protected:
	int*	_FindFieldInt(int i);
	int64*	_FindFieldI64(int i);

	void	_SetXmlFieldInt(int i, int value);
	void	_SetXmlFieldI64(int i, int64 value);

	int		_GetXmlFieldInt(int i);
	int64	_GetXmlFieldI64(int i);

private:
	ItemID		m_ItemID;				//物品实体ID
	PersonID	m_ParentID;				//拥有者ID
	char		m_name[OBJ_NAME_LEN];	//名字
	int			m_Type;					//类型
	int			m_Career;				//职业限制
	int			m_Sex;					//性别限制
	int			m_MinLevel;				//最低等级限制
	int			m_Quatily;				//品质
	int			m_StackMax;				//最大堆叠数量
	int			m_SellPrice;			//出售价格
	CEffect		m_EffectUse;			//使用效果
	CEffect		m_EffectEquip[EQUIP_EFFECT_MAX];	//装备效果

	int			m_StackSize;			//堆叠数量
	int			m_Position;				//装备位置
	PersonID	m_RoleId;               //装备英雄id

	int 		m_Strength;             //力量
	int 		m_Intellect;            //智力
	int 		m_Technique;			//技巧
	int 		m_Agility;				//敏捷

	int 		m_Hit;					//命中值
	int			m_Jouk;					//闪避值
	int 		m_Crit;					//暴击值
	int 		m_Tenacity;				//韧性值
	int 		m_Parry;				//格挡值
	int 		m_Treat;				//治疗力

	int 		m_BaseHpMax;			//基础生命值上限
	int 		m_BasePhysiDamage;      //基础物理攻击
	int 		m_BasePhysiDefense;		//基础物理防御
	int 		m_BaseMagicDamage;		//基础魔法攻击
	int 		m_BaseMagicDefense;		//基础魔法防御
	int			m_BaseStuntDamage;		//基础绝技攻击
	int			m_BaseStuntDefense;		//基础绝技防御

	int 		m_Current_level;		//当前装备强化等级, 初始0
	int 		m_MaxLevel_intensify;   //装备强化上限
	int			m_NextGradeTemplateId;  //装备升级,下一等级模板id
	int			m_UpGradeCharge;       // 装备升级手续费

	int 		m_IntensifyJadePoints;
	int 		m_IntensifyJadeBasePoints;	
	int 		m_LayCharge;
public:	
	//int 		m_Intensify_points[CHARGE];		//从当前强化等级强化到下一级需求点数
	//int 		m_Charge[CHARGE];				//手续费
	
	int			m_Souls[ITEM_KONG];//已镶嵌魂晶魂玉 列表，模板id
//魂晶
	SoulCrystal m_crystal[ITEM_ARRTU];

	UpGradeNeeds m_UpGrade[ARR_LENS];	//升级需要
private: 
	int			m_SoulType;				//魂玉种类, 日1， 月2， 星3， -1
	int			m_SoulPoints;				//魂玉点数

};
