//飘梦剑法.
//中级-->终极武功。

inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N身行闪动，令$n不知所踪，突然一招「惊雷乍现」刺向$n的$l处！",
    "apply_factor": 2,
    "name" : "惊雷乍现", 
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N手中的$w四方闪动，勾画出一片剑网，猛地一招「梦醒东溟」刺向$n的$l处！",
    "apply_factor": 5,
    "name" : "梦醒东溟",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N身行漂浮不定，围住$n不住旋转，手中的$w一招「醉梦八方」突然刺向$n的$l！",
    "apply_factor": 10,
    "name" : "醉梦八方",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N身行变慢，左手护住头部，似是醉梦之状，手中的$w一招「黄梁美梦」刺向$n的$l！",
    "apply_factor": 7,
    "name" : "黄梁美梦",
    "damage_type":"刺伤",
  ])});   

string *parry_weapon=({

"$N手中的$w令人琢磨不定，虚虚实实，$n只觉得陷入了一个无底的旋涡，连忙后退开来。\n",
"$N轻叱一声，用力一挥$w，只见$w划过一条美丽的曲线，封住了$n的$v。\n",
"$N一看形势不妙，连忙唰唰唰三招将门户守住，$n也是无可奈何！\n",
"$N的$w直朝$n的下盘刺去，$n无奈之下，只好收回了$v。\n"

});

string *parry_hand=({

"$N的$w有如长了眼睛，朝$n的手腕刺去，$n无奈之下只好后退几步。\n",
"$N一挥手中的$w，$w宛如铁索一般，横在了两人之间，$n的进攻之力也化为乌有！\n",
"$N轻笑一声，手中的$w挥舞起来，犹如仙子舞蹈，轻轻带过了$n的进攻。\n",
"$N的$w轻轻一带，化解了$n的进攻！\n"

});


string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

mapping query_action(object me,object weapon)
{
         return action[random(sizeof(action))];
 

}
mapping *query_all_action(object me)
{
return action;	
}

string query_type()    
{                      
	return "sword";
}
string query_base()  
{
	return "sword";
}

int valid_learn(object me)
{
	object weapon;
   if(!objectp(weapon=me->query_temp("weapon"))||
	  weapon->query("skill_type")!="sword")
			return notify_fail("手中无剑,如何学习飘梦剑法？\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
 
 return 1;  


}
string *query_perform()
{
	return ({"duomeng","zuimeng"}); 
}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}


int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/duomeng"))
  return 180;
  return 100;
}
