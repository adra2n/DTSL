
#include <ansi.h>
inherit ROOM;

int do_claw(string arg);
void create ()
{
  set ("short","山崖顶");
  set ("long", @LONG
这里是山崖的顶部。很多人都到这里来采药。
LONG);
   set("objects",([
	   __DIR__"obj/heshouwu":1,
	   ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_claw",({"pa","claw"}));
}

int do_claw(string arg)
{
	object me;
	me=this_player();
	if(!arg||arg!="down")
		return notify_fail("你要往哪里爬？\n");
	message_vision("$N朝山崖下爬去！\n",me);
	me->move(__DIR__"shanya");
	return 1;
}