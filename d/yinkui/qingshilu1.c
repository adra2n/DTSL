
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是条青石路，地上铺着整齐的青砖。这里冷冷清清的。几乎没
有什么人。南边是阴癸派的议事广场。北边一条青石路。
LONG);
  set("exits",([
	  "south":__DIR__"guangchang",
	  "north":__DIR__"qingshilu2",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

