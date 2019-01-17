
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是石龙武馆的练武场，是石龙武馆初级弟子学习武功的地方。
你可以在这里练站桩来提高自己的武功。只见这里尘土飞扬，数名弟子
正在那里练得热闹。
LONG
);


	set("exits", ([
		"west" :__DIR__"wuchang2",
		
	]));
	/*set("objects",([
	     __DIR__"npc/dizi":1,
	    ]));*/
       set("no_fight",1);
       set("lianwu","站桩");
       set("over_work","你的站桩已经练习得可以了，可以去找教头了[task ok]。\n");
       set("work_msg",({
       	"你两腿一分，一个马步稳稳地站在地上！\n",
       	"你大喝一声，气沉丹田，双脚一跺，地上出现一个浅坑。\n",
       	"只见一名弟子朝你的双脚踢去，你晃了几晃，稳稳地站住了。\n",
       	}));
       set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","lianwu");
}

#include "work_skill.c"