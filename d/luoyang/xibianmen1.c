
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"朱雀门"NOR);
  set ("long", @LONG
这里是洛阳西门的朱雀门。从这里也可以进入洛阳城中。有几个官
兵正在这里严格地检查出入的行人。
LONG);

  set("exits", ([ 
  

  "south":__DIR__"ximen",
 
         ]));
  set("objects",([
	  __DIR__"npc/bing":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

