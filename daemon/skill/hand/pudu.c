//如来神掌
//普渡众生。

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
    return notify_fail("「普渡众生」只能在战斗中使用!\n");
    if(weapon)
    return notify_fail("拿着武器，如何使用「普渡众生」？\n");
    if(me->query("PKS")>=5)
        return notify_fail("你罪孽深重，无法使用此绝技了！");
    if(!me->query_skill("rulai-shenzhang",1))
    return notify_fail("不学「如来神掌」如何使用「普渡众生」？\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("你的内力修为太低了!\n");
    if((int)me->query_skill("strike",1)<110)
    return notify_fail("你的基本掌法太差了！\n");
    if((int)me->query_skill("rulai-shenzhang",1)<110)
    return notify_fail("你的「如来神掌」还不到家！\n");
    if((int)me->query_skill("wuxiang-shengong",1)<100)
    return notify_fail("你的「无相神功」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「普渡众生」！\n");
    if(me->query("perform_quest/pudu")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("连续施展「普渡众生」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/pudu")
      &&time()-me->query_temp("perform_busy")<5)
      return notify_fail("连续施展「普渡众生」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/pudu"))
    	damage=damage/2;
    else
    	damage += damage/4;
    
    msg=HIY"$n"+HIY+"眼前一花，一对巨掌迎面推来，看似没有任何招式花巧，甚至没带起半分劲气狂风，\n"+
        "可是$N"+HIY+"已达到大巧若拙的至境，无论$n"+HIY+"作何闪躲退避，似仍逃不出佛掌的笼罩。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「普渡众生」只能在战斗中使用!\n");
    
    msg=YEL"$N"+YEL+"两袖一挥，双掌从袖内探出，凌空虚抓，登时生出一股吸扯之力，$n"+YEL+"立刻生出一种无\n"+
        "从着力的感觉，最要命处就是这一招发出的气势劲道，产生出庞大无匹的压力，把他的\n"+
        "感官完全笼罩其中，连肌肤也如被针刺，失去往常的灵锐。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「普渡众生」只能在战斗中使用！\n");
    
    msg=MAG"$N"+MAG+"全身纹风不动，连衣袂亦没有扬起分毫，忽然右手从上登变为平伸，身体则像一根\n"+
        "木柱般前后左右的摇晃，右手再在胸前比划，掌形逐渐变化，拇指外弯，其他手指靠\n"+
        "贴伸直，到手掌推进至尽，刚好一分不差的朝$n"+MAG+"的$l处拍去！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「普渡众生」只能在战斗中使用！\n");
    
    if(!me->query("perform_quest/pudu")){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    msg=HIG"$N"+HIG+"每个动作均慢条斯理，让人看得清清楚楚，可是$N"+HIG+"的“慢”，却刚好使$n"+HIG+"难以进行反击，\n"+
        "$n"+HIG+"大吃一惊，佛门玄功，确是惊世骇俗！\n"NOR;
    
    damage += damage/2;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
