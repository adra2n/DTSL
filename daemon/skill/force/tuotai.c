//换日大法。脱胎换骨。

#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	if(target!=me)
			return notify_fail("你只能对自己使用脱胎换骨！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
        if((int)me->query_skill("huanri-dafa",1)<120)
		return notify_fail("你的换日大法修为不够！\n");
        if((int)me->query_skill("force",1)<120)
        return notify_fail("你的基本内功修为不够！\n");
	if(me->query("max_force")<2000)
		return notify_fail("你的内力修为不够！\n");
        if(me->query("force")<200)
		return notify_fail("你的内力不足以使用此内功！\n");
	
	if(me->query_temp("exert_huanri"))
	return notify_fail("你正在使用此内功！\n");
	
	if(time()-me->query_temp("exert_huanri_busy")<10)
          return notify_fail("连续施展「脱胎换骨」需要深厚的先天真气支持，你修为不够，如何能行？\n");
	
	message_vision(HIR"$N"+HIR+"深吸了一口气，脸上突然红光闪现，全身骨骼做响！\n"NOR,me);
	
	me->add_temp("apply/damage",me->query_skill("huanri-dafa",1));
	me->add_temp("apply/dodge",me->query_skill("huanri-dafa",1));
	me->add_temp("apply/armor",me->query_skill("huanri-dafa",1));
	
        me->add("force",-200);
	me->set_temp("exert_huanri",1);
        call_out("cancel_exert",me->query_skill("huanri-dafa",1)/6,me);
	return 1;
}

int cancel_exert(object me)
{
  if(!objectp(me))
  return 1;
  
  me->add_temp("apply/damage",-me->query_skill("huanri-dafa",1));
  me->add_temp("apply/dodge",-me->query_skill("huanri-dafa",1));
  me->add_temp("apply/armor",-me->query_skill("huanri-dafa",1));
  
  message_vision(HIY"$N"+HIY+"长嘘了一口气，脸上的红光慢慢地退去。\n"NOR,me);
  me->delete_temp("exert_huanri",1);
  me->set_temp("exert_huanri_busy",time());
  return 1;
}
