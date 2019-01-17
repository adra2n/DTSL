
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","朝阳峰");
  set ("long", @LONG
朝阳峰又称东峰。峰顶生满巨桧乔松，浓荫蔽日，环境非常清幽。
游人自松林间穿行，上有团团绿荫，如伞如盖，耳畔阵阵松涛，如呤如
咏，顿觉心旷神怡，超然物外。东峰由一主三仆四个峰头组成，朝阳台
所在的峰头最向，玉女峰在西，石楼峰居东，博台偏南，宾主有序，各
呈千秋。
LONG);

  set("exits", ([ 
 "westdown":__DIR__"shanlu5",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
