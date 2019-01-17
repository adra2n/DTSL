
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东湖堤");
  set ("long", @LONG
这里是扬州城的东湖堤。东边传来一些喧哗声，打破了这里的宁静。
和这里的垂扬斜柳不同南面就又是一番景色了。
LONG);

  set("exits", ([ 
 "north":__DIR__"donghudi3",
 "southwest":__DIR__"nanhudi2",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

