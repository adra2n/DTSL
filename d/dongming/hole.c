
inherit ROOM;
#include <ansi.h>
int do_enter(string arg);
void create()
{
	set("short", HIB"假山洞"NOR);
	set("long", @LONG
这里是假山的洞中。四处黑黑的，不见五指。潮湿的气体扑进你的
鼻中。这里看起来阴森恐怖，你不禁小心起来。
LONG);
	set("exits", ([
		"out":__DIR__"jiashan",
			]));
 if(sizeof(children(__DIR__"obj/qingmingjian"))<2)
      set("objects",([
		  __DIR__"obj/qingmingjian":1,
		  ]));
       set("valid_startroom", 1);   
set("no_clean_up",1);
       set("outdoors", "青石路");  
	setup();
       
       
}

