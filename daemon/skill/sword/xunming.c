//魅影寻命
//by rzy 2002.11.11

#include <ansi.h>

inherit SSERVER;


int perform(object me,object target)
{
    object weapon;
    string msg;
    int flag=0,damage;

    if(!target)
    if(!objectp(target=offensive_target(me)))
        return notify_fail("目前你没有攻击的目标！\n");
    if(!me->is_fighting())
        return notify_fail("「魅影寻命」只能在战斗中使用!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
        return notify_fail("手中无剑，如何使用「魅影寻命」？\n");
    if(weapon->query("flag")==1)
        return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("yingzi-jianfa",1))
        return notify_fail("不学「影子剑法」如何使用「魅影寻命」？\n");
    if((int)me->query("max_force",1)<3000)
        return notify_fail("你的内力太低了!\n");
    if((int)me->query("PKS")<1)
        return notify_fail("你没有背负人命，无法使出如此狠辣的招数！\n");
    if((int)me->query_skill("sword",1)<220)
        return notify_fail("你的基本剑法太差了！\n");
    //if((int)me->query("bellicosity")<5000)
    //    return notify_fail("你的杀气太轻，无法使出如此狠辣的招数！\n");
    //测试时发现好象死了杀气就清零,所以先不考虑限制这个了。
    if((int)me->query_skill("yingzi-jianfa",1)<220)
        return notify_fail("你的「影子剑法」还不到家！\n");
    if((int)me->query_skill("dodge",1)<220)
        return notify_fail("你的「基本轻功」还不到家！\n");
    if((int)me->query("kee")>(me->query("max_kee")*99/100))
        return notify_fail("你没有受伤，无法施展「魅影寻命」！\n");
    if(me->query("apply_points")<me->query("max_apply_points")/2)
        return notify_fail("凭你目前的气势无法施展「魅影寻命」！\n");

    if(me->query("vocation")!="杀手")
    return notify_fail("只有杀手才能施展「魅影寻命」！\n");

     if(me->query("job_office_number/杀手任务")>=500 && me->query("vocation_score")>100)
    flag=1;
    
    if(flag
      &&time()-me->query_temp("perform_busy")<16)
       return notify_fail("连续施展「魅影寻命」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!flag
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("连续施展「魅影寻命」需要深厚的先天真气支持，你修为不够，如何能行？\n");

    if(flag)
    damage=me->query("apply_points")+(me->query("max_kee")-me->query("kee"))/10;
    else
    damage=(me->query("max_kee")-me->query("kee"))/10;

    msg=BLU"$N"+BLU+"激起潜力，身形加快，化做数个影子从各个方向攻向$n"+BLU+"要害，\n瞬间正反两种力道"+
        "激荡起重重气旋！\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");

    if(!me->is_fighting())
    return notify_fail("「魅影寻命」只能在战斗中使用!\n");

    if(me->query("kee")>me->query("max_kee")*95/100){
    me->set_temp("perform_busy",time()-2);
    return notify_fail("你目前的伤势只能激发你的潜能发一招！\n");
    }

    msg=BLU"气旋中$N"+BLU+"身法再次加快，一时间前后左右尽是$N"+BLU+"的身影，漫天剑影中不辨真身，\n凛冽的剑气使$n"+BLU+"呼吸"+
        "停止，全身有若被割裂般痛楚！\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");

    if(!me->is_fighting())
    return notify_fail("「魅影寻命」只能在战斗中使用!\n");

    if(me->query("kee")>me->query("max_kee")*80/100){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("你目前的伤势只能激发你的潜能发两招！\n");
    }
    msg=BLU"$n"+BLU+"只觉压力不断增大，呼啸的劲力卷起尘土遮天闭日，$N"+BLU+"犹如鬼魅让人无法捕捉位置，\n$n"+BLU+"睁目如"+
        "盲，任凭剑影从各个方向攻来，竟连招架躲避都无从下手！\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");

    if(!me->is_fighting())
    return notify_fail("「魅影寻命」只能在战斗中使用!\n");

    if(me->query("kee")>me->query("max_kee")*65/100){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("你目前的伤势只能激发你的潜能发三招！\n");
    }
    msg=HIB"$N"+HIB+"伤势发作，激起更大潜力，竟能突破自身境界，在高速度中射出有若实质\n般的剑气，狭窄空间再次暴起"+
        "无边的战气，另$n"+HIB+"心胆俱寒，无法发挥自身的力量！\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");

    if(!me->is_fighting())
    return notify_fail("「魅影寻命」只能在战斗中使用!\n");

    if(me->query("kee")>me->query("max_kee")*45/100){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("你目前的伤势只能激发你的潜能发四招！\n");
    }
    else if(me->query_skill("yingzi-jianfa",1)<300) {
        me->set_temp("perform_busy",time()-2);
        return notify_fail("你的剑法修为只能发出四招！\n");
    }
    
    if(flag) {
	    message_vision(HIG"\n$N"+HIG+"招式急变，一反影子剑法琢磨不定仿佛鬼魅的路数，在内伤逼迫下再次提升自身潜力，\n"+
	                      "以全身内力灌注剑身，激出一道剑气，"+weapon->query("name")+HIG+"化为精虹紧随其后攻向$n"+HIG+"，\n"+
	                      "竟比先前射出的剑气更快了一层！\n"NOR,me,target);
            me->add_temp("apply/damage",damage);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            me->add_temp("apply/damage",-damage);
            
            if(!me->is_fighting())
            return notify_fail("「魅影寻命」只能在战斗中使用!\n");
    
            if(me->query("kee")>me->query("max_kee")*15/100){
            me->set_temp("perform_busy",time()-2);
            return notify_fail("你目前的伤势只能激发你的潜能出五招！\n");
            }

    }
    if(!flag) {
    
            msg=HIG"\n$N"+HIG+"招式急变，一反影子剑法琢磨不定仿佛鬼魅的路数，在内伤逼迫下再次提升自身潜力，\n"+
                   "以全身内力灌注剑身，手中"+weapon->query("name")+HIG+"化为精虹攻向$n"+HIG+"，竟带起风雷之声！\n"NOR;
            me->set_temp("action_msg",msg);
            me->add_temp("apply/damage",damage);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            me->add_temp("apply/damage",-damage);
            me->delete_temp("action_msg");
            
            if(!me->is_fighting())
            return notify_fail("「魅影寻命」只能在战斗中使用!\n");
    
            if(me->query("kee")>me->query("max_kee")*15/100){
            me->set_temp("perform_busy",time()-2);
            return notify_fail("你目前的伤势只能激发你的潜能出五招！\n");
            }
    
    }

    if(flag) {
    	if(random(100)==1) {
            damage=damage*10;
            msg=RED"$N"+RED+"重伤之下心灵一片明净，剑法忽然攀升到至高境界，手中"+weapon->query("name")+RED+"发出细微至无法察觉的抖动，\n"+
                   "$N"+RED+"抬手撒出一团剑光，光芒过后$N"+RED+"仍是一个身影，却出现了无数的"+weapon->query("name")+RED+"，如此化剑为\n"+
                   "影的招数纵使神鬼也万难躲避！\n"NOR;
                me->set_temp("action_msg",msg);
                me->add_temp("apply/damage",damage);
                COMBAT_D->do_attack(me,target,weapon,0,2);
                me->add_temp("apply/damage",-damage);
                me->delete_temp("action_msg");
                
                if(!me->is_fighting())
       		return notify_fail("「魅影寻命」只能在战斗中使用!\n"); 
        }
        else {
    	    message_vision(RED"\n$N"+RED+"重伤之下心灵一片明净，剑法忽然攀升到至高境界，手中"+weapon->query("name")+RED+"发出细微至无法察觉的抖动，\n"+
    	                      "$N"+RED+"抬手撒出一团剑光，光芒中两道有形剑气高速射出，"+weapon->query("name")+RED+"化做长虹紧随而至，一切动作宛若\n"+
    	                      "天成，无懈可击！\n"NOR,me,target);
            me->add_temp("apply/damage",damage);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            me->add_temp("apply/damage",-damage);
            
            if(!me->is_fighting())
	    return notify_fail("「魅影寻命」只能在战斗中使用!\n"); 
        }
     }
       
     if(!flag) {   
     	
            msg=RED"$N"+RED+"重伤之下心灵一片明净，剑法忽然攀升到至高境界，手中"+weapon->query("name")+RED+"发出细微至无法察觉的抖动，\n"+
                   "$N"+RED+"抬手撒出一团剑光，光芒中$N"+RED+"人剑合一，以难以想象的高速度攻向$n"+RED+"！\n"NOR;
                me->set_temp("action_msg",msg);
                me->add_temp("apply/damage",damage);
                COMBAT_D->do_attack(me,target,weapon,0,2);
                me->add_temp("apply/damage",-damage);
                me->delete_temp("action_msg");
       
       		if(!me->is_fighting())
       		return notify_fail("「魅影寻命」只能在战斗中使用!\n");    	
       
       }
    
    if(!me->is_fighting())
       return notify_fail("「魅影寻命」只能在战斗中使用!\n");    

    me->set_temp("perform_busy",time());
    return 1;

}
