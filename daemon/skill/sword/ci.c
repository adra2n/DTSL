//幻影突刺。

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 100 //!!!提高命中

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int flag=0,damage;
    
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
	   return notify_fail("「幻影突刺」只能在战斗中使用!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("手中无剑，如何使用「幻影突刺」？\n");
    if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("yingzi-jianfa"))
    return notify_fail("不学「影子剑法」如何使用「幻影突刺」？\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("sword",1)<110)
    return notify_fail("你的基本剑法太差了！\n");
    if((int)me->query_skill("yingzi-jianfa",1)<110)
    return notify_fail("你的「影子剑法」还不到家！\n");
    if((int)me->query_skill("dodge",1)<100)
    return notify_fail("你的「基本轻功」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「幻影突刺」！\n");
    
    if(me->query("vocation")!="杀手")
    return notify_fail("只有杀手才能施展「幻影突刺」！\n");
    
    if(me->query("job_office_number/杀手任务")>=1000)
     flag=1;
    
    if(flag
      &&time()-me->query_temp("perform_busy")<7)
       return notify_fail("连续施展「幻影突刺」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!flag
      &&time()-me->query_temp("perform_busy")<3)
       return notify_fail("连续施展「幻影突刺」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    if(flag) damage=me->query("apply_points");
    else
    damage=me->query("apply_points")/2;
    
    msg=HIB"$n"+HIB+"整个人已陷进一种近乎无可抗拒的劲漩里。那是千百股奇怪的力道，部分把$n"+HIB+"扯前，部\n"+
        "分却直压而来，还有几股横向和旋转的力道。就像掉进下了大海怒涛汹涌的漩涡中，使人\n"+
        "难有自主把持的能力。\n"NOR;    
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
  
    if(!me->is_fighting())
    return notify_fail("「幻影突刺」只能在战斗中使用!\n");
    
    msg=HIB"$n"+HIB+"想也不想，立刻聚集了全身功力，俯身坐马，同时往来人反攻和瞧去。 一时间，$n"+HIB+"只\n"+
        "能见到一个黑影子。一点剑芒，正在$n"+HIB+"眼前扩大。无坚不摧的剑气，透过长剑侵来，使\n"+
        "$n"+HIB+"呼吸顿止，全身有若刀割。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「幻影突刺」只能在战斗中使用!\n");
    
    msg=BLU"$n"+BLU+"眼前仍有点点剑芒，不断炫闪，使$n"+BLU+"睁目如盲，只能纯凭感觉作出反应。摹地剑芒剧\n"+
        "盛，四面八方尽是呼啸的剑影芒光，虚实难测。$n"+BLU+"感到敌剑生出一股粘贴之力，对方的\n"+
        "长剑像毒蛇般附着$n"+BLU+"的周围，搠向$n"+BLU+"的$l！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
   
   me->set_temp("perform_busy",time());
    return 1;   
  
}  

