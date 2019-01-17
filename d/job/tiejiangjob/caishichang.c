#include <ansi.h>
inherit ROOM;

int do_cai(string arg);
void create ()
{
  set ("short","采石场");
  set ("long", @LONG
这里是采石场。这里有丰富的矿石，许多人在这里采石，来打造兵
器。但是据说也有不少人在开采矿石时被矿石砸死。这里还立着一个牌
子（pai）。
LONG);

  set("exits", ([ 
 "southeast":__DIR__"shanlu1",
// "east":__DIR__"songlin",
       ]));
  set("item_desc",([
	  "pai":"在此开采(kaicai)矿石者，受伤者自负，官府一概不负责。\n",
	  ]));
set("outdoors","dabashan");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_cai","kaicai");
}

int do_cai(string arg)
{
	object me,ob,tool;
	me=this_player();
	if(!arg||arg!="矿石")
		return notify_fail("你想开采什么？\n");
	if(!objectp(tool=me->query_temp("weapon")))
		return notify_fail("空手怎么开采矿石？\n");
	if(tool->query("skill_type")!="fork")
		return notify_fail("你还是用镐头开采吧！\n");
	if(me->is_busy())
		return notify_fail("你现在很忙，歇歇吧!\n");
	if(me->is_fighting())
		return notify_fail("你还是先打完仗再说吧！\n");
	if((int)me->query_encumbrance() + 50000 > (int)me->query_max_encumbrance() ) 
         return notify_fail( "你身上的东西太多了，根本拿不动矿石，还采什么啊。\n");
      message_vision("$N用"+tool->name()+"开采起矿石来。\n",me);
	me->start_busy(1);
	me->receive_damage("sen",50+random(5));
	if(random(10)>6)
	{ob=new("/d/job/tiejiangjob/kuang");
	ob->move((me));
	message_vision("$N开采出一块"+ob->name()+"来！\n",me);
	}
	else
	{
		message_vision("突然一块大矿石从山上滚了下来！\n直接砸向$N!\n",me);
		if((int)me->query_skill("dodge",1)>=1)
		{
			message_vision("$N见势不好，连忙闪了开来！\n",me);
            ob=new("/d/job/tiejiangjob/kuang");
	        ob->move((me));
            message_vision("$N开采出一块"+ob->name()+"来！\n",me);
			return 1;
		}
		else
		{
			message_vision("$N被矿石砸了正中！\n",me);
            ob=new("/d/job/tiejiangjob/kuang");
	        ob->move((me));
			me->unconcious();
			return 1;
		}
	}
	return 1;
}