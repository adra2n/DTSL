
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","长廊");
  set ("long", @LONG
这里是一条长廊，两边画着一些精美的山水画，一看就是出自名家
手笔。这里非常安静，连走过的丫鬟的都非常小心。北边是一个卧室，
是宋家堡弟子们休息、睡觉的地方。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"changlang1",
 "enter":__DIR__"woshi",
 "north":__DIR__"lingwuroom",
      ]));
  set("valid_startroom", 1);
  set("outdoors","songjia");
  setup();
 
}
