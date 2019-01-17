//多梦。

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50 //此pfm 伤害高，命中也不错

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int damage,flag;
    
    flag=0;
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
	   return notify_fail("「多梦」只能在战斗中使用!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("手中无剑，如何使用「多梦」？\n");
    if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("piaomeng-jianfa",1))
    return notify_fail("不学「飘梦剑法」如何使用「多梦」？\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("sword",1)<160)
    return notify_fail("你的基本剑法太差了！\n");
    if((int)me->query_skill("piaomeng-jianfa",1)<160)
    return notify_fail("你的「飘梦剑法」还不到家！\n");
    if((int)me->query_skill("bihai-force",1)<150)
    return notify_fail("你的「碧海神功」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「多梦」！\n");
    if(me->query("perform_quest/duomeng")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("连续施展「多梦」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/duomeng")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("连续施展「多梦」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    
    if(!me->query("perform_quest/duomeng"))
    damage=damage/2;
    else damage=damage*2;
    
    msg=WHT"$N"+WHT+"的$w"+WHT+"泛成一道白光转如风轮，那一圈圈回旋，似极我佛如来顶后的般若光轮。在这\n"+
        "白色光轮之中，那光霞为之失色、消失，$n"+WHT+"不由得为之色变！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「多梦」只能在战斗中使用!\n");
    
    msg=YEL"$N"+YEL+"和$n"+YEL+"终究一接触，刹那，白色光轮化成雾，雾是$w"+YEL+"的颜色。这雾，如纱、如诗、\n"+
        "如梦、如……情人褪下最后一件衣衫── \n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「多梦」只能在战斗中使用!\n");
        
    msg=MAG"$N"+MAG+"手中$w"+MAG+"忽地淡化开来，化做一片淡淡地气影，朝$n"+MAG+"遍洒下来。就当要击中$n"+MAG+"时，气势\n"+
        "突然变盛，气影忽然收缩，化为普普通通的一击！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(objectp(target)&&random(10)>6){
    	msg=YEL"\n$N"+YEL+"气息一乱，身形已然迟缓，不由得大惊失色！\n\n"NOR;
    	message_vision(msg,target);
    	target->start_busy(random(3));
    }
    
   me->set_temp("perform_busy",time());
    return 1;   
  
}  

