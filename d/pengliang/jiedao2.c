inherit ROOM;


void create()
{
	set("short", "街道");
	set("long", @LONG
这里是彭城的南北的主干道，彭城毁于契丹马贼之手，少帅军占领
彭梁以后，开始重建彭城，工程好象还在继续，街道的两旁房屋有的刚
刚建好，有的还在架设房屋的主架。
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"northeast" : __DIR__"jiedao1",
                "west" : __DIR__"gongdi1",
                 "east" : __DIR__"gongdi2",
                "southeast" : __DIR__"jiedao4",
	]));
	set("objects",([
	 __DIR__"npc/shaoshuaijun":1,
	 ]));
	setup();
	replace_program(ROOM);
}

