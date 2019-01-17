
#include <ansi.h>
inherit ROOM;
int do_pa(string arg);
void create ()
{
  set ("short",HIB"半山腰"NOR);
  set ("long", @LONG
这里是山崖的半山腰。这里能爬的方向似乎有上「up」、左
「left」、右「right」。
LONG);
  set("valid_startroom", 1);
  set("no_fight",1);
  setup();
 
}
void init()
{
   add_action("do_pa","climb");
}
int do_pa(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||
  (arg!="up"&&arg!="left"&&arg!="right"))
  return notify_fail("你只能往上[up]、左[left],右[right]爬！\n");
  ob->set_temp("climb_trace2",arg);
  if(ob->is_busy())
  return notify_fail("你正忙着呢。\n");
  message_vision(YEL"$N手攀着悬崖的边缘，爬了上去！\n"NOR,ob);
  ob->move(__DIR__"yadi3");
  return 1;
}
