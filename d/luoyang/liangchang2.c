
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","粮仓");
  set ("long", @long
虽然洛阳外围已经有数个屯粮之处，但是枭雄王世充仍然在城内建
立了一处屯粮之所，平时派重兵看护。以防不测。
long);

  set("exits", ([ 
      "west":__DIR__"liangchang",
      "east":__DIR__"changxiajie3",
  ]));
  set("objects",([
	  __DIR__"npc/wujiang2":2,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

