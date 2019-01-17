
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","观音堂");
  set ("long", @LONG
观音堂高踞坡岗，近临危崖，环境幽静，四周树木蓊郁，悦目赏心。
传说入山于此，解脱尘凡；出山于此，解脱险阻，又故名解脱庵。进山的
人在此焚香洗心，入山方可化险为夷，步步平安。
LONG);

  set("exits", ([ 
 "westdown":__DIR__"jietuopo",
      ]));
  set("objects",([
     __DIR__"npc/xiangke":1,
     ]));
 set("valid_startroom", 1);
  setup();
 
}

