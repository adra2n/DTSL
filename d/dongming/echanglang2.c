
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"东廊"NOR);
	set("long", @LONG
这里是东廊。有几名东溟派弟子从你的身旁匆匆走过。北边是一片
草地，南边是一个凉亭，远远可以看到「青竹亭」三个大字，有几名东
溟派弟子正在那里聊天乘凉。
LONG);
	set("exits", ([
	     
		
		"north":__DIR__"caodi1",
		"west":__DIR__"echanglang1",
		"south":__DIR__"qingzhuting",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

