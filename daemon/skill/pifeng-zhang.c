//披风杖法.独孤阀尤楚红的武功。
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N手中$w一荡，使出「清风细雨」，但见一道杖影隐隐约约，若有若无地向$n压下",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砸伤",
  ]),
 ([ "action":"$N的$w望上一挑，一招[微风拂柳]已将$n各处退路封死。",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砸伤",
  ]),
  ([ "action":"$N站立不动，$w挥舞，生成一阵强风，一招[风吹莲动]扫向了$n的中盘!",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砸伤",
  ]),
  ([ "action":"$N轻挥$w，杖头颤动，气机牢牢锁住$n,好一招[山雨未来风满楼]",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砸伤",
  ])});   



int valid_learn(object me)    
{
  return 1;    


}

int practice_skill(object me)  
{
  return 1;  


}


mapping query_action(object me,object weapon)
{
   mapping act;
   act=action[random(sizeof(action))];
   return act;
 

}


string query_type()    
{                      
	return "staff";
}
string query_base()  
{
	return "staff";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

