//天魔大法.阴癸派武功.

inherit FORCE;
#include <ansi.h>


int valid_learn(object me)
{       
    
	if(me->query_skill("force",1)<10)
		return notify_fail("你的基本内功修为不够，无法领略天魔大法。\n");
    if(me->query_skill("tianmo-dafa",1)>=100&&
		me->query("bellicosity")<100)
		return notify_fail("你的杀气太低了，无法领略天魔大法。\n");
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("「天魔大法」只能通过学来提高!\n");
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
	int lev;
	lev=me->query_skill("tianmo-dafa",1);
	
	if(lev<=50) return 15;
	else if(lev<=100) return 25;
	else if(lev<=150) return 30;
	else return 40;
}

int query_respirate(object me) //吐纳时调用.
{
	int lev;
	lev=(int)me->query_skill("tianmo-dafa",1);
	
	if(lev<=50) return -10;
	else if(lev<=100) return -15;
	else if(lev<=150) return -20;
	else return -50;

}

string sub_exercise(object me)
{
  int lev;
  lev=(int)me->query_skill("tianmo-dafa",1);
  if(lev<=100) return BLU"$N"+NOR+BLU+"缓缓运起天魔功，使气围绕周身缓慢运行。\n"NOR;
  else if(lev<=150) return HIM"$N"+NOR+HIM+"颇为熟练的运起天魔功，顿时面泛红光。\n"NOR;
  else if(lev<=200) return MAG"$N"+NOR+MAG+"运气打坐，面色隐隐泛起红光，天魔功已能内敛于神了。\n"NOR;
  else if(lev<=250) return WHT"$N"+NOR+WHT+"面带笑容地坐在那里，宛如仙子一般。\n"NOR;
  else if(lev<=300) return HIW"$N"+NOR+HIW+"双手随意地放于双膝之上，姿态幽雅，让人顿起爱怜之心。\n"NOR;
  else if(lev<=350) return HIG"$N"+NOR+HIG+"呼吸之声宛如魔音一般，犹如天籁，让人失去自制之力。\n"NOR;
  else if(lev<=400) return RED"$N"+RED+"面色娇媚，异常红润，天仙之色几乎让人丢失魂魄。\n"NOR;
  else return HIR"$N"+NOR+HIR+"好似天仙般坐在那里，一股魔力足以让任何人发狂。\n"NOR;
}

string sub_respirate(object me)
{
  int lev;
  lev=(int)me->query_skill("tianmo-dafa",1);
  if(lev<=100) return BLU"$N"+NOR+BLU+"缓缓运起天魔功，使气围绕周身缓慢运行。\n"NOR;
  else if(lev<=150) return HIM"$N"+NOR+HIM+"颇为熟练的运起天魔功，顿时面泛红光。\n"NOR;
  else if(lev<=200) return MAG"$N"+NOR+MAG+"运气打坐，面色隐隐泛起红光，天魔功已能内敛于神了。\n"NOR;
  else if(lev<=250) return WHT"$N"+NOR+WHT+"面带笑容地坐在那里，宛如仙子一般。\n"NOR;
  else if(lev<=300) return HIW"$N"+NOR+HIW+"双手随意地放于双膝之上，姿态幽雅，让人顿起爱怜之心。\n"NOR;
  else if(lev<=350) return HIG"$N"+NOR+HIG+"呼吸之声宛如魔音一般，犹如天籁，让人失去自制之力。\n"NOR;
  else if(lev<=400) return RED"$N"+RED+"面色娇媚，异常红润，天仙之色几乎让人丢失魂魄。\n"NOR;
  else return HIR"$N"+NOR+HIR+"好似天仙般坐在那里，一股魔力足以让任何人发狂。\n"NOR;
}

string *query_exert() //exert 调用.
{
	return ({"tianmo","huihun","jufen","moxin"});
}

void skill_improved(object me)
{
	int lv = (int)me->query_skill("tianmo-dafa", 1);   

	if (lv == 40)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第一层了。\n"NOR);
	if (lv == 80)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第二层了。\n"NOR);
	if (lv == 120) 
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第三层了。\n"NOR);
	if (lv == 140)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第四层了。\n"NOR);
	if (lv == 160)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第五层了，对你的武功有所增强了。\n"NOR);
	if (lv == 180)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第六层了。\n"NOR);
	if (lv == 200)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第七层了。\n"NOR);
	if (lv == 220)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第八层了。\n"NOR);
	if (lv == 240)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第九层了。\n"NOR);
	if (lv == 260)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第十层了，对你的武功有不小增强。\n"NOR);
	if (lv == 280)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第十一层了。\n"NOR);
	if (lv == 300)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第十二层了。\n"NOR);
	if (lv == 320)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第十三层了。\n"NOR);
	if (lv == 340)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第十四层了，对你的武功有很大的增强。\n"NOR);
	if (lv == 360)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第十五层了。\n"NOR);
	if (lv == 380)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第十六层了。\n"NOR);
	if (lv == 400)
		tell_object(me,HIW"天魔大法十八层神功你已经修炼到了第十七层了，融会了你的武功已经有了很大的突破。\n"NOR);
	if (lv == 450
	    &&!me->query("tianmodafa_quest_allok")
	    &&!me->query("tianmodafa_quest_ok"))
		tell_object(me,HIR"你已经接近天魔大法第十八层境界了，只差一个突破。\n"NOR);
	if (me->query("tianmodafa_quest_allok")||me->query("tianmodafa_quest_ok"))
		tell_object(me,RED"你的天魔大法已经贯通了十八层境界！达至大成了！\n"NOR);
		
}

string query_level_msg(object me,int lv)
{
	
	if (lv <= 40)
		return BLU"第 一 层"NOR;
	if (lv <= 80)
		return BLU"第 二 层"NOR;
	if (lv <= 120) 
		return HIB"第 三 层"NOR;
	if (lv <= 140)
		return HIB"第 四 层"NOR;
	if (lv <= 160)
		return HIB"第 五 层"NOR;
	if (lv <= 180)
		return CYN"第 六 层"NOR;
	if (lv <= 200)
		return CYN"第 七 层"NOR;
	if (lv <= 220)
		return CYN"第 八 层"NOR;
	if (lv <= 240)
		return CYN"第 九 层"NOR;
	if (lv <= 260)
		return CYN"第 十 层"NOR;
	if (lv <= 280)
		return HIC"第十一层"NOR;
	if (lv <= 300)
		return HIC"第十二层"NOR;
	if (lv <= 320)
		return HIC"第十三层"NOR;
	if (lv <= 340)
		return HIW"第十四层"NOR;
	if (lv <= 360)
		return HIG"第十五层"NOR;
	if (lv <= 380)
		return HIG"第十六层"NOR;
	if (lv <= 400)
		return HIR"第十七层"NOR;
	if(!me->query("tianmodafa_quest_allok")&&
	   !me->query("tianmodafa_quest_ok"))
	   return HIR"第十七层"NOR;
	return RED"第十八层"NOR;
		
}