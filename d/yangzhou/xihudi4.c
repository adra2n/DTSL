
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西湖堤");
  set ("long", @LONG
这里是扬州城的西湖堤。这里停靠着几艘已经修补好的花船，三三两
两的船工或坐或卧，随地休息着。
LONG);

  set("exits", ([
 "south":__DIR__"xihudi3",
 "northeast":__DIR__"guangchang",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

