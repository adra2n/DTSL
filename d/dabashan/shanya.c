
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山崖");
  set ("long", @LONG
这里是大巴山的一个山崖。这里地势倾斜，你不禁加倍小心起来，
以免掉了下去。
LONG);

  set("exits", ([ 

   "south":__DIR__"shanlu1",
   "northeast":__DIR__"shanfeng",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

