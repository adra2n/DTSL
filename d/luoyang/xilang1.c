
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"西廊"NOR);
  set ("long", @LONG
这里是西廊。墙壁上画着很多的图画，均是历代名画家的成名之作。
这里已经是皇宫的内部了，所以有很多的卫兵在来回的巡逻。长廊的旁
边有一个水池，水面清晰，可以看到里面有许多鱼在游动。有几个宫女
正在池边玩耍。
LONG);

  set("exits", ([ 
  
  "east":__DIR__"changlang",
  "west":__DIR__"xilang2",

         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

