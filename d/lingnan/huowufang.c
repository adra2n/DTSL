
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","货物房");
  set ("long", @LONG
这里是宋家堡的货物房。宋家堡所有生意的货物都放在这里保管。
宋家堡的货物总管正在这里清点着货物。
LONG);

  set("exits", ([ 

  "west":__DIR__"zhulin",
       ]));
  set("objects",([
	  __DIR__"npc/li":1,
	  ]));

  set("valid_startroom", 1);
 
  setup();
 
}

