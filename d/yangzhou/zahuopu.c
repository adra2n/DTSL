
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","杂货铺");
  set ("long", @LONG
这里是扬州的一家杂货铺。这家店铺开张已久，在扬州有着不小的
声誉。每天来这里买东西的人很多。店铺老板总是在这里忙来忙去。
LONG);

  set("exits", ([ 
 "east":__DIR__"nanjishi",
        ]));
  set("objects",([
	  __DIR__"npc/zhu":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}


