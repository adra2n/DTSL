// /d/yuyang/edao1
// Room in 渔阳
inherit ROOM;

void create()
{
	set("short", "涿郡");
	set("long", @LONG
涿郡和渔阳、安乐、北平、辽西并列为东北边陲五大城，因高开道
以渔阳为京，故渔阳隐成五城之首，成为该区军事经济贸易的中心，但
涿郡因其地理位置也是兵家必争之地。
LONG
	);

	set("exits", ([
                "south" : __DIR__"eroad3",
                "east" : __DIR__"shandao1",
                "northwest" : "/d/mayi/changcheng20",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


