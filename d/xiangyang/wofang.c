
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧房");
  set ("long", @LONG
这里是客栈的卧房了，这里横七竖八地躺着许多人，你来到这里，
不禁有些困了。
LONG);

  set("exits", ([ 
 "down":__DIR__"yingbinguan",
 
        ]));
  set("sleep_room",1); 
  set("valid_startroom", 1);
  setup();
 
}
int valid_leave(object me,string dir)
{
	if(dir=="down")
		me->delete_temp("gived_money");
	return ::valid_leave(me,dir);
}
