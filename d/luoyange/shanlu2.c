
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条通向西边山上的小路。这里地势险要，确实是个易守难
攻的地方。这里离天下文明的飞马牧场不远了，不时可以在附近看到飞
马牧场放马的人。
LONG);

  set("exits", ([ 
  "southeast":__DIR__"shanlu1",
  "northwest":__DIR__"caoyuan",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

