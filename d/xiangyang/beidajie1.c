
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北大街");
  set ("long", @LONG
这里是襄阳的北大街。南面就是襄阳的中心了。由于近来战乱连年，
所以街上的行人不是很多。不是有几个捕头走过，手中拿着一些字画，似
乎正在寻找通缉犯。
LONG);

  set("exits", ([ 
 "north":__DIR__"beidajie2",
 "south":__DIR__"guangchang",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

