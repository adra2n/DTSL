inherit ROOM;

void create()
{
	set("short", "码头");
	set("long", @LONG
这里是荥泽的码头，大运河在这里和洧水的物资在这里交汇，是船
只转驳的地点，从这里卸船，运往荥阳，而荣阳则是南船北马的转运处。	
LONG );

	set("exits", ([
               "southeast"      : __DIR__"xingze",
		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



