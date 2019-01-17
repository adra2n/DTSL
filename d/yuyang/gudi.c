// /d/yuyang/edao1
// Room in 渔阳
inherit ROOM;

void create()
{
	set("short", "谷底");
	set("long", @LONG
你顺着峡谷艰难的走着，忽然间眼前豁然开朗，阵阵花香迎面扑来。
这里风景秀丽，山水如画，空气清新。一种回归自然的感觉油然而升，使
你不禁忘记外面动荡的社会。
LONG);

	set("exits", ([
                "eastup" : __DIR__"xiagu",
                "westup" : __DIR__"xiagu1",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


