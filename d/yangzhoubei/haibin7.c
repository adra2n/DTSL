
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","海滨");
  set ("long", @LONG
这里是海滨。西边是茫茫的大海。几名渔夫看来是刚刚打鱼回来。
现在兵荒马乱，附近的渔村经常遭到官兵、盗贼的洗劫，渔民的生活很
是艰苦。
LONG);

  set("exits", ([ 
 "east":__DIR__"tulu",
 "northwest":__DIR__"haibin6",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

