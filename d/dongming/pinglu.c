
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"小路"NOR);
	set("long", @LONG
你到了一个平坦之处。地上铺着方砖，一直通向前方。南边是一个
石阶。西面有一个木屋。
LONG);
	set("exits", ([
	     
		
		"west":__DIR__"muwu2",
	
		"southdown":__DIR__"shijie5",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

