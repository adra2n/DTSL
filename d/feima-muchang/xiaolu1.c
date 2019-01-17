
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。两旁是高高的栅栏，里面养着各种各样的马匹。
有很多人牵着马朝外走去。远处可以看到几个牧场，有几个飞马牧场的
弟子正在那里放牧养马。
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"xiaolu2",
	  "southeast":__DIR__"podao2",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

