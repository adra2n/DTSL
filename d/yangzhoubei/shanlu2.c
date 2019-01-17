
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。四周怪石嶙峋，几乎辨认不出前面的道路。战乱
时代，据说这种地方是盗贼出没之地，你不禁小心起来。
LONG);

  set("exits", ([ 
 "north":__DIR__"shanlu3",
 "southeast":__DIR__"shanlu1",
        ]));
  set("objects",([
     __DIR__"npc/qiangdao":1,
     ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

