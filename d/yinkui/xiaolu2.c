
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。这里地处洛阳和襄阳之间，行人却不是很多。这
里风景秀丽，山水如画，空气清新。地上有很多漂亮的野花、蒲公英等
植物。不时有鸟儿从你的头上飞过。
LONG);

  set("exits",([
	  "westup":__DIR__"xiaolu1",
          "southeast":__DIR__"xiaolu3",
	  "northwest":__DIR__"fendi",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

