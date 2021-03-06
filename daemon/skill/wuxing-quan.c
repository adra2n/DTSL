// 五行拳.

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N站稳马步,一招[开门见山]打向$n的$l!",
        "dodge": 0,//此招数的攻击力。
        "force": 60,//此招数的伤害力。force+parry=100.
        "parry" : 40,//此招数的防守力。
        
        "damage_type": "瘀伤"//击中后的伤害类型。
]),

([  "action": "$N身子下蹲,一招[秋风卷叶]扫向$n的下盘!",
        "dodge": -5,
        "force": 60,
        "parry" : 40,
       
        "damage_type": "瘀伤"
]),

([      "action": "$N猛的双拳打向$n的$l处,正是一招[双龙出海]！",
        "dodge": 0,
        "force": 60,
        "parry" : 40,
      
        "damage_type": "瘀伤"
]),

([  "action": "$N突然双拳连环出击,正是一招[五行连环],打向$n的$l处!",
        "dodge": -5,
        "force": 60,
        "parry" : 40,
        
        "damage_type": "瘀伤"
]),

});


mapping query_action(object me)  //返回招数名称
{
        return action[random(sizeof(action))];
}


string query_type()  //返回类型。只要不是兵器的武功，在这里都反回为hand.
{
	return "hand";
}

string query_base()//返回基本武功类型。
{
	return "cuff";
}

