
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","宽敞大路");
  set ("long", @LONG
这里是一条宽敞的大路。江苏自古以来就是繁华的地方，所以这里
人也是很多，有些热闹。有几个江南女子谈笑着从你的身旁走过，丝毫
不带一丝的羞涩之意。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"xiaolu4",
 "south":__DIR__"dalu2",
 "north":"/d/yangzhoubei/xiaolu1",
        ]));
  set("objects",([
          __DIR__"npc/nvzi":2,
          ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

