
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"听雨轩"NOR);
	set("long", @LONG
这里是「听雨轩」。平时经常有东溟派弟子在这里休息乘凉。这里
有一幅对联：秋雨密如线，不及愁思稠。字迹清秀，虽然看起来已经时
日已久，但依然颜色不褪。
LONG);
	set("exits", ([	     		
		"north":__DIR__"caodi2",	
		"south":__DIR__"wuchang",				
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

