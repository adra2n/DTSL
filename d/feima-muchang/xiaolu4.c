
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是条小路。这是通往后山的路，所以几乎没有什么人。有很多
人牵着马朝远处走去。远处可以看到几个牧场，有几个飞马牧场的弟子
正在那里放牧养马。
LONG);

  set("exits", ([ 
	  "northeast":__DIR__"xiaolu3",
	  "southwest":__DIR__"houshan",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

