
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","无上洞");
  set ("long", @LONG
此处为华山的无上洞。越过苍龙岭，经五云峰度桥向上到通天门，
便可到达这里。经过这里可以到华山中峰，它有名玉女峰。从“玉女峰
”沿小道东行可到东峰。
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"jinsuoguan",
 "westup":__DIR__"lianhuaping",
 "southeast":__DIR__"xianzhangya",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
