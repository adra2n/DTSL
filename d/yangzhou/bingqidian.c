
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵器店");
  set ("long", @LONG
这里是一家兵器店，这里打造的兵器坚固，锋利，受人赞誉。熊熊
火光照亮了四周的墙壁，热气熏的你想脱掉身上的衣服。四下看去，只
见到处放着长剑、钢刀，在炉火的照耀下闪闪发光。只见铁匠正在那里
敲敲打打，只见又一把锋利的宝剑出炉了。
LONG);

  set("exits", ([ 
 "north":__DIR__"dongdajie1",
       ]));
  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

