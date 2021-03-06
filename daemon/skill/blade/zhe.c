//折花百式
//折花
//by rzy 02.9.16
#include <ansi.h>
inherit SSERVER;

#define REDUCE_DEX -150

int perform(object me,object target) {
	object weapon;
	int damage=me->query("apply_points"),flag=0;
	string msg;

	weapon=me->query_temp("weapon");

	if(!target)
          if(!objectp(target=offensive_target(me)))
		return notify_fail("目前你没有攻击的目标！\n");
	if(!me->is_fighting())
		return notify_fail("「折花」要在战斗中使用！\n");
	if(!weapon)
		return notify_fail("空手无法使用「折花」！\n");
	if(weapon->query("skill_type")!="blade")
		return notify_fail("你使用的武器不对！\n");
	if(weapon->query("flag")==1)
		return notify_fail("断掉的兵器不能再使用了！\n");
	if(!me->query_skill("zhehua-baishi",1))
		return notify_fail("你不会「折花百式」怎么能使用「折花」？\n");
	if(me->query("apply_points")<=0)
		return notify_fail("你的气势不足，无法使用「折花」！\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("以你的内力修为，使不出「折花」这种绝技！\n");
	if((int)me->query_skill("blade",1)<110)
		return notify_fail("你的基本刀法太差了！\n");
	if((int)me->query_skill("zhehua-baishi",1)<110)
		return notify_fail("你的「折花百式」还不到家！\n");
	if((int)me->query_skill("flower-force",1)<110)
		return notify_fail("你的「飞花流水」还不到家！\n");
	if(time()-me->query_temp("perform_busy")<10)
		return notify_fail("连续施展「折花」需要深厚的先天真气支持，你修为不够，如何能行？\n");
	if(me->query_skill("huachan",1)<100)
		return notify_fail("你的画禅修为太低了！\n");

	msg=HIG"$N"+HIG+"双目精光绽放，$w"+HIG+"向前急刺，$w上透出一道凝聚至有形的内家真气，往$n"+HIG+"激射过去。\n"
		"竟然比其它招数都快上数倍！\n"NOR;   
		
		flag += COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
		
		
        if(!me->is_fighting())
                 return 1;
        else if(flag && random(10)>4) {
		msg=HIR"\n"+"$n"+HIR+"浑身穴道被$N的真气所困，无法自如的行动！\n"NOR;
		message_vision(msg,me,target);
		target->start_busy(random(3)); 
	}
	me->set_temp("perform_busy",time());
	return 1;

}
