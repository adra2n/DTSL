
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","花园");
  set ("long", @LONG
这里是个花园。这里种的花不是很多，但是珍贵的品种也是不少。
群花争奇斗艳，竟相开放。有几个花匠正在这里修剪着花草。南边是宋
家堡堡主的卧室了，不是有丫鬟从这里走过。
LONG);

  set("exits", ([ 

      "east":__DIR__"xiaoqiao3",
	  "south":__DIR__"woshi1",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

