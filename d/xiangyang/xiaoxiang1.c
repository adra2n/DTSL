
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小巷");
  set ("long", @LONG
这里是小巷。这里经常混杂了各种人物，三教九流各种各样。只见
几个地痞样的人物正聚在角落里赌钱，不是传来阵阵地叫骂声。还有几
个人聚集在一起低声地商量着什么，不是还抬起头看你几眼。
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie1",
 "northeast":__DIR__"xiaoxiang2",
        ]));
  set("objects",([
	  __DIR__"npc/liumang":1,
	  ]));
   set("outdoors","xiangyang");
set("valid_startroom", 1);
  setup();
 
}

