//大金刚轮印。
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
     int i;
     object weapon;
     
     if(target&&target!=me)
     return notify_fail("你只能对自己使用「大金刚轮印」。\n");
     
     weapon=me->query_temp("weapon");	
     if(weapon)
     return notify_fail("拿着武器，如何使用「大金刚轮印」？\n");
    if(!me->query_skill("jiuzi-zhenyan",1))
    return notify_fail("不学[九字真言]如何使用「大金刚轮印」？\n");
    if((int)me->query("max_force")<2000)
    return notify_fail("你的内力修为太低了!\n");
    if((int)me->query("force")<800)
    return notify_fail("你的内力不够使用此招数!\n");
    if((int)me->query_skill("jiuzi-zhenyan",1)<140)
    return notify_fail("你的九字真言太差了！\n");
    if((int)me->query_skill("strike",1)<140)
    return notify_fail("你的基本掌法还不到家！\n");
    if(me->query("eff_kee")>=me->query("max_kee"))
    return notify_fail("你现在没有受内伤，没有必要使用大金刚轮印。\n");
    
    if(time()-me->query_temp("perform_busy")<30)
      return notify_fail("连续施展「大金刚轮印」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    message_vision(HIR"$N"+HIR+"深吸一口气，暗捏大金刚轮印，脸上红光闪现，瞬间恢复血色！\n"NOR,me);
    
    me->receive_curing("kee",me->query_skill("jiuzi-zhenyan",1)*4);
    me->add("force",-800);
    
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
