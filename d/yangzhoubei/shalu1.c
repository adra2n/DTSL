
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","沙路");
  set ("long", @LONG
这里是一条沙路。一阵风吹过，卷起漫天的黄沙。不时有官兵骑着
马急驰而过。看来又要打仗了。
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu3",
 "northwest":__DIR__"shalu2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

