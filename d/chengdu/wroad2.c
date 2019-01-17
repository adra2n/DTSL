
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "大路");
	set("long", @LONG
这是成都西门外的一条大路。西边是一片树林，据说很多人在那里
迷路出不来。
LONG);


	set("exits", ([
		"east" : __DIR__"wroad1",
        "west":"/u/kouzhong/youlin1",
	]));
       set("outdoors", "成都");
	setup();
}



