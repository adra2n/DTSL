
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛阳人坊");
  set ("long", @LONG
这里是洛阳人坊。东面是一个小饭馆，专门为那些小商贩们提供一
些便宜的食品，西边则是洛阳的水车肆，因为这里地势较高，是整个洛
阳最容易失火的地方，因此将朝廷的水车肆设立在这里。
LONG);

  set("exits", ([ 
      "east":__DIR__"xiaofanguan",
      "west":__DIR__"shuichesi",
      "north":__DIR__"qinglongjie2",
      "south":__DIR__"luoshenjie2"
  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

