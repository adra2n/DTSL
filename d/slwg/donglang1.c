
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "东廊");
	set("long", @LONG
这里是石龙武馆的西厢廊。继续往东边走，就是武馆练习武功的练
功房了。东边是武馆的正厅。厢廊的两旁是不大不小的荷花池，里面荷花
盛开，非常漂亮。
LONG
);


	set("exits", ([
		"westup" :__DIR__"zhengting",
                "east":__DIR__"donglang2",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
