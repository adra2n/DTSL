
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","望仙大街");
  set ("long", @LONG
这是望仙大街，南北贯通长安城。大街上十分热闹，人来人往川流
不息。西面是一片宁静的住宅区。
LONG);

  set("exits", ([ 
 "north":__DIR__"dongshixikou2",
 "south":__DIR__"xpdajie6",
 "west":__DIR__"xuanpingfang",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

