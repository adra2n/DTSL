
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是飞马场主尚秀珣的卧室。床上的被褥叠得整整齐齐。墙上挂
着一口宝剑。梳妆台旁边的桌子上还放着一些书籍。这里的摆设朴素大
方，不落俗套。一股淡淡的清香充满了整个卧室。
LONG);

  set("exits", ([ 
	  "south":__DIR__"feiniao_yuan",
    ]));

  
  set("valid_startroom", 1);
  setup();
 
}

