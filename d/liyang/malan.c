inherit ROOM;
void create()
{
	set("short", "马栏");
	set("long", @LONG
这里是军营的马栏，清一色的高头战马。营中的战马俱是精选，膘
肥体壮，马夫们正给马槽里添黑豆和草料，一股马粪味和草料的混合味
道飘了过来。
LONG );
	set("exits", ([
		"west" : __DIR__"junying",
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

