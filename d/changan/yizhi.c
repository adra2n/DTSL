
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","阿房宫遗址");
  set ("long", @LONG
这里就是秦朝阿房宫的遗址，眼到之处尽是残垣断壁，回想当年富
丽堂皇的阿房宫一夜之间变成废墟，不禁使你感慨万千。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"guandao4",
         ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}
