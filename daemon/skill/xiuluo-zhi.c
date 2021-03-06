// 修罗指。慈航静斋。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N运气于拇指之上，迎上$n的进攻，一招「无心修罗指」刺向$n的$l!",
        "apply_factor": 2,
        "name" : "无心修罗指",
       "damage_type": "刺伤"
]),

([  "action": "$N食指灵活闪动，坐虚右实，一招「无刺修罗指」刺向$n的$l!",
        "apply_factor": 5,
        "name" : "无刺修罗指",
        "damage_type": "刺伤"
]),

([      "action": "$N中指稳而不乱，守中带攻，一招「无静修罗指」‘哧’地一声刺向$n!",
        "apply_factor": 8,
        "name" : "无静修罗指",
        "damage_type": "刺伤"
]),

([  "action": "$N无名指划了个弧线，一道气劲直朝$n的$l处射去，正是一招「无形修罗指」!",
        "apply_factor": 4,
        "name" : "无形修罗指",
        "damage_type": "刺伤"
]),
([  "action": "$N小拇指灵活闪动，飘忽不定，突然一招「无伤修罗指」刺向$n的$l!",
        "apply_factor": 6,
        "name" : "无伤修罗指",
        "damage_type": "刺伤"
]),

});

string *parry_weapon=({

"$N手指微微一动，于破空之中形成哧的一声，只见一道气劲挡开了$n的$v。\n",
"$N手指不住变换，幻化出种种奇异之象，$n大吃一惊，连忙收回$v。\n",
"$N动作轻柔，指法丝毫不带任何杀气，周身隐约闪现出圣女的光辉，$n的$v是无论如何也无法进攻了。\n",
"$N动作静如处女，动如脱兔，手指如闪电般朝$n的额头点去，$n连忙撤回$v退开。\n"

});

string *parry_hand=({

"$N手腕微动，手指瞬间变换刺、挑、钩等几个招数，$n的攻势不由得缓了下来。\n",
"$N手指凝住不动，遥遥的指向$n的要害之处，虽然一招未出，但$n却找不到$N的破绽。\n",
"$N轻声一笑，好似天籁一般，$n顿时生出不忍战斗只感。$N手指一挥，已经封住了所有的破绽。\n",
"$N手指在地上一划，只见一道气劲将地面划出一个圆弧，溅起的碎石朝$n飞去，迫得$n退后一步！\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

mapping query_action(object me)  
{
       return action[random(sizeof(action))];
}

mapping *query_all_action(object me)
{
return action;	
}

int valid_learn(object me)
{
       
     if((int)me->query("PKS",1)>=5)
	return notify_fail("你杀的人太多了，无法学习修罗指。\n");
     if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
     return notify_fail("空了手才能学习修罗指。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if((int)me->query("PKS",1)>=5)
	return notify_fail("你杀的人太多了，无法练习修罗指。\n");
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习修罗指!\n");
     return 1;
}

string *query_perform()
{
	return ({"lingxi"});   
}


string query_type() 
{
	return "hand";
}

string query_base()
{
	return "finger";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  
  return 120;
}
