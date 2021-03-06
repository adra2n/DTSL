// 碧海鞭法 宋阀，宋玉致，『虎衣红粉』欧阳倩
//damage+parry=120~160--160~200-->260~300
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N身行晃动，手中$w轻轻一摆，一招「随波逐流」打向$n的$l处！",
        "apply_factor": 4,
        "name" : "随波逐流",
        "damage_type": "瘀伤"
]),

([  "action": "$N抽身转式，$w旋动起来，化出一道道的圆弧，一招「浪卷残云」罩向$n!",
        "apply_factor": 4,
        "name" : "浪卷残云",
        "damage_type": "瘀伤"
]),

([      "action": "$N整条$w在先现出波浪似的曲纹,一招「巨浪滔天」鞭尖刺向$n的$l处！",
        "apply_factor": 4,
        "name" : "巨浪滔天",
        "damage_type": "瘀伤"
]),

([  "action": "$N的$w猛然击出，一招「长鲸吸水」,$w如一条白练向$n打了过去！",
        "apply_factor": 4,
        "name" : "长鲸吸水",
        "damage_type": "瘀伤"
]),

([  "action": "$N手中$w抽向$n，看似简单的一鞭，却让$n玄之又玄,好一招「深渊龙腾」击向$n!",
        "apply_factor": 4,
        "name" : "深渊龙腾",
        "damage_type": "瘀伤"
]),
});

string *parry_weapon=({

"$N手中的$w宛如灵蛇一般，卷向$n的$v，毫不费力的挡开了$n的进攻。\n",
"$N手中的$w朝$n的手腕卷去，$n一惊，连忙收招回。\n",
"$N手中的$w划了一个圆弧，宛如龙游天空，卷向$n的$v。\n",
"$N的$w直朝$n的下盘攻去，$n无奈之下，只好收回了$v。\n"

});

string *parry_hand=({

"$N的$w有如长了眼睛，朝$n的手腕卷去，$n无奈之下只好后退几步。\n",
"$N一挥手中的$w，$w在两人之间化成一道铁壁，横在了两人之间，$n的进攻之力也化为乌有！\n",
"$N轻笑一声，手中的$w挥舞起来，犹如仙子舞蹈，轻轻带过了$n的进攻。\n",
"$N的$w轻轻一缠，一饶，一带，化解了$n的进攻！\n"

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
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("不拿武器如何学习碧海鞭？\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("你拿的武器不对。\n");
	
     return 1;  
        
       
}

int practice_skill(object me)
{
      
object weapon;
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("不拿武器如何练习碧海鞭？\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("你拿的武器不对。\n");
      
     return 1; 
}

string query_type()  
{
	return "whip";
}

string query_base()
{
	return "whip";
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
  
  if(me->query_skill("bihai-bianfa",1)>=120)
  factor=40;
  
  if(me->query_skill("bihai-bianfa",1)>=180)
   factor +=40;
     
  return factor;
}

int skill_parry(object me,object victim)
{
  int factor=0;
  
  if(me->query_skill("bihai-bianfa",1)>=120)
  factor=40;
  
  if(me->query_skill("bihai-bianfa",1)>=180)
   factor +=30;
 
  return factor;
}