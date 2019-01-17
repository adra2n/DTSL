

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小径");
  set ("long", @LONG
穿过东大寺，来到后方的一道窄小的路径，两旁林木蔽天，予人直
通幽微的隐蔽感觉。由于下过一场雪，小路铺满白雪，不留神下确很易
错过。你走进小径，脚踏处发出“沙沙”的响声。
LONG);

  set("exits", ([ 
 "west":__DIR__"dongdasi",
 "north":__DIR__"yuhean",
]));
 
 set("outdoors","changan");
    set("valid_startroom", 1);
  setup();
 
}
