//天罡八诀。宋家堡内功。
inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
 
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("天罡三诀只能通过学来提高!\n");
}


string query_type()
{
	return "force_skill";
}

string query_base()
{
	return "force";
}

int query_exercise(object me)//被打坐时调用。
{
	int level;
	level=(int)me->query_skill("tiangang-bajue");
	if(level<=50)
		return 30;
	else if(level<=120) return 40;
	else return 50;
}

int query_respirate(object me) //吐纳时调用.
{
	int level;
	level=(int)me->query_skill("tiangang-bajue");
	if(level<=50)
		return -30;
	else if(level<=120) return -40;
	else return -50;

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("tiangang-sanjue",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"深吸一口气，然后气走浑身各处，觉得丹田暖和，说不出的舒服。\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"气息自然流通，游走全身经脉，于周围事物晃若无物。\n"NOR;
	else if(level<=200) return HIM+"$N"+NOR+HIM+"盘膝而坐，双掌合扣，周身冒出阵阵热气来。\n"NOR;
	else if(level<=250) return RED"$N"+NOR+RED+"气息绵长，周身隐隐透出一股霸气。\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"五指合拢，放于双膝之上，一股刀意笼罩全身。\n"NOR;
	else if(level<=350) return MAG"$N"+NOR+MAG+"神态威严，气息悠长不绝，让人产生望而生畏的感觉。\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"双手交错放于胸前，只是吐息之间，一股刀意便已经笼罩了全身。\n"NOR;
	else return HIG"$N"+HIG+"静坐不动，气息在"+NOR+MAG+"全身经脉"+HIG+"迅速游走，似已达到超然物外的境界。\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("tiangang-sanjue",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"深吸一口气，然后气走浑身各处，觉得丹田暖和，说不出的舒服。\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"气息自然流通，游走全身经脉，于周围事物晃若无物。\n"NOR;
	else if(level<=200) return HIM+"$N"+NOR+HIM+"盘膝而坐，双掌合扣，周身冒出阵阵热气来。\n"NOR;
	else if(level<=250) return RED"$N"+NOR+RED+"气息绵长，周身隐隐透出一股霸气。\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"五指合拢，放于双膝之上，一股刀意笼罩全身。\n"NOR;
	else if(level<=350) return MAG"$N"+NOR+MAG+"神态威严，气息悠长不绝，让人产生望而生畏的感觉。\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"双手交错放于胸前，只是吐息之间，一股刀意便已经笼罩了全身。\n"NOR;
	else return HIG"$N"+HIG+"静坐不动，气息在"+NOR+MAG+"全身经脉"+HIG+"迅速游走，似已达到超然物外的境界。\n"NOR;
}

string *query_exert() 
{
	return ({"ningxin","zhanyi"});
}
