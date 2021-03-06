// 折花百式。
//花间派刀法。
//中级-->终极武功。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N一式「以意相求」忽地放手，$w的尾端向上弹起，以意想不到方位呼的向$n戳去！",
        "apply_factor": 2,
        "name" : "以意相求",
       "damage_type": "砍伤"
]),

([  "action": "$N突然一声清啸，一招「花间月影」虚虚实实，是是而非的击向$n的$l！",
        "apply_factor": 5,
        "name" : "花间月影",
        "damage_type": "砍伤"
]),

([      "action": "不见$N如何动作，忽然来到$n右侧三尺许处,「有中寻无」抽出$w随手向$n飞去！",
        "apply_factor": 10,
        "name" : "有中寻无",
        "damage_type": "砍伤"
]),

([  "action": "$N身形突然左右闪动，飘忽不定，突然迅捷地使出一招「冷花拂面」削向$n的$l！",
        "apply_factor": 7,
        "name" : "冷花拂面",
        "damage_type": "砍伤"
]),
([  "action": "$N手中的$w划出一个个的圈子，这招「天方地园」一出，顿时裹得$n眼花缭乱，不知所措！",
        "apply_factor": 4,
        "name" : "天方地园",
        "damage_type": "砍伤"
]),
([  "action": "$N一式「虬枝突现」忽地出手，并指成刀，以意想不到方位呼的向$n戳去！",
        "apply_factor": 6,
        "name" : "虬枝突现",
        "damage_type": "刺伤"
]),
([  "action": "$N突然一声清啸，一招「片片落花」虚虚实实，是是而非的击向$n的$l！",
        "apply_factor": 3,
        "name" : "片片落花",
        "damage_type": "砍伤"
]),
});

string *parry_weapon=({

"$N潇洒地一个转身，充满了诗情画意，轻轻一挥$w挡住了$n的$v！\n",
"$N面带微笑，完全不象是在战斗中，手中$w充满画意的一招，已经将$n的$v格开！\n",
"$N潇洒地几个转身，手中$w挥舞开来，宛如片片鲜花坠落，令$n不得不撤回$v。\n",
"$N手中$w不带丝毫的杀气，削砍之式宛如观花之人，丝毫不差地挡开了$n的$v！\n"

});

string *parry_hand=({

"$N动作幽雅，显出一派风流倜傥的样子，手中$w点到即止地挡住了$n的进攻！\n",
"单看$N的动作，好似在潇洒地舞蹈，又好似在观赏百朵鲜花，$w一挥一削之间，$n的进攻化为乌有！\n",
"$N悠然挥舞着$w，口中缓慢诵出一首诗，动作和诗句配合之中，封住了$n的进攻。\n",
"$N周身显出一股悠然意境，在不经意之间，$w已封住了$n的进攻，并迫得$n退后几步！\n"

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
	object weapon;
	
	//if(me->query("huajian_skill")!="zhehua-baishi")
	// return notify_fail("你无法学习折花百式！\n");
	 
	weapon=me->query_temp("weapon");
	if (!weapon||weapon->query("skill_type")!="blade")
            return notify_fail("只有装备刀类的兵器才可以学习折花百式。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
	weapon=me->query_temp("weapon");
	if (!weapon||weapon->query("skill_type")!="blade")
            return notify_fail("只有装备刀类的兵器才可以练习折花百式。\n");
     return 1;
}

string *query_perform()
{
	return ({"zhi","zhe"});   
}


string query_type() 
{
	return "blade";
}

string query_base()
{
	return "blade";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}



int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/zhi"))
  return 200;
  return 100;
}

