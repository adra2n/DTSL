
#include <ansi.h>
inherit ROOM;


void create ()
{
set ("short","北大街");
  set ("long", @LONG
这里是襄阳的北街。街上的人很少，显得有些冷清。东边有一家裁
缝店，但是门口看起来冷冷清清。有几个人正站在这里，低声地谈论着
天下的形势。
LONG);

  set("exits", ([ 
 "north":__DIR__"beidajie3",
 "south":__DIR__"beidajie1",
 "east":__DIR__"caifengdian",
        ]));
  set("objects",([
	  __DIR__"npc/butou":1,
	  __DIR__"npc/old":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

