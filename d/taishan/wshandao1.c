
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","蜿蜒山道");
  set ("long", @LONG
这里是通往泰山后山的蜿蜒山道，因为路很不好走，所以这里的游
人很少，抬头望去，泰山高耸的山峰已经深入云端。
LONG);

  set("exits", ([ 

   "southdown":__DIR__"daizongfang",
   "northup":__DIR__"wshandao2",
        ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

