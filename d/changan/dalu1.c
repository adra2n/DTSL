
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","大路");
  set ("long", @LONG
这里是一条大路。这里是河南省的边界了。从这里西行，就是陕西
省了。往东边走，就可以到洛阳了。这条道路非常宽敞，看起来太平无
事。
LONG);

  set("exits", ([ 
"west":__DIR__"tulu2",
"east":__DIR__"dalu2",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

