
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "大路");
	set("long", @LONG
这里是一条宽敞的大路。这里已经是浙江的境地了。这里的行人渐
渐多了起来。
LONG);
	set("exits", ([
		"south":__DIR__"tulu3",
		"north":__DIR__"dalu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

