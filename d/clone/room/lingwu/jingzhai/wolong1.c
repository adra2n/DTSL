
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧龙岭");
  set ("long", @LONG
这里就是长白山的卧龙岭了，这里地势险要，两边都是突起的岩石
峭壁，道路上满是冰雪，一不小心就可能滑落到山涧之中。路的旁边立
着一个大石碑，上面的字迹已经模糊不清，只能隐约看到卧龙岭三个大
字。
LONG);

  set("exits", ([ 
 "westup":"/d/changbaishan/tiyun-feng",
 "eastup":__DIR__"wolong2",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

