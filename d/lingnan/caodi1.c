
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片草地。这里已经是岭南了。迎面的是一条笔直大道，道
边种有青青杨柳树，随风飘扬。南边隐隐约约可以看到一个城堡似的建
筑物。
LONG);

  set("exits", ([ 

  "northwest":"/d/xiangyang/caodi1",
  "southeast":__DIR__"dalu1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

