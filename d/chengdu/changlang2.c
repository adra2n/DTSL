
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长廊");
  set ("long", @LONG
这里是长廊。墙壁上有各种美丽的图案，种类繁多，有山水、花鸟、
鱼虫等等，一看就是出自著名工匠之手。南边就是解文龙的卧室了。
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"xilang2",
	  "south":__DIR__"woshi2",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
