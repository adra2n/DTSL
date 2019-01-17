
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","仰天池");
  set ("long", @LONG
仰天池不过一米见方，深不盈尺。此池被道家称作太乙池。别看这
池子不大，“神通”可大着哩。它久旱不涸，雨涝不溢，春夏秋冬，池
水始终如一。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"liandanlu",
 "southup":__DIR__"luoyanfeng",
 "eastup":__DIR__"jintiangong",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
