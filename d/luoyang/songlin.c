
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","松林");
  set ("long", @LONG
这里是一片松林，四周静悄悄的。一股松子油的清香扑入鼻中。西
边是一个采石场，传来采石的声音。
LONG);

  set("exits", ([ 
  "south":__DIR__"shanlu3",
  "west":__DIR__"caishichang",
  "east":__DIR__"songlin2",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

