
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","练武场");
  set ("long", @LONG
你走进一座三开间的大厅，打通了成为一个大场子。场子两边的兵
器架上摆满了各种兵刃。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"houhuayuan",
        ]));
 

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

