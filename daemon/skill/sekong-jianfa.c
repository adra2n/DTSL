//色空剑
//中级-->终极武功

inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N手中$w一抖，一招「帘密厌看花并蒂」，手中$w化成一道银练，攻向$n的$l！",
    "apply_factor": 1,
    "name" : "帘密厌看花并蒂", 
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N轻飘飘地纵身跃起，突然一招「楼高怕见燕双栖」使出，手中$w一转，径刺$n$l！",
    "apply_factor": 2,
    "name" : "楼高怕见燕双栖",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N身形转个不停，一招「休教羌笛惊杨柳」，手中$w如风吹柳动，扰得$n眼花缭乱！",
    "apply_factor": 3,
    "name" : "休教羌笛惊杨柳",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N的$w胸前横立，突然手中$w向$n横扫过去，好一招「未许吹萧惹凤凰」！",
    "apply_factor": 4,
    "name" : "未许吹萧惹凤凰",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N错步上前，忽然间纵身跃起，手中$w一式「兰草不占王者气」对准$n就是一剑！",
    "apply_factor": 5,
    "name" : "兰草不占王者气",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N淡淡一笑，一式「萱花不辨女儿香」，$w带着一股香风刺向$n！",
    "apply_factor": 6,
    "name" : "萱花不辨女儿香",
    "damage_type":"刺伤",
  ]), 
  ([ "action":"$N神态悠闲，手中$w触地，一招「幸我不曾犁地狱」从不可思议的角度划向$n的$l！",
    "apply_factor": 7,
    "name" : "幸我不曾犁地狱",
    "damage_type":"刺伤",
  ]), 
  ([ "action":"$N手腕一抖，使了个「干卿甚事吐青莲」，手中$w舞出一朵青莲对准$n$l挥去！",
    "apply_factor": 8,
    "name" : "干卿甚事吐青莲",
    "damage_type":"刺伤",
  ]), 
  ([ "action":"$N手中$w直指$n$l，一招「惯将不洁调西子」轻妙地划向$n的$l！",
    "apply_factor": 9,
    "name" : "惯将不洁调西子",
    "damage_type":"刺伤",
  ]), 
  ([ "action":"$N神态悠闲，手中$w凭空一指，一招「漫把横陈学小怜」横着一剑划向$n的$l！",
    "apply_factor": 10,
    "name" : "漫把横陈学小怜",
    "damage_type":"刺伤",
  ]), 
  ([ "action":"$N使一招「只为有情成小劫」，手中$w如闪电般地向$n的$l连攻数剑！",
    "apply_factor": 10,
    "name" : "只为有情成小劫",
    "damage_type":"刺伤",
  ]), 
  ([ "action":"$N手中$w手中$w不停地颤抖着，剑气不断的发出，这招「却因无碍到灵台」使得如火纯青！",
    "apply_factor": 10,
    "name" : "却因无碍到灵台",
    "damage_type":"刺伤",
  ]), 
});   


string *parry_weapon=({

"$N脸上毫无表情，不喜、不怒，看似是不经意地一挥手中的$w，却正好挡住$n的$v。\n",
"$N轻啸一声，身形旋转，如同明月下的鲜花，白雪中的苍松，唰地一声$w已经架住了$v。\n",
"$N手中$w几下拨点，犹如鲜花盛开，又如珠落银盘，轻轻巧巧的几个招式，封住了$n的$v。\n",
"$N身形如风般向后一退，手中$w一拨，架开了$n的$v，只留下阵阵的幽香。\n"

});

string *parry_hand=({

"$N手腕一转，$w由下至上一挑，好似仙子提着个花篮，已然封住了$n的进攻。\n",
"面对$n的进攻，$N似乎毫不在意，手中$w一划，一个漂亮的圆弧已然将$n阻挡住。\n",
"$N身形轻盈洒脱，宛如仙子一般，华丽而不带丝毫的俗气，手中的$w更如横天彩虹，完全封住了$n的进攻。\n",
"$N手中$w看准$n的破绽，猛地一招刺去，但是招式不及用老，就在$n致命处停住！\n"

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
	
	if((int)me->query("PKS",1)>=5)
	return notify_fail("你杀的人太多了，无法学习色空剑法。\n");
	
	if(!objectp(weapon=me->query_temp("weapon"))||
	   weapon->query("skill_type")!="sword")
			return notify_fail("手中无剑，如何学习色空剑？\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;
   
   if((int)me->query("PKS",1)>=5)
   return notify_fail("你杀的人太多了，无法练习色空剑法。\n");
	
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
 
 return 1;  


}
string *query_perform()
{
	return ({"kong","se"}); 
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
  
  if(me->query("perform_quest/kong"))
  factor=100;
  
  if(me->query("execute_quest/xinyoulingxi")){
   factor +=150;
   
  }
  if(me->query("execute_quest/jianxintongming")){
   factor +=200;
   
  }
 
  return factor;
}
