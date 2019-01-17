
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"长夏门"NOR);
  set ("long", @LONG
这里是洛阳的南门的边门。从这里也可以进入洛阳城。
LONG);

  set("exits", ([ 
  	  "southeast":"/d/outyang/guanlu1",
	  "north":__DIR__"changxiajie5",
	  "northeast":__DIR__"xiaolu1",
  "west":__DIR__"nanmen",
       ]));
  set("objects",([
	  __DIR__"npc/bing":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

