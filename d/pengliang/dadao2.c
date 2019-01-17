inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
你走在一条尘土飞扬的大道上。以往四周人来人往。挑担子的行商，
赶着大车的马夫，熙熙攘攘，非常热闹。现在因为战乱的原因你已经看不
到几个行人了。
LONG);

	set("exits", ([
		"west":"/d/xingyang/dadao4",
                "south":__DIR__"beichengmen",
                "east":"/d/yangzhoubei/shalu2"
	]));

 	set("outdoors","/d/pengliang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}


