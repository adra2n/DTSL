
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条崎岖的山路。向北走可以到华山的金天宫，西南边有一
座小凉亭，供行人休息之用。东南是去华山南天门的道路。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"jintiangong",
 "east":__DIR__"shanlu5",
 "southwest":__DIR__"yanggongting",
 "southeast":__DIR__"nantianmen",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
