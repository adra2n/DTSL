
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长安楼");
  set ("long", @LONG
这里是长安有名的酒楼，虽然比不上跃马桥畔的福聚楼，但也算是
长安数一数二的酒楼了，并不是每个人都可以到这里来吃饭的。
LONG);

  set("exits", ([ 
 "west":__DIR__"hgdajie2",
        ]));
 set("objects",([
	 __DIR__"npc/xiaoer5":1,
	 ]));
 set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

