
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是飞马牧场大管家商震的卧室。平时很少有人到这里来。床上
的被褥叠得整整齐齐。墙上挂着一副字画，字迹看起来苍劲有力，显示
出一副英雄豪迈的气氛。
LONG);

  set("exits", ([ 
	  "south":__DIR__"qingshilu6",
    ]));
  set("objects",([
 "/d/job/feima/shangzhen":1,
	  ]));
 set("no_fight",1); set("no_exert",1);

  
  set("valid_startroom", 1);
  setup();
 
}

