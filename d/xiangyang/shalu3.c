
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是一条沙石路。南边是一片树林。偶尔会有人骑着马匆匆而
过。路旁有一个用树木搭起的小屋。
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shalu2",
  "south":__DIR__"tree1",
  "northeast":"/d/baling/lu1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

