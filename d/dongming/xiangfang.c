
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"香房"NOR);
	set("long", @LONG
这里是间香房。这里供着菩萨。这里香气缭绕，你不禁被这里的气
氛所感动了。
LONG);
	set("exits", ([
	     
		
		"west":__DIR__"shilu1",
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

