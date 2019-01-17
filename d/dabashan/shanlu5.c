
#include <ansi.h>
inherit ROOM;
int do_pa();
void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。东边就是险峻的大巴山了。抬头望去，大巴山怪
石嶙峋，不禁让人望而却步。四下没有什么路，要想上去，只有爬(pa)了。
LONG);

  set("exits", ([ 

   "west":"/d/xiangyang/tulu3",
           ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
  add_action("do_pa","pa");
}

int do_pa()
{
   object me;
   me=this_player();
   if(me->query("sen")<15)
   return notify_fail("你试图爬上去，可是精神疲倦，根本使不上半点力气。\n");
   me->add("sen",-15);
   message_vision("$N看准一个地方，用双手抓住，爬了上去。\n",me);
   tell_room(__DIR__"shanji2",me->name()+"爬了上来！\n");
   me->move(__DIR__"shanji2");
   return 1;
}
