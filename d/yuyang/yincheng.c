// /d/yuyang/edao1
// Room in 渔阳
inherit ROOM;

void create()
{
	set("short", "北平郡");
	set("long", @LONG
北平郡和渔阳、安乐、涿郡、辽西并列为东北边陲五大城，因高开
道以渔阳为京，故渔阳隐成五城之首，成为该区军事经济贸易的中心，
但北平郡因其地理位置也是兵家必争之地。
LONG
	);

	set("exits", ([
                "south" : __DIR__"edao3",
                "west" : __DIR__"eroad2",
                //"southwest":"/d/xucheng/xiaolu2"
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


