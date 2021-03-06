//魔影
//by rzy 02.09.23
//modify by yanyan 2003.11.14

#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
	int i;
	int last_time;
	object weapon;
	weapon=me->query_temp("weapon");
	
	if(!me->is_fighting(target))
		return notify_fail("「鬼魅魔影」要在战斗中施展！\n");
	if(!weapon || weapon->query("skill_type")!="whip")
		return notify_fail("手中没有鞭子，如何施展「鬼魅魔影」？\n");
	if(weapon->query("flag")==1)
        	return notify_fail("断掉的兵器不能再使用了！\n");
	if(me->query_temp("perform_moying"))
		return notify_fail("你正在使用「鬼魅魔影」。\n");
	if(!me->query_skill("tianmo-dai",1))
		return notify_fail("你还没有学会「天魔带」！\n");
	if((int)me->query_skill("tianmo-dafa",1)<110)
		return notify_fail("你的「天魔大法」还不到家！\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("你的内力修为太低了!\n");
	if((int)me->query("force")<500)
		return notify_fail("你目前的内力状况太差了！\n");
	if((int)me->query_skill("tianmo-dai",1)<110)
		return notify_fail("你的「天魔带」太差了！\n");
	if((int)me->query_skill("whip",1)<120)
		return notify_fail("你的基本鞭法还不到家！\n");
	if(time()-me->query_temp("perform_busy_moying")<10)
		return notify_fail("你刚施用过「鬼魅魔影」，真气尚未平复！\n");
	
	message_vision(HIB"\n$N"+HIB+"一挥手中的"+weapon->name()+HIB+"，手腕用力一旋，"+weapon->name()+HIB+"犹如灵蛇一般旋转起来，\n"+
                   "$N"+HIB+"的身形逐渐加快，让人琢磨不定。\n"NOR,me);
	i=me->query_skill("tianmo-dai",1)/3;
	me->add_temp("apply/dodge",i);
	me->set_temp("perform_moying",1);
	me->set_temp("perform_busy",time()-7);//防止立刻施展其他威力大pfm
	me->add("force",-200);
    
    last_time=me->query_skill("tianmo-dai",1)/3;
    if(last_time>=70) last_time=70;
    
	call_out("rid_defence",last_time,me,i);
	return 1;   
  }  
 
void rid_defence(object me,int i)
{
	if(!me) return;
	message_vision(HIB"\n$N"+HIB+"冷笑了一声，身形逐渐慢了下来。\n"NOR,me);
	me->add_temp("apply/dodge",-i);
	me->delete_temp("perform_moying");
	me->set_temp("perform_busy_moying",time());
	return;
}