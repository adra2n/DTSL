
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是襄阳城的南门外的官路。北面就可以到襄阳的北门了。有很
多车马朝北边走去，一派热闹的景象。这里渐渐热闹了起来，不时有大
队的官兵从你的身旁走过。
LONG);

  set("exits", ([ 
 "north":__DIR__"guanlu3",
 "south":__DIR__"xiaolu1",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

