
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是石龙武馆的练武场，是石龙武馆初级弟子学习武功的地方。
你可以在这里举石锁来提高自己的武功。只见这里尘土飞扬，数名弟子
正在那里练得热闹。
LONG
);


	set("exits", ([
		"north" :__DIR__"wuchang2",
		
	]));
	/*set("objects",([
	     __DIR__"npc/dizi":1,
	    ]));*/
       set("no_fight",1);
       set("lianwu","举石锁");
       set("over_work","你的举石锁已经练习得可以了，可以去找教头了[task ok]。\n");
       set("work_msg",({
       "你一声大喊，把石锁举过了头顶，然后“砰”地一声扔在了地上！\n",
       "你一口气把石锁举过头顶，稳稳地站了一会，然后“砰”地一声把石锁扔了下来！\n",
       "你气沉丹田，吸了口气，把石锁举过了头顶，然后“砰”地一声扔在了地上！\n",
       }));
       set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","lianwu");
}

#include "work_skill.c"