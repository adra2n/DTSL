
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int times)
{
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	  me->set_temp("death_msg","中了毒龙散死了！\n");
   }
   else {
      tell_object(me, HIB "突然你全身一阵抖动，看来是中了阴癸派的[毒龙散]！\n" NOR );
      message("vision", me->name() + "身子晃了晃，有些站不稳了。\n",
            environment(me), me);
	   me->start_busy(2);
   }
      me->receive_damage("kee", 25);
      me->receive_wound("gin", 10);
      me->apply_condition("dulongsan", times - 1);
   if( times < 1 ) return 0;
   return CND_CONTINUE;
}
