
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","扁舟");
  set ("long", @LONG
这是荡漾在湖水中的一叶扁舟，用来接送往来画舫的公子佳人们。
几个公子正在船里吟诗作对。
LONG);

 set("outdoors","ship");
  set("valid_startroom", 1);
  setup();
 
}

