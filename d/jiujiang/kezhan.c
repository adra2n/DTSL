
inherit ROOM;


void create ()
{
  set ("short","九江客栈");
  set ("long", @LONG
这里是一家客栈。由于来九江的人很多，所以这家客栈经常人满。
店小二跑来跑去，忙个不停。只见又一个江湖豪客走了进来，店小二连
忙跑上去打招呼。
LONG);

  set("exits", ([ 

 "north":__DIR__"dongdajie2",
 "enter":__DIR__"wofang",

         ]));
 set("objects",([
	 __DIR__"npc/xiaoer2":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="enter")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("店小二拦住了你：客官，您还没给钱呢!\n");
		else return notify_fail("掌柜从里面喊道：客官，给钱再住店啊!\n");
		return ::valid_leave(me,dir);
		return 1;
}
