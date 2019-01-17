

inherit ROOM;

void create()
{
	set("short", "南侧街");
	set("long", @LONG
这是一条普通的青石板路，南边是入滇必经的南侧门，北边不远是
东大街。这里的行人不是很多。
LONG);
        set("outdoors", "成都");

	set("exits", ([
		"north" : __DIR__"nancejie1",
		"south" : __DIR__"xiaonanmen",
	]));

	setup();
	replace_program(ROOM);
}

