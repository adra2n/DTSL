
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","车马行");
  set ("long", @LONG
这里是这是襄阳城的车马行，总管襄阳军事上的车马供应。有几个
官兵正无精打采地站在这里。这里的马也是缺乏喂养，同天下闻名的飞
马牧场相比，真是天壤之别了。
LONG);

  set("exits", ([ 
 "east":__DIR__"nandajie2",
       ]));
  set("objects",([
	  __DIR__"npc/lizongbing":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

