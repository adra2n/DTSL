
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小亭");
  set ("long", @LONG
这里是一座小的凉亭，里面的摆设非常简单，只有几个石桌子、石
凳子。有几个游客正在那里休息聊天。四周景色秀丽，清风阵阵吹来，
不由得让人感到舒服。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu4",
       ]));
  /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
