
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草原");
  set ("long", @LONG
这里是一片一望无际的草原。有几个马夫在这里放马。这里离天下
文明的飞马牧场不远了，看这里的马雄俊无比，或许就是飞马牧场的良
驹。
LONG);

  set("exits", ([ 
  "southeast":__DIR__"shanlu2",
  "northwest":__DIR__"shanlu3",
        ]));
  set("objects",([
	  __DIR__"npc/mafu":1,
	  __DIR__"npc/horse":1,
	  ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

