
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"新春门"NOR);
  set ("long", @LONG
这里是洛阳西门的边门。从这里也可以进入洛阳城中。有几个官兵
正在这里严格地检查出入的行人。
LONG);

  set("exits", ([ 
  

  "northup":__DIR__"xichenglou",
  "east":__DIR__"luoshuidi1",
 
         ]));
  set("objects",([
	  __DIR__"npc/bing":1,
	  ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

