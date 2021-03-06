// 独尊拳 独尊堡武功
//force+parry=150~180--180~220--280~320

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N腾身而起，双拳猛地挥出，一招「上尊苍天」直击向$n的$l!",
        "apply_factor": 5,
        "name" : "上尊苍天",
       "damage_type": "瘀伤"
]),

([  "action": "$N立定身行，一招「下尊后土」，右拳再猛地挥出，这一拳之威仿佛充满天地!",
        "apply_factor": 5,
        "name" : "下尊后土",
        "damage_type": "瘀伤"
]),

([      "action": "$N双手似拳私掌，变化莫测的功向$n，好一招「北尊沧海」！",
        "apply_factor": 5,
        "name" : "北尊沧海",
        "damage_type": "瘀伤"
]),

([  "action": "$N双拳十字交叉，一招「南尊穆山」左手化弧，右手自下而上打向$n的$l!",
        "apply_factor": 5,
        "name" : "南尊穆山",
        "damage_type": "瘀伤"
]),

([  "action": "$N一声长啸．一招「惟我独尊」,一拳击出，有遇天开天，遇地破地之威!",
        "apply_factor": 5,
        "name" : "惟我独尊",
        "damage_type": "瘀伤"
]),

});

string *parry_weapon=({

"只见$N不顾$n的$v，右手一退$n的$v，$n不得不后退开来。\n",
"$N完全不顾$n的$v，反而以更快的速度打向$n的$l，好象围魏救赵般化解了$n的进攻。\n",
"$N双拳十字交错，攻守兼备，封住了$n的进攻。\n",
"$N双拳打出一片拳影，化解了$n的进攻！\n"

});

string *parry_hand=({

"$N的手掌迎上$n的进攻，只听碰地一声，双方各退后几步。\n",
"$N拳法错乱，如同万千幻影，$n见势不好，连忙后退开来！\n",
"$N招式严谨，出招丝毫不乱，使$n的进攻不得不无功而返。\n",
"$N的拳势轻轻一带，化解了$n的进攻！\n"

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

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习独尊拳。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习独尊拳！\n");
     return 1;
}

string query_type() 
{
	return "hand";
}

string query_base()
{
	return "cuff";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}


int skill_damage(object me,object victim)
{
  int factor=0;
  
  if(me->query_skill("duzun-quan",1)>=120)
  factor=40;
  
  if(me->query_skill("duzun-quan",1)>=180)
   factor +=60;
     
  return factor;
}

int skill_parry(object me,object victim)
{
  int factor=0;
  
  if(me->query_skill("duzun-quan",1)>=120)
  factor=40;
  
  if(me->query_skill("duzun-quan",1)>=180)
   factor +=30;
 
  return factor;
}