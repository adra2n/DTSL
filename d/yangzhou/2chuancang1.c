
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","餐厅雅座");
  set ("long", @long
这里是船上的餐厅雅座，可以在这里与花魁，歌妓们一边欣赏美
美景一边品尝美味佳肴。
long);

  set("exits", ([ 

 "north":__DIR__"2chuancang2",
 "down":__DIR__"chuancang",
 ]));
 
 set("objects",([
	 __DIR__"npc/yahuan1":2,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

