//踢。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N突然伸出蹄子踢向$n",
        "dodge": 10,
        "force": 50,
		"damage":50,
        "parry" :50,
        
        "damage_type": "踢伤"
]),
([     "action": "$N突然跑了过去，踢了$n一下",
       "dodge": 10,
	   "force":10,
	   "parry":10,
	   "damage_type": "踢伤",
]),


});







mapping query_action(object me)
{
        return action[random(sizeof(action))];
}



