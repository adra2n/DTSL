
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"石阶"NOR);
	set("long", @LONG
这里是一级级的向上的石阶。在往前走就是平坦的青石路了。里面
传来练习武艺的呼喝声。旁边还立着一个石碑「bei」。
LONG);
	set("exits", ([
	     
		"northdown" :__DIR__"shijie2",
		"south":__DIR__"shilu1",
		
	]));
	set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
	set("item_desc",([
		"bei":GRN"东溟茫茫\n飘然若梦\n"NOR,
		]));
        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

