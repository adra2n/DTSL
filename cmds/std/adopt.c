//for dtsl.
#include <ansi.h>

inherit F_CLEAN_UP;


int main(object me, string arg)
{
   object ob;
   if(!arg) return notify_fail("你想接受谁加入势力？\n");
   if(!objectp(ob=present(arg,environment(me))))
    return notify_fail("这里没有这个人。\n");
   if(!userp(ob))
       return notify_fail("你还是吸收玩家加入势力吧！\n");
   if(!me->query("shili/leader"))
       return notify_fail("你不是势力的首领，歇着吧！\n");
   if(ob->query("shili/leader"))
     return notify_fail("他是一个势力的首领，你敢要吗？！\n");
   if(me->query_temp("mark_join")!=ob->name())
    return notify_fail("这个人并没有要求加入你们的势力！\n");
    ob->set_temp("mark_join",me->query("shili/name"));
   message_vision("$N决定吸收$n加入自己的势力！\n",me,ob);
   CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s决定吸收%s加入自己的势力！", me->name(),ob->name()));
   me->delete_temp("mark_join");
   tell_object(ob,HIG"\n请去势力名单榜处打 "+HIY+"join"+HIG+" 命令就可以正式加入了！\n\n"NOR);
   return 1;
}
