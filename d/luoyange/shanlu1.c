
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条通向西边山上的小路。遥遥望去，西边的山峰高高耸立，
似乎有很多楼宇林立其中。不时有人骑着马从你的身旁驰过。
LONG);

  set("exits", ([ 
  "southeast":__DIR__"xiaolu3",
  "northwest":__DIR__"shanlu2",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

