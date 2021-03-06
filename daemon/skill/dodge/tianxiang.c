
#include <ansi.h>
inherit SSERVER;

int perform(object me,object target)
{
  
  int dodge;
  string msg;
 
  if( me->query_skill("jiuying-dodge",1)<150)
  return notify_fail("你的鹫鹰天翔还不到家，无法施展「天翔」！\n");
  if( me->query_skill("dodge",1)<150)
  return notify_fail("你的基本轻功还不到家，无法施展「天翔」！\n");
 
  if(me->query_temp("perform_tianxiang"))
  return notify_fail("你正在使用「天翔」！\n");
  if(time()-me->query_temp("perform_tianxiang_busy")<10)
      return notify_fail("连续施展「天翔」需要深厚的先天真气支持，你修为不够，如何能行？\n");
  if(me->query("force")<200)
  return notify_fail("你的内力不足！\n");
  
  me->add("force",-200);
  
  msg=HIY"\n$N"+HIY+"身形突然灵动起来，宛如天上飞行的鹫鹰一般！\n"NOR;
  
     message_vision(msg,me);
  dodge=me->query_skill("jiuying-dodge",1)/5;
  me->set_temp("perform_tianxiang",1);
  me->add_temp("apply/dodge",dodge);
  
  call_out("perform2",dodge*3/6,me,dodge);
  
  return 1;
}

void perform2(object me,int dodge)
{
   if(!me)
    return;
    
   message_vision("\n$N收回了鹫鹰天翔。\n",me);
   
   me->delete_temp("perform_tianxiang");
   me->add_temp("apply/dodge",-dodge);
   me->set_temp("perform_tianxiang_busy",time());
   
   return;
}
