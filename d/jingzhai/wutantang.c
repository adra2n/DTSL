
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"无贪堂"NOR);
  set ("long", @LONG
这里是慈航静斋的无贪堂。来到此堂的慈航静斋的弟子，每看到无
贪堂三个字，都要时刻谨记要忘记贪念，以超脱世俗。
LONG);

  set("exits", ([ 

  "north":__DIR__"qusutang",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

