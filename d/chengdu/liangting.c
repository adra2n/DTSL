
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","凉亭");
  set ("long", @LONG
这里是凉亭。北面是个花园。清风吹来，你不觉精神一振。凉亭的
围杆花纹奇特，必定是出自成都著名工匠之手。
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"huayuan",
	  "south":__DIR__"changlang1",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
