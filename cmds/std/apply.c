// apply.c
//written by yanyan.
//2000.11.
//for datang-shuanglong.
//last Update By Yanyan@dt 2003.9.9

inherit F_CLEAN_UP;

#include <ansi.h>

string swap_skill(string type)
{
	switch(type){
		case "damage":return HIR"伤害"NOR;
		case "dodge" :return HIM"敏捷"NOR;
	    case "parry" :return WHT"招架"NOR;
	}
}

int main(object me, string arg)
{
	string skill;
	int action,factor;
	string flag;
	mapping apply_action;
	object weapon;
	string type;
	int old_damage,old_dodge,old_parry;		
	
	if(!arg)
		return notify_fail("请使用 apply damage 或 apply parry 或 apply dodge 。\n");
	if(arg=="none")
	{
				
	  	me->delete("prepare");
		tell_object(me,"你决定在战斗中不指定使用招数!\n");
		return 1;
	}
	if(me->query_temp("combat"))
		return notify_fail("\n你正在尽全力使用绝技！\n");
	if(sscanf(arg,"%s %s",skill,flag)==2
	  &&flag=="y")
	{
	  if(!me->query_skill(skill))
	  return notify_fail("你没有这种武功。\n");
	  if(SKILL_D(skill)->query_type()=="knowledge"||
	     SKILL_D(skill)->query_type()=="literate"||
	     SKILL_D(skill)->query_type()=="dodge"||
	     SKILL_D(skill)->query_type()=="force_skill"||
	     SKILL_D(skill)->query_type()=="base")
	  return notify_fail("这种武功不能用在战斗中的！\n");
	  me->set("prepare/"+SKILL_D(skill)->query_type(),skill);
	  tell_object(me,"你决定以后战斗中只使用"+to_chinese(skill)+"。\n");
	  return 1;
	}
	
	if( sscanf(arg, "%s",type)!=1)
                return notify_fail("指令格式：apply 类型\n");
    
    	if(type!="damage"&&type!="dodge"&&type!="parry")
      		return notify_fail("类型只能是 伤害(damage)、敏捷(dodge)和招架(parry)其中之一。\n");
      	
	me->set_temp("combat",1);
	apply_action=me->query("actions");
	tell_object(me,"\n你决定提高"+chinese_number(apply_action["apply_factor"])+"成"+swap_skill(type)+"的效果。\n");
	skill=me->reset_action(me->query_temp("weapon"));
	
	factor = apply_action["apply_factor"]*me->query_skill(skill,1)/10;
	
	old_damage = me->query_temp("apply/damage");
	old_dodge  = me->query_temp("apply/dodge");
	old_parry  = me->query_temp("apply/armor");
	if(type == "damage"){
		me->add_temp("apply/damage",factor);
		me->add_temp("apply/dodge",-factor/2);
		me->add_temp("apply/armor",-factor/2);
		message_vision(CYN"\n$N"+NOR+CYN"的出手突然重了起来！\n"NOR,me);
	}
	else
	if(type == "dodge"){
		me->add_temp("apply/dodge",factor);
		me->add_temp("apply/damage",-factor/2);
		me->add_temp("apply/armor",-factor/2);
		message_vision(CYN"\n$N"+NOR+CYN"的身法突然敏捷了起来！\n"NOR,me);
	}
	else{
		me->add_temp("apply/armor",factor);
		me->add_temp("apply/damage",-factor/2);
		me->add_temp("apply/dodge",-factor/2);
		message_vision(CYN"\n$N"+NOR+CYN"收紧门户，不漏丝毫破绽！\n"NOR,me);	
	}
	
	call_out("remove_factor",10,me,apply_action["apply_factor"],old_damage,old_dodge,old_parry);
	return 1;
	
}

void remove_factor(object me,int factor,int old_damage,int old_dodge,int old_parry)
{
	if(!me)
		return;
	
	me->delete_temp("combat");
	if(me->is_fighting())
		message_vision(CYN"\n$N"+NOR+CYN+"长吁了口气，双手十字交错，后退了几步。\n"NOR,me);
	else
		message_vision(CYN"\n$N"+NOR+CYN+"长吁了口气，气息缓缓沉于丹田。\n"NOR,me);
	
	me->set_temp("apply/damage",old_damage);
	me->set_temp("apply/dodge",old_dodge);
	me->set_temp("apply/armor",old_parry);
	
	me->set_temp("apply_pause_fight",random(factor/2));
	
}

int help (object me)
{
        write(@HELP
        
apply 技能类型

	技能类型分为 伤害(damage)、招架(parry)、和敏捷(dodge)。
例如：
	yong damage
	那么你将会增加你在战斗中的伤害，不过同时，你会相应的降低招
架和敏捷。同理，如果你增加了招架，那么伤害和敏捷会降低；你增加了敏
捷，那么伤害和招架会降低。
    增加威力的数值是根据你所使用的武功随机选择的，每一套武功的招数
的威力都不相同，可以用 action 命令查看，
如：action tianmo-jianfa，不过action命令只能查看你所学的武功。
如： action tianmo-jianfa
┏━tianmo-jianfa 招数━━━━━━━━━━━━━━━━━━━━━┓
┃第一招       「魅影请命」             威力：2                 ┃
┃第二招       「天魔飞舞」             威力：3                 ┃
┃第三招       「鬼影圆舞」             威力：4                 ┃
┃第四招       「天魔魅影」             威力：5                 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

    注意：不管你的技能多高，这种效果只会持续 10 秒钟。在全部施
展完毕后，会根据所施展招数的威力来暂停几个回合的战斗。这就意味
着如果你用了攻击力最强的第四招，那么在结束时，你就有可能在接下
来的几个回合里只能处于防守的状态了。因为是随机的，所以如果运气
好，也可能不会有暂停的时候。

HELP
        );
        return 1;
}