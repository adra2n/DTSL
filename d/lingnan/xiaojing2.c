
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","小径");
  set ("long", @LONG
这里是条小径。整条路由细碎的小石子铺成。这里清幽典雅。南边
是一个花园。不时有宋家堡的弟子从那里进进出出。
LONG);

  set("exits", ([ 

  "northwest":__DIR__"xiaojing1",
 "south":__DIR__"huayuan3",
     ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

