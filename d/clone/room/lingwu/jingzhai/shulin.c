
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","松树林");
  set ("long", @LONG
这里是一片广阔的松树林。西边就是卧龙岭的摆尾峰。由于树木茂
盛，所以这里寒风不是很大。地上的积雪很厚，几乎能没人膝盖。据说
这里经常有群狼出没，你不禁小心起来。
LONG);

  set("exits", ([ 
 "west":__DIR__"wolong7",
 "east":__DIR__"shulin",
 "south":__DIR__"shulin",
 "north":__DIR__"shulin",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

