
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是一条青石路，路面是由上好的青砖铺成。西边是阴癸派的议
事广场。这里冷冷清清的，平时没有什么来这里。
LONG);
  set("exits",([
	  "west":__DIR__"guangchang",
	  "east":__DIR__"qingshilu5",
	  ]));
  /*
  set("objects",([
      __DIR__"npc/fanan":1,
      ]));*/
  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

