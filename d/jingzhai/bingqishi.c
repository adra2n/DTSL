
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"兵器室"NOR);
  set ("long", @LONG
这里是慈航静斋的兵器室。这里整整齐齐地放着几把兵器。旁边立
着一块牌子，写着：普善为本。
LONG);

  set("exits", ([ 

  "north":__DIR__"suishilu3",
    ]));
  set("objects",([
	  __DIR__"obj/changjian":3,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

