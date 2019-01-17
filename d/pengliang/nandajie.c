inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。东边就是大名鼎鼎的
少帅的在彭梁的办公地点＂少帅府＂
LONG );
        set("outdoors", "pengliang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"damen",
		"north" : __DIR__"shizijietou",
		"south" : __DIR__"nanmen",
	]));
	setup();
	replace_program(ROOM);
}

