
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"长廊"NOR);
	set("long", @LONG
这里是条长廊。长廊的墙壁上花着一些山水画，画工精美，看起来
是出自名工匠之手。北边是一条石路，东西两边个是一条长廊，通向其
他地方。
LONG);
	set("exits", ([
	     
		"north" :__DIR__"shilu2",
		"east":__DIR__"echanglang1",
		"west":__DIR__"wchanglang1",
		
	]));

        set("objects",([
			__DIR__"npc/shanyan":1,
			]));
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

