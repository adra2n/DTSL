//天刀八诀。
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 80

int perform(object me,object target)
{ 
   object weapon;
   int damage,flag;
   string msg;
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
	   return notify_fail("「天刀八诀」只能在战斗中使用！\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="blade")
    return notify_fail("手中无刀，如何使用「天刀八诀」？\n");
	if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("tiandao-bajue"))
    return notify_fail("不学宋家的刀法如何使用「天刀八诀」？\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("blade",1)<110)
    return notify_fail("你的基本刀法太差了！\n");
    if((int)me->query_skill("tiandao-bajue",1)<110)
    return notify_fail("你的天刀八诀还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展出「天刀八诀」！\n");
    
    if(me->query("perform_quest/bajue")
      &&time()-me->query_temp("perform_busy")<8)
          return notify_fail("连续施展「天刀八诀」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(me->query("perform_quest/bajue_fail")
      &&time()-me->query_temp("perform_busy")<4)
          return notify_fail("连续施展「天刀八诀」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/bajue")
      &&time()-me->query_temp("perform_busy")<3)
          return notify_fail("连续施展「天刀八诀」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    
    if(me->query("perform_quest/bajue_fail")){
      damage=damage*3/4;
      flag=0;
    }
    else
    if(!me->query("perform_quest/bajue")){
     damage=damage/2;
     flag=0;
    }else flag=1;
    
    if(!flag)
    msg=HIC"$N"+HIC+"一招「天风环佩」砍向$n"+HIC+"的$l处！仿佛天仙在云端乘风来去，虽不能看到，却有环佩\n"+
        "铿锵的仙乐清音！\n"NOR;
    else
    msg=HIC"$w"+HIC+"划上虚空，刀光闪闪，天地的生机死气全集中到刀锋处，天上星月立即黯然失色。这\n"+
        "感觉奇怪诡异至极点，难以解释，不能形容。只见$w"+HIC+"破空而去，横过两丈空间，直击$n"+HIC+"，\n"+
        "却没带起任何破风声，不觉半点刀气，可是$n"+HIC+"却清楚把握到$N"+HIC+"的$w"+HIC+"笼天罩地，除硬拼一途\n"+
        "外，再无另一选择。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「天刀八诀」只能在战斗中使用！\n");
    
    if(me->query_skill("tiandao-bajue",1)<130){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("你的刀法修为不足，目前只能出一招天刀！\n");
    }
    
    if(!flag)
    msg=HIG"$N"+HIG+"一招「潇湘水云」砍向$n"+HIG+"的左臂！手中$w"+HIG+"化做十刀，却如霞雾缭绕，隐见水光云影，流\n"+
        "转不尽，意态无穷。\n"NOR;
    else
    msg=HIG"$N"+HIG+"的身躯忽的重现$n"+HIG+"眼前，$w"+HIG+"像活过来般自具灵觉的寻找对手，绕一个充满线条美合乎天\n"+
        "地之理的大弯，往$n"+HIG+"的$l刺去，而$N"+HIG+"的躯体完全由$w"+HIG+"带动，既自然流畅，\n"+
        "又若鸟飞鱼游，浑然无瑕，精采绝伦。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    
    if(!me->is_fighting())
    return notify_fail("「天刀八诀」只能在战斗中使用！\n");
    
    if(me->query_skill("tiandao-bajue",1)<150){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("你的刀法修为不足，目前只能出两招天刀！\n");
    }
    
    if(!flag)
    msg=HIG"$N"+HIG+"似水流不断的刀式，蓦地化作一道碧光冶冶、穿岩漱石的清泉活水，手中$w"+HIG+"划出\n"+
        "一道光芒，循某一条优美至超乎任何言语所能形容的弧度，直取$n"+HIG+"，正是「石上流泉」！\n"NOR;
    else
    msg=HIG"$N"+HIG+"刀势变化，紧褁全身，有若金光流转，教人无法把握天刀下一刻的位置。身形似进\n"+
        "非进，似退非退，确是无懈可击的刀法。只听“噗”双方一触即开，$n"+HIG+"被迫风车般旋转，\n"+
        "才能化去$N"+HIG+"无坚不摧的气劲，先机顿失。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「天刀八诀」只能在战斗中使用！\n");
    
    if(me->query_skill("tiandao-bajue",1)<170){
    	me->set_temp("perform_busy",time());
        return notify_fail("你的刀法修为不足，目前只能出三招天刀！\n");
    }
    
    
    if(!flag)
    msg=YEL"$N"+YEL+"整个人旋动起来，一招「梧叶舞秋风」直取$n"+YEL+"的$l！$w"+YEL+"似是随意出击，全无痕迹刀\n"+
        "路可寻，更因其怪异的身法，$n"+YEL+"的攻势立时冰消瓦解。\n"NOR;
    else
    msg=YEL"$N"+YEL+"的$w"+YEL+"每一部分均变成制敌化敌的工具，至乎任何令人想也没想过的方式，\n"+
        "应付$n"+YEL+"发动的攻击。只见$N"+YEL+"追逐无定，以惊人高速闪挪腾移，但$N"+YEL+"的姿态\n"+
        "仍是那么不合乎战况的从容大度，其紧凑激厉处又隐含逍遥飘逸的意味，精采至难以任何\n"+
        "语言笔墨可作形隐含逍遥飘逸的意味。\n"NOR;
	
	COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
	    
    if(!me->is_fighting())
    return notify_fail("「天刀八诀」只能在战斗中使用！\n");
    
    if(me->query_skill("tiandao-bajue",1)<190){
    	me->set_temp("perform_busy",time());
        return notify_fail("你的刀法修为不足，目前只能出四招天刀！\n");
    }
    
    msg=HIY"\n只听唰的一声，$N"+HIY+"竟收回手中的"+weapon->query("name")+HIY+"，面手下垂，自然而然生出一股庞大无匹的气势紧罩$n"+HIY+"！\n"NOR;
    message_vision(msg,me,target);
    
    if(!flag){
    	me->set_temp("perform_busy",time());
    	return 1;
    }
    me->set_temp("perform_busy",time());
    call_out("perform2",4,me,target,weapon,damage);
    
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
	   
    msg=HIR"只听唰的一声，$w"+HIR+"出手了！一切只能以一个快字去形容，发生在肉眼难看清楚的高速下，\n"+
        "$n"+HIR+"感到$N"+HIR+"出手时，$w"+HIR+"早已挥出，化作闪电般的长虹，划过两丈的虚空劈向自己。$n"+HIR+"只感到\n"+
        "周遭所有的气流和生气都似被$N"+HIR+"这惊天动地的一招吸个一丝不剩，一派生机尽绝，死亡和\n"+
        "肃杀的骇人味儿。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「天刀八诀」只能在战斗中使用！\n");
    
    if(me->query_skill("tiandao-bajue",1)<210){
    	me->set_temp("perform_busy",time());
        return notify_fail("你的刀法修为不足，目前只能出五招天刀！\n");
    }
    
    msg=WHT"$N"+WHT+"一个回旋，$w"+WHT+"平平无奇地再往迎回来的$n"+WHT+"横扫。这第六刀并不觉有任何不凡处，但却慢至\n"+
        "不合常理。$n"+WHT+"却清楚掌握到$N"+WHT+"此招寓快于慢，大巧若拙，虽不见任何变化，但千变万化尽在\n"+
        "其中，如天地之无穷，宇宙般没有尽极。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「天刀八诀」只能在战斗中使用！\n");
    
    if(me->query_skill("tiandao-bajue",1)<230){
    	me->set_temp("perform_busy",time());
        return notify_fail("你的刀法修为不足，目前只能出六招天刀！\n");
    }
    
    msg=WHT"$N"+WHT+"的$w"+WHT+"悄然探出，变化中突然收劲，$n"+WHT+"一时不查，身形顿时被$N"+WHT+"的$w"+WHT+"吸住，\n"+
        "只听$N"+WHT+"一声长笑，$w"+WHT+"从$n"+WHT+"双掌间拔起，直至头顶上方笔直指向夜空的位置闪电下劈。任$n"+WHT+"\n"+
        "有通天砌地之能，在如此情况下，势难挡格$N"+WHT+"此招。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「天刀八诀」只能在战斗中使用！\n");
    
    if(me->query_skill("tiandao-bajue",1)<250){
    	me->set_temp("perform_busy",time());
        return notify_fail("你的刀法修为不足，目前只能出七招天刀！\n");
    }
    
    msg=HIG"$N"+HIG+"的$w"+HIG+"来至与地面平行的当儿，修地全速冲刺，直往前方三丈外的$n"+HIG+"箭矢般激射而去。只见\n"+
        "$w"+HIG+"笔直激射，迅速拉近与$n"+HIG+"的距离，刀气把对手完全锁紧笼罩，当$n"+HIG+"触地的一刻，\n"+
        "恰是$w"+HIG+"临身的刹那。"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    me->set("apply_points",0);
    me->set_temp("perform_busy",time());
    return 1;   
  
}
