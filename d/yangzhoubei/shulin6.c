
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片树林。四下望去，竟然发现几具死尸，有几只野兽在那
里吃腐烂的尸体。你一阵恶心，加快了行进的脚步。
LONG);

  set("exits", ([ 
 "east":__DIR__"shulin5",
 "southwest": "/d/xingyang/tulu3",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

