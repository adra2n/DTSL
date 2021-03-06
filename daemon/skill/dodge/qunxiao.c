//游龙身法
//群啸。


#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int perform(object me,object target)
{
       object *t;
       int i,fight_flag=0,damage;
  		
	if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
	
	if(!me->is_team_leader())
	return notify_fail("你不是队伍的首领，无法施展「群啸」！\n");
	
	if(!me->is_fighting())
	return notify_fail("「群啸」只能在战斗中使用！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(!me->query_skill("youlong-shenfa",1))
		return notify_fail("不学游龙身法如何使用「群啸」？\n");
	if((int)me->query_skill("youlong-shenfa",1)<100)
		return notify_fail("你的游龙身法修为不够！\n");
	if((int)me->query_skill("dodge",1)<100)
		return notify_fail("你的基本轻功修为不够！\n");
	if(me->query("apply_points")<=0)
	return notify_fail("你的气势不足以使用「群啸」！\n");
	
	if(time()-me->query_temp("form_busy")<15)
      return notify_fail("连续施展「群啸」需要深厚的先天真气支持，你修为不够，如何能行？\n");
        
        t=me->query_team();
        t=t-({0});
        if(sizeof(t)<2) return notify_fail("要施展「群啸」必须至少两个人！\n");
        
        for(i=0;i<sizeof(t);i++)
         if(objectp(t[i])){
         if(environment(t[i])!=environment(me))
         return notify_fail("有人不和你站在一起！\n");
         if(t[i]->query_skill("youlong-shenfa",1)<100)
         return notify_fail(t[i]->name()+"游龙身法修为太低了！\n");
       }
       
       if(me->is_killing(target->query("id")))
       fight_flag=1;
       message_vision(HIR"\n$N"+HIR+"一声长啸：「布阵」！四下啸声阵阵，令人胆寒！\n"NOR,me);
       
       for(i=0;i<sizeof(t);i++){
         if(!t[i]->is_fighting(target)){
           if(fight_flag) {t[i]->kill_ob(target);target->kill_ob(t[i]);}
           else {t[i]->fight_ob(target);target->fight_ob(t[i]);}
         }
        t[i]->set_temp("form_busy",time());
        damage=t[i]->query("apply_points");
        t[i]->add_temp("apply/damage",damage);
        COMBAT_D->do_attack(t[i],target,t[i]->query_temp("weapon"),0,2);
        t[i]->add_temp("apply/damage",-damage);
      }
        me->set_temp("form_busy",time());
        return 1;
}

