
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","和光大街");
  set ("long", @LONG
这是和光大街，南北连接长安城的光化门和和平坊。这里不再那么静
悄悄了，街上十分热闹，人来人往川流不息。西面有一家饭铺，东面看样
子象是一个赌场。
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie1",
 "south":__DIR__"hgdajie2",
 "east":__DIR__"lequanguan",
 "west":__DIR__"fanpu",
       ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

