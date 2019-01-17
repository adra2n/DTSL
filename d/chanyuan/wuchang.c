
#include <ansi.h>
inherit ROOM;
int do_sao(string arg);

void create ()
{
  set ("short","练武场");
  set ("long", @LONG
这里是净念禅院的武场。平时武僧们就在这里练习武艺。只听这里
呼喝的声音不绝，旁边几个僧人打得正起劲。远处十几个僧人站成几排，
正在努力练习武艺，呼喝的声音远远传来，悠扬不绝，足见内力之深。
LONG);

  set("exits", ([ 

	  "east":__DIR__"xiaolu7",
	  "west":__DIR__"caodi4",
      ]));
  set("objects",([
	  __DIR__"npc/xuchen":1,
	  ]));
  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_sao","sao");
}

int do_sao(string arg)
{
	object me;
	me=this_player();
	if(!arg||arg!="武场") return notify_fail("你想扫什么?\n");
	if(!me->query_temp("budian_job/3"))
		return notify_fail("你在这里忙什么呢?\n");
	if(me->is_busy()) return notify_fail("你正忙着呢!\n");
	if((int)me->query("sen",1)<=5) return notify_fail("你太累了,已经不能再干活了!\n");
	if(me->query_temp("budian_job/ok"))
		return notify_fail("好了,你可以回去交工了!\n");
	if(me->query_temp("budian_job/count"))
		me->add_temp("budian_job/count",1+random(1));
	else me->set_temp("budian_job/count",1);
	if((int)me->query_temp("budian_job/count",1)>=10+random(5))
		me->set_temp("budian_job/ok",1);
	me->receive_damage("sen",10+random(2));
	call_out("return_job",2,me);me->start_busy(1);
	message_vision("$N仔细地打扫起武场来。\n",me);
	return 1;
}

void return_job(object me)
{
	message_vision("$N擦擦头上的汗,觉得自己又为佛家圣地做了件好事.\n",me);
	return;
}