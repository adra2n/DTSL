
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","寇记绸缎庄");
  set ("long", @LONG
这里是洛阳的一个绸缎庄。这里的做的衣服美观大方，达官显贵络
绎不绝地到这里挑选适当的衣物。
LONG);

  set("exits", ([ 
 "west":__DIR__"changxiajie1",
        ]));
 set("objects",([
	 __DIR__"npc/ma":1,
	 __DIR__"npc/huoji":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

