
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","武场");
  set ("long", @LONG
这里是海沙帮的武场。有几个海沙帮弟子在这里练习武艺，舞枪弄
棒，好不威风。
LONG);

  set("exits", ([ 
  "southwest":__DIR__"xiaolu2",
      ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

