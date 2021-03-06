//飞挝鞭法。
//中级-->终极武功。

inherit SKILL;
#include <ansi.h>
mapping *action=({
 ([ "action":"$N突然一纵，凌空朝$n斜扑过来。就像鹫鹰从高处滑翔下降攫取草原上钟爱的美食，\n"+
             "双眸贯注深情，嘴角还逸出一丝自信骄傲的笑意。",
    "apply_factor": 2,
    "name" : "鹫鹰凌空",
    "damage_type":"瘀伤",
  ]),
  ([ "action":"$N忽然$w击至，带起的劲风迫得眼前的$n落叶般飘开，速度与时间角度均无懈可击，\n"+
              "迫得$n只余硬拼一法。",
    "apply_factor": 5,
    "name" : "风卷落叶",
    "damage_type":"瘀伤",
  ]),
  ([ "action":"$N的$w击在虚空处，$n有力的一招，立时威势全消，还似吃了暗亏，闪电般改招换式，\n"+
              "往后退开。",
    "apply_factor": 10,
    "name" : "海市蜃楼",
    "damage_type":"瘀伤",
  ]),
  ([ "action":"$N不屑的冷哼一声，右手移到$w正中处，微抖一下，两端立时化成百千点光影，水银泻\n"+
              "地的往$n洒去。",
    "apply_factor": 7,
    "name" : "九天银河",
    "damage_type":"瘀伤",
  ]),
 ([ "action":"$N冷笑一声，左手微扬，$w的另一端立时化成点点芒光，潮水般洒往$n，下面却飞起一\n"+
             "脚，踢向$n的下盘，变招时从容不迫，教人叹为观止。",
    "apply_factor": 4,
    "name" : "大漠游龙",
    "damage_type":"瘀伤",
  ]),
([ "action":"$N发出一阵长笑，$w回收，似是守式，但身在其中的$n无不感到其中暗藏厉害的杀着，\n"+
            "不得不后退闪避。",
    "apply_factor": 6,
    "name" : "偷天袭月",
    "damage_type":"瘀伤",
  ]),
});   

string *parry_weapon=({

"$N手中$w一伸，紧接着一晃，抖出数点幻影，封住了$n的$v！\n",
"$N微微一笑，手中的$w如灵蛇般朝$n的$v卷去，$n一惊，连忙后退开来！\n",
"$N手中的$w如游龙一般，气势汹涌地朝$n的下盘卷去，$n连忙收回$v后退开来！\n",
"$N低哼一声，手中$w一晃，只听啪的一声，震开了$n的$v！\n"

});

string *parry_hand=({

"$N手中$w一伸，紧接着一晃，抖出数点幻影，封住了$n的进攻！\n",
"$N微微一笑，手中的$w如灵蛇般朝$n的下盘卷去，$n一惊，连忙后退开来！\n",
"$N手中的$w如游龙一般，气势汹涌地朝$n的下盘卷去，$n连忙收招后退开来！\n",
"$N低哼一声，手中$w一晃，只听啪的一声，震开了$n的手掌！\n"

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
string *query_perform()
{
  return ({"kun"});
}
string query_type()    
{                      
	return "whip";
}
string query_base()  
{
	return "whip";
}

int valid_learn(object me)
{
	object weapon;
	if(!objectp(weapon=me->query_temp("weapon"))||
		(string)weapon->query("skill_type")!="whip")
			return notify_fail("手中无鞭，如何学习飞挝鞭法？\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
 
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/kun"))
  return 200;
  return 80;
}
