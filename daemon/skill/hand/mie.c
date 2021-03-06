//玲珑玉拳：玲珑灭神。
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50

int perform(object me,object target)
{ 
   object weapon;
   string msg;
   int damage;
   
    weapon=me->query_temp("weapon");
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
	if(!me->is_fighting())
		return notify_fail("「玲珑灭神」只能在战斗中使用!\n");
   if(weapon)
    return notify_fail("拿着武器，如何使用「玲珑灭神」？\n");
    if(!me->query_skill("linglong-yuquan",1))
    return notify_fail("不学「玲珑玉拳」如何使用「玲珑灭神」？\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("cuff",1)<110)
    return notify_fail("你的基本拳法太差了！\n");
    if((int)me->query_skill("linglong-yuquan",1)<110)
    return notify_fail("你的「玲珑玉拳」还不到家！\n");
    if((int)me->query_skill("tianmo-dafa",1)<100)
    return notify_fail("你的「天魔大法」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「玲珑灭神」！\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("连续施展「玲珑灭神」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points")/2;
    
    msg=HIC"$N"+HIC+"身法轻盈，拳法忽快忽慢，曼妙的姿态宛如含羞少女，但同时又以\n"+
        "狠辣的招数朝$n"+HIC+"的$l处打去！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「玲珑灭神」只能在战斗中使用!\n");
    
    msg=HIY"$N"+HIY+"唇角逸出一丝笑意，无数的拳影把$n"+HIY+"紧紧锁紧，似攻似守，逢隙必入的攻来，\n"+
        "倏地$n"+HIY+"身前现出漫空星点，每一点都似乎在向他攻来，又每一点都像、水恒不动，\n"+
        "有如天上的星空，在变化周移中自具恒常不变的味道！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「玲珑灭神」只能在战斗中使用!\n");
    
    msg=HIG"$N"+HIG+"由快转缓，还今人难以置信的旋转起来，双拳似乎织成完美无瑕的圆网，\n"+
        "把$n"+HIG+"紧裹其中，顿使$n"+HIG+"生出不知该攻何处的无奈感觉。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
        me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
