
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","海滨");
  set ("long", @LONG
这里是海滨。南边是茫茫的大海。面对大海，心中顿时觉得舒服了
许多，好象在多的苦恼在大海面前都可以消失的一干二净。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"haibin5",
 "west":__DIR__"haibin3",
        ]));
  set("objects",([
    __DIR__"npc/youke":2,
    ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

