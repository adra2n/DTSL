
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"竹林"NOR);
	set("long", @LONG
这里是竹林。这里的竹子青翠碧绿。在这里插着一个碧绿的竹棒。
有几个弟子正在这里干活。
LONG);
	set("exits", ([	     		
		"east":__DIR__"wchanglang1",
		"southwest":__DIR__"zhulin2",
		"northwest":__DIR__"jiashan",				
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

void init()
{
	add_action("do_zhong","zhong");
}

int do_zhong(string arg)
{
	object ob;
	ob=this_player();
	if(!ob->query_temp("popo_job1"))
		return notify_fail("你在这里忙什么呢?\n");
	if((int)ob->query("sen",1)<8)
		return notify_fail("你太累了，歇歇吧!\n");
	if(ob->is_busy())
		return notify_fail("你正忙着呢?\n");
	if(!arg||arg!="竹子") return notify_fail("你想做什么?\n");
	else
	{ 
	
			ob->add_temp("count",1);
		
		ob->receive_damage("sen",random(8));
		ob->start_busy(1);
		message_vision("$N认真的种起竹子来.\n",ob);
		  if((int)ob->query_temp("count",1)>10+random(3))
		  { ob->delete_temp("popo_job");
		    ob->delete_temp("popo_job1");
			ob->set_temp("popo_ok",1);
		    ob->delete_temp("count");
			printf("你可以回去复命了!\n");
			return 1;
		  }
		  call_out("return_job",1,ob);
		  return 1;
	}
	
}

void return_job(object ob)
{
	switch(random(3))
	{
	case 0:message_vision("$N擦了擦头上的汗，深吸了一口气，觉得精神好多了。\n",ob);break;
	case 1:message_vision("$N擦了擦头上的汗，不禁为这里美丽的景色所吸引住了。\n",ob);break;
	case 2:message_vision("$N擦了擦头上的汗，觉得自己又为东溟派做了一件好事。\n",ob);break;
	}

	remove_call_out("return_job");
}




