
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"山崖"NOR);
	set("long", @LONG
这里是一个山崖。下面是深不见底的深渊。你向下看了看，不觉得
手脚发软。
LONG);
	set("exits", ([
		"north":__DIR__"shulin2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

