//baimo by 2001/9/24

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short",HIW"巫师接待室"NOR);
  set ("long", @LONG
这里是巫师接待玩家的地方。这里有一个留言板，上面有玩家对
skills 意见。
LONG);

  set("exits", ([ 
 "east":"/d/yangzhou/xiaolou",
         ]));
  
    setup();
  call_other("/obj/board/skill_b", "???"); 
  
}


