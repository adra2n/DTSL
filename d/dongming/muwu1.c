
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"木屋"NOR);
	set("long", @LONG
这里是间木屋。是守山弟子住宿的地方。床上的被褥叠得整整齐齐
。墙上挂着几把长剑，几名弟子正注视着出入的行人。
LONG);
	set("exits", ([
		"east":__DIR__"shilu1",
		
	]));
   set("objects",([
	   __DIR__"npc/dizi":2,
	   ]));
        
       set("valid_startroom", 1);   
	setup();
       
       
}

