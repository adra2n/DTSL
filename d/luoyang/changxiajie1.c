
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长夏大街");
  set ("long", @long
这里是洛阳的长夏街。东面是一个绸缎庄。

long);

  set("exits", ([ 
	  "north":__DIR__"shennvdi2",
	  "east":__DIR__"caifengdian",
  	  "south":__DIR__"changxiajie2",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

