
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"石阶"NOR);
  set ("long", @LONG
这里是石阶。再往上走，就可以到皇宫正殿紫金殿了。来皇宫参见
皇上的大臣们都要经过这里。石阶十分宽大，两边站着守卫的官兵。平
时根本没人来这里。
LONG);

  set("exits", ([ 
  
  "enter":__DIR__"zijindian",
  "down":__DIR__"guangchang4",
         ]));
  set("objects",([
	  __DIR__"npc/guanbing":4,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

