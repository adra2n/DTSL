/*
NPC 所使用的刀法，分为等级的。这是第二级的刀法---level two.
*/
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N手中$w冒出阵阵寒气，“唰”地一声出奇不意地朝$n的$l刺来！",
    "apply_factor": 5,
    "name" : "刀法",
    "damage_type":"砍伤",
  ]),
 ([ "action":"$N身形下沉，身子不住旋转，手中$w挽做一团刀花朝$n的$l处削去！",
    "apply_factor": 5,
    "name" : "刀法",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N手中$w一挥，招式大开大阖，只见瞬时万般刀光朝$n的$l处砍来！",
    "apply_factor": 5,
    "name" : "刀法",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N手中的$w略走偏锋，$w左转有弯，阴诡无比一招砍向$n的$l！",
    "apply_factor": 5,
    "name" : "刀法",
    "damage_type":"砍伤",
  ])});   






mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}


string query_type()    
{                      
	return "blade";
}
string query_base()  
{
	return "blade";
}

int valid_learn(object me)
{
	return 1;
}
int practice_skill(object me)  
{
 
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

