
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","东廊");
  set ("long", @LONG
这里是东廊。廊壁上画了很多山水名画，从中可以看出宋家堡的修
养水平如何。不时有一些宋家堡弟子从你的身旁匆匆走过。
LONG);

  set("exits", ([ 

  "west":__DIR__"donglang1",
  "east":__DIR__"donglang3",
       ]));
  set("objects",([
	  __DIR__"npc/yahuan":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

