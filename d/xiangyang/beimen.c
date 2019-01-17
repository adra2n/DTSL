
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北门");
  set ("long", @LONG
这里是襄阳城的北门。自古以来襄阳就是军事重地。所以这里的检
查也是非常严格。有几个官兵耀武扬威地站在那里，对进城的人不住地
呼喝。
LONG);

  set("exits", ([ 
 "south":__DIR__"beidajie3",
 "north":__DIR__"beiguanlu1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

