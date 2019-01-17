
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","石桥");
  set ("long", @LONG
这里是座石桥。从这里往前看，恰好可以看见一块大岩石，由于酷
似观音。菩萨，故名观音岩。一道瀑布从岩上流下，又好似滴水观音。
造化之工，实在令人赞叹不已。
LONG);

  set("exits", ([ 
 "east":__DIR__"jietuopo",
 "southup":__DIR__"jingxinan",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

