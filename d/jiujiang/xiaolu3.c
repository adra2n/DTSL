
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是江边的小路。这里行人不多。你不时可以看到江上有大船驶
过。一阵风吹过，江水的潮湿气息扑鼻而来。
LONG);

  set("exits", ([ 

  "east":__DIR__"caodi1",
  "southwest":__DIR__"xiaolu2",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

