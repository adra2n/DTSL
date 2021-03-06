//五霸刀法
//三分归一统。
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -100

int perform(object me,object target)
{ 
   object weapon;
   int damage;
   string msg;
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
	   return notify_fail("「三分归一统」只能在战斗中使用！\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="blade")
    return notify_fail("手中无刀，如何使用「三分归一统」？\n");
	if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("wuba-daofa",1))
    return notify_fail("不学五霸刀法如何使用「三分归一统」？\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("blade",1)<160)
    return notify_fail("你的基本刀法太差了！\n");
    if((int)me->query_skill("wuba-daofa",1)<160)
    return notify_fail("你的五霸刀法还不到家！\n");
    if(me->query_skill("jiuxuan-dafa",1)<150)
    return notify_fail("你的九玄大法修为太低了！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展出「三分归一统」！\n");
    
    if(me->query("perform_quest/sanfen")
      &&time()-me->query_temp("perform_busy")<10)
          return notify_fail("连续施展「三分归一统」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/sanfen")
      &&time()-me->query_temp("perform_busy")<5)
          return notify_fail("连续施展「三分归一统」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/sanfen"))
     damage=damage/2;
            
    msg=HIR"$N"+HIR+"缓锾把$w"+HIR+"从鞘内抽出，整个人立生变化，不但神采飞扬，且生出一种宏伟壮阔的气\n"+
        "魄，人与刀结合为一。刀下沉，斜指向上，刀锋颤震，人却如变成不动的磐石，似在非\n"+
        "在，天地人融为一体。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「三分归一统」只能在战斗中使用！\n");
       
    msg=YEL"$N"+YEL+"的$w"+YEL+"似不堪劈击的往左侧震开，人却借劲被刀带得随刀移位，倏忽间远离$n"+YEL+"寻丈，\n"+
        "接着一个急旋，$w"+YEL+"重化金芒，竟以波浪般的线路直搠$n"+YEL+"，退而反进，进退无隙可寻，妙\n"+
        "若天成。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「三分归一统」只能在战斗中使用！\n");
   
    msg=HIY"$N"+HIY+"作波浪前进的$w"+HIY+"变成化身而走的金光，于离$n"+HIY+"半丈近处腾身而起，刀光再变作漫天\n"+
        "金雨，照头照脑往$n"+HIY+"洒下去，一股厉无匹的刀气以惊人的高速横空击去，刀气把$n"+HIY+"完全\n"+
        "锁死笼罩。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「三分归一统」只能在战斗中使用！\n");
    
    if(!me->query("perform_quest/sanfen")){
    	me->set_temp("perform_busy",time());
    	return 1;
    }
    me->set_temp("perform_busy",time());
    call_out("perform2",3,me,target,weapon,damage);
    
    return 1;   
  
}

int perform2(object me,object target,object weapon,int damage)
{ 
        string msg;
        
        if(!me) return 1;
        if(!target||!living(target)){
         me->set_temp("perform_busy",time());
         return 1;
        }
        me->set_temp("perform_busy",time());
        if(!weapon||me->query_temp("weapon")!=weapon)
        return 1;
        if(me->is_busy())
        return 1;
  
        if(!me->is_fighting(target))
	   return 1;
	   
    msg=HIG"$N"+HIG+"摆出架势，左手鞘盾牌般斜护胸口，右手横$w"+HIG+"高举过头，坐马沉腰，凛冽的劲气，\n"+
        "狂风似的往两丈外的$n"+HIG+"追去，此守式名为封天闭地，无隙可入。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「三分归一统」只能在战斗中使用！\n");
    
    msg=MAG"$N"+MAG+"厉叱一声，左手鞘凝起十成真劲，人往横移，往$n"+MAG+"破空袭至，横在头顶的$w"+MAG+"疾\n"+
        "劈而下，气浪滚动，就若大海的水往两旁墙立而起，现出水底的通行之路，直去$n"+MAG+"。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
   
    me->set_temp("perform_busy",time());
    return 1;   
  
}
