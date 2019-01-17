// Room: /d/longyan/drugstore.c

inherit ROOM;

void create()
{
	set("short", "紫仁堂");
	set("long", @LONG
这里是一间药铺，据说远近的乡亲都来这里看病，这里
的大夫姓张，人送外号“张华佗”，据说医术了得，是附近
的名医。这里陈设朴实，正堂上一块大扁“妙手回春”。再
往里就是药房了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mktstr2",
]));

	setup();
	replace_program(ROOM);
}
