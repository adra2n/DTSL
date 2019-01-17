
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是画舫上的的厨房，有几个厨子正在这里忙着做饭。只见这里
香气扑鼻，有很多做好的饭菜放在了桌子上。有几个客人正在那里姿态
幽雅地吃着。
LONG);
	set("exits", ([
		"east" :__DIR__"chuancang2",
	]));
	set("objects",([
	    __DIR__"npc/chuzi":1,
	    ]));
	set("resource/water",1);
	set("valid_startroom", 1);
	setup();
}
