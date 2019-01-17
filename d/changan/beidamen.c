
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北大门");
  set ("long", @LONG
这是长安城的北大门，城墙上贴着几张官府告示。官兵们警惕地注
视着过往行人，你最好小心为妙。一条笔直的青石板大道向南延伸。向
北的路就能通向北梁山地区，过了山就是回族人的地盘了。
LONG);

  set("exits", ([ 
 "east":__DIR__"xiaolu5",
 "west":__DIR__"xiaolu4",
 "north":__DIR__"shandao6",
 "south":__DIR__"tydajie4",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

