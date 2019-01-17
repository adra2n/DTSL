
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","迎宾馆");
  set ("long", @LONG
这里是襄阳最大的客栈--迎宾馆。每天都有很多人来这里投宿。由
于兵荒马乱，来投宿多是逃难的百姓。店小二总是忙个不停。只见又有
几个客人进来，店小二连忙过去打招呼。
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie1",
 "up":__DIR__"wofang",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="up")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("店小二拦住了你：客官，您还没给钱呢!\n");
		else return notify_fail("掌柜从里面喊道：客官，给钱再住店啊!\n");
		return ::valid_leave(me,dir);
		return 1;
}
