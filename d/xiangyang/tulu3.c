
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。这里是四川的境地。往西走就可以到成都了。不时
有几骑快马飞快跑过。
LONG);

  set("exits", ([ 
 "east":"/d/dabashan/shanlu5",
 "west":__DIR__"tulu4",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

