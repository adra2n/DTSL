
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","光明桥");
  set ("long", @LONG
这是一座位于光明大街上的白色石桥，跨越在南北流向的永安渠之
上，桥下舟楫往来，桥上行以车马不绝，四周尽是巨宅豪户，西南方向
就是有名的西市了。
LONG);

  set("exits", ([ 
  "westdown":__DIR__"xishibeikou2",
  "eastdown":__DIR__"gmdajie6",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

