// /d/zhuojun/dadao3.c
// Room in 涿郡
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，此处人群稀少，四周也静悄悄的。
LONG
        );
set("outdoors", "/d/zhuojun");
set("exits", ([
                "northwest":"/d/yuyang/chalu",  
                "southwest":__DIR__"dadao2",    
	]));
       setup();
	replace_program(ROOM);
}
