//渡劫指
//一指劲
//by rzy 02.9.18

#include <ansi.h>
inherit SSERVER;

int perform(object me,object target) {
        object weapon;
        int ap,vp;
        
        weapon=me->query_temp("weapon");
        
        if(!target)
          if(!objectp(target=offensive_target(me)))
        	return notify_fail("目前你没有攻击的目标！\n");
        if(!me->is_fighting())
                return notify_fail("只有在战斗时才可以使用「一指劲」！\n");
        if(me->query("PKS")>=5)
        return notify_fail("你罪孽深重，无法使用此绝技了！");
        if(weapon)
                return notify_fail("拿着武器无法使用「一指劲」！\n");
        if((int)me->query_skill("wuxiang-shengong",1)<110)
        	return notify_fail("你的「无相神功」修为太低！\n");
        if(!me->query_skill("dujie-zhi",1))
                return notify_fail("你还没有学会「渡劫指」！\n");
        if((int)me->query("max_force")<1000)
                return notify_fail("以你的内力修为无法使出「一指劲」这样的招数！\n");
        if((int)me->query_skill("dujie-zhi",1)<110)
                return notify_fail("你的「渡劫指」还不够娴熟！\n");
        if((int)me->query_skill("finger",1)<110)
                return notify_fail("你的基本指法还不到家！\n");
	if(me->query("apply_points")<=0)
		return notify_fail("你的气势不足，无法使用「一指劲」！\n");
        if(time()-me->query_temp("perform_busy")<6)
                return notify_fail("连续施展「一指劲」需要深厚的先天真气支持，你修为不够，如何能行？\n");
        if(me->query_skill("bikouchan",1)<100)
		return notify_fail("你的闭口禅修为太低了！\n");
        
        ap=me->query_int()+me->query_dex()+me->query("combat_exp")/50000;
        vp=target->query_int()+target->query_dex()+target->query("combat_exp")/50000;
        
	message_vision(MAG"$N"+MAG+"身形快速转动，口中高宣佛号，劲气迸发，手指连动，瞬间发出数道指力，直袭击向$n"+MAG+"！ \n"NOR,me,target);
		
        if(!target->query_temp("weapon")) {
        	
        	if(random(ap+vp)>vp) {
                	message_vision(HIR"\n$N"+HIR+"被$n"+HIR+"的指力点中，真气无法凝聚，顿时浑身一麻！\n"NOR,target,me);
                	target->start_busy(3);         
        	}
        	else {
			message_vision(HIY"\n$N"+HIY+"纵身跃起，半空中身形连连转动，$n"+HIY+"的指力竟然全部落空！\n"NOR,target,me);
			me->start_busy(random(2)); 
		}
	}
        if(target->query_temp("weapon")) {
        	
        	if( random(ap+vp)>vp) {
        		message_vision(HIR"\n$N"+HIR+"被$n"+HIR+"的指力点中，真气涣散，只觉手中"+target->query_temp("weapon")->name()+HIR+"似有千斤之重，一个把持不住，竟脱手飞出！\n"NOR,target,me);	
			target->query_temp("weapon")->move(environment(target));
		}
		else {
			message_vision(HIY"\n$N"+HIY+"被$n"+HIY+"的指力点中，真气一沉，只觉手中"+target->query_temp("weapon")->name()+HIY+"不断加重，连忙凝气紧握！\n"NOR,target,me);
			target->start_busy(1);
			me->start_busy(2);
		}
	}
	me->set_temp("perform_busy",time());
	return 1;
}