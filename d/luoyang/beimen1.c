
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"青龙门"NOR);
  set ("long", @LONG
这里是洛阳的青龙门，从这里也可以入城。城墙上站着几个士兵，
警惕地看着进出的行人。
LONG);

  set("exits", ([ 
      "southwest":__DIR__"qinglongjie",
      "east":__DIR__"beimen",
  ]));
  set("objects",([
      __DIR__"npc/bing":2,
  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 }

