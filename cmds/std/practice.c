
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string skillname,base,type;
   int skill, skill_basic,sen;int cost;

   if(!arg||sscanf(arg,"%s for %d",arg,cost)!=2)
   return notify_fail("请使用practice|lian 技能 for 次数。\n");
   if(cost<=0)
   return notify_fail("次数必须大于零！\n");
   if(cost>=1000)
   return notify_fail("你还是珍惜一下自己的身体吧！\n");
   if(environment(me)->query("no_fight"))
   return notify_fail("这里禁止练习武功！\n");
   if(me->is_busy())
   return notify_fail("你正忙着呢！\n");
   if( me->is_fighting() )
     return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");
   if(!me->query_skill(arg,1)) return notify_fail("你并没有学这种技能!\n");
   type=SKILL_D(arg)->query_type();
   if(type&&(type=="knowledge"||type=="base"))
   return notify_fail("这个技能不能练习！\n");
   skill=(int)me->query_skill(arg,1);
   base=SKILL_D(arg)->query_base();
   skill_basic=(int)me->query_skill(base,1);
   if(!skill_basic)
   return notify_fail("你还是先学学基本功夫吧！\n");
if((skill_basic)<skill)
	   return notify_fail("你还是先把基本功夫学好再练习吧!\n");
   if((int)me->query("sen",1)<20)
	   return notify_fail("你现在的精神不是很好,不能练习!\n");
   if((int)me->query("sen",1)<cost*20)
	   return notify_fail("你现在的精神不足以进行这种强度的练习!\n");
   if(type=="hand")
   if(me->query("force")<=10*cost)
    return notify_fail("你的内力太低了！\n");
   skillname=to_chinese(arg);
   if(SKILL_D(arg)->practice_skill(me))
   {
           me->add("sen",-cost*20);
           if(type=="hand")
           me->add("force",-10*cost);
           me->improve_skill(arg,(skill/5+skill_basic/2+random(20))*cost);
	   message_vision("$N用心地练起"+skillname+"来\n",me);
	   return 1;
   }
   else (int)SKILL_D(arg)->practice_skill(me);
   
   
}

int help(object me)
{
   write(@TEXT
指令格式：practice <技能种类>

这个指令让你练习某个种类的技能.
用法： lian(practice) 武功，如 lian tianmo-jianfa
如果你该项的基本技能足够高，可以经由练习直接升级，而且升级的上限只跟
你基本技能的等级有关，换句话说，勤加练习是使你的所学「青出于蓝胜于蓝」
的唯一途径，当然，在这之前你必须从实际运用中获得足够的经验以提升你的基
本技能。
TEXT
   );
   return 1;
}
