
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小石路");
  set ("long", @LONG
这里是条小石路。这里不时地可以看到阴癸派的弟子。南边就是阴
癸派的山门了。北边是一个花园。这里人影稀少，非常寂静，透漏出一
股诡异的气氛。
LONG);
  set("exits",([
	  "south":__DIR__"door",
	  "north":__DIR__"huayuan",
	  ]));

  set("outdoors","yingui");
  set("valid_startroom", 1);
  setup();
 
}

