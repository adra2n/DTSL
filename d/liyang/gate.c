inherit ROOM;
void create()
{
	set("short", "元帅府");
	set("long", @LONG
这是黎阳元帅府的所在地，黑色大门平时紧紧闭着，门前四个身着
士兵站着。边上有个大旗杆。
LONG );
	set("exits", ([
		"south" : __DIR__"qingshilu",
		"north":"/d/clone/room/cityroom/liyang",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 4,
	]));
	set("no_clean_up", 0);
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

