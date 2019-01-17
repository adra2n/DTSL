
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","翠灵宫");
  set ("long", @LONG
翠灵宫为木石结构，依崖就势而筑。外廊明柱，雕梁画栋，镂花门
窗，其风格秀丽典雅。宫分前后两殿，上下两层，东西各建有配殿，将
前后两殿沟通连为一体。后殿门额悬有翠云宫牌匾，殿内供奉众星之母
斗姥神位，塑像神态威严端庄。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"lianhuaping",
 "westup":__DIR__"julingzu",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
