
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"主堂"NOR);
  set ("long", @LONG
这里是独尊堡的主堂。门前有两个石狮子，更增添了庄严的气氛。
正中央放着一把大椅子，两旁排列着一排小椅子。这里庄严肃穆，让人
连大气也不敢出一声。
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"qiao",
	  "southeast":__DIR__"ceyuan",
	  "east":__DIR__"donglang1",
	  "west":__DIR__"xilang1",
         ]));
  set("valid_startroom", 1);
  setup();
  "/obj/sboard/duzun_b.c"->foo();
}
