//天魔气场。
#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int exert(object me, object target)
{
	object *ob;
	int ap,dp,i;
	string msg;
	
	if(target==me)
			return notify_fail("「天魔气场」只能用来攻击别人！\n");
	if(!me->is_fighting())
	return notify_fail("「天魔气场」只能在战斗中使用！\n");
	if(!living(target))
		return notify_fail("那不是个活物耶！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(!me->query_skill("tianmo-dafa",1))
		return notify_fail("不学天魔大法如何使用「天魔气场」？\n");
	if((int)me->query_skill("tianmo-dafa",1)<120)
		return notify_fail("你的天魔大法修为不够！\n");
	if((int)me->query_skill("force",1)<120)
        return notify_fail("你的基本内功修为不够！\n");
        
        if(time()-me->query_temp("exert_busy/tianmo")<10)
          return notify_fail("连续施展「天魔气场」需要深厚的先天真气支持，你修为不够，如何能行？\n");
	
	msg=HIB"\n围着$N"+HIB+"的众人都生出要向前倾跌的可怕感觉。$N天魔功在刹那间提升至极限，\n"+
	       "周围的空气似是给一下子抽乾了，周围方圆两丈许的空间忽然凹陷下去成了一\n"+
	       "个无底深洞。\n\n"NOR;
	message_vision(msg,me);
	ob=all_inventory(environment(me));
	
	for(i=0;i<sizeof(ob);i++){
	 if(!living(ob[i])) continue;
	 if(ob[i]==me) continue;
	 if(!me->is_fighting(ob[i])) continue;
         ap=me->query_skill("force",1)+me->query("apply_points");
         dp=ob[i]->query_skill("force",1)+ob[i]->query("apply_points");
        
          if(random(ap+dp)>dp){
           tell_object(ob[i],HIY"你身陷在天魔气场中，气势不由得迅速降低！\n"NOR);
           ob[i]->set("apply_points",ob[i]->query("apply_points")/10);
          }
          else
          message_vision("\n$N见势不妙，急忙从气场中争脱而出！\n",ob[i]);
        }
        
        me->set_temp("exert_busy/tianmo",time());//yun tianmo 要有间隔时间
        me->set_temp("perform_busy",time());//使用后，不能立即使用 perform
        
        return 1;
}
