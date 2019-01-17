
#include <ansi.h>
inherit ROOM;

int do_jump(string arg);
void create ()
{
  set ("short",HIG"论剑台"NOR);
  set ("long", @LONG
这里就是峨眉山的[论剑台]了。许多武林人士为了公平决斗，都来
这里进行比武。只见地上散乱地放了很多兵器，看来是又刚刚结束了一
场比武。如果要下论剑台，你可以跳(jump down)下去。
LONG);

  set("no_death",1);
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_jump","jump");
}

int do_jump(string arg)
{
   object ob;
   
   ob=this_player();
   if(!arg||arg!="down")
   return notify_fail("你要往哪里跳？\n");
   if(ob->is_busy()||ob->is_fighting())
   return notify_fail("你正忙着呢！\n");
   message_vision("$N纵身朝论剑台下跳去！\n",ob);
   tell_room(__DIR__"shanlu3",ob->name()+"从论剑台上跳了下来！\n");
   ob->move(__DIR__"shanlu3");
   return 1;
}
