// 天罡拳。静念禅院.
//中级-->终极武功

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N步伐沉稳，双拳虎虎生风，一招「开门拜客」打向$n的$l！",
        "apply_factor": 2,
        "name" : "开门拜客",
       "damage_type": "瘀伤"
]),

([  "action": "$N身行站稳，双拳划了个圆弧，向$n集中打去，正是一招「童子拜佛」打向$n的$l！",
        "apply_factor": 5,
        "name" : "童子拜佛",
        "damage_type": "瘀伤"
]),

([      "action": "$N左拳连击了数下，挡住了$n的进攻，同时右拳猛地划了个弧线击出，正是一招「流星摆尾」！",
        "apply_factor": 10,
        "name" : "流星摆尾",
        "damage_type": "瘀伤"
]),

([  "action": "$N的身行快速旋转，躲开了$n的攻击，同时左拳击向$n的上路，右拳击向下路，正是一招「双龙出海」！",
        "apply_factor": 7,
        "name" : "双龙出海",
        "damage_type": "瘀伤"
]),

});

string *parry_weapon=({

"$N面带微笑，双拳似轻似重，顿时使$n的$v有无从下手之感！\n",
"$N左拳微微一带，举轻若重地卸开了$n的进攻！\n",
"$N一挥双拳，$n只觉得自己的进攻落空了，险些跌倒在地。\n",
"$N的双拳朝$n的手腕打去，$n急忙后退，手中的$v险些被打落在地！\n"

});

string *parry_hand=({

"$N双拳变换无常，以守代攻地架开了$n的进攻。\n",
"$N微微一笑，双拳一挥，$n的进攻已经被冰消瓦解！\n",
"$N双拳一挥，随后闪开，寻找着进攻的机会。\n",
"$N双拳不住变换，虽是简单的招式，却封住了$n的全部进攻之力！\n"

});

mapping query_action(object me)  
{
     return action[random(sizeof(action))];
        
}
mapping *query_all_action(object me)
{
return action;	
}
string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

int valid_learn(object me)
{
    if(me->query("chanyuan_skill")!="tiangang-quan")
    return notify_fail("你不能学习这个技能！\n");
    if((int)me->query("PKS",1)>=5)
    return notify_fail("你只觉得自己作孽深重，不能在继续学习下去了!\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习天罡拳。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(me->query("chanyuan_skill")!="tiangang-quan")
    return notify_fail("你不能练习这个技能！\n");
      if((int)me->query("PKS",1)>=5)
    return notify_fail("你只觉得自己作孽深重，不能在继续练习下去了!\n");
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习天罡拳。\n");
     return 1;
}

string *query_perform()
{
	return ({"tiangang","zhenhun"});   
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
  if(me->query("perform_quest/tiangang"))
  return 180;
  return 90;
}
