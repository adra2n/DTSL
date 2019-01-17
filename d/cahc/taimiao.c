
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","太庙");
  set ("long", @LONG
太庙面积很大，大殿、二殿、三殿为庙中主要建筑。大殿对面为大
戟门，门外有玉带河。太庙是天子祭祖的地方，所以只有祭祀活动时才
显得热闹些，其他日子，只有几个太监看守，非常冷清。
LONG);

  set("exits", ([ 
 "west":__DIR__"tianjie4",
         ]));
   
  set("valid_startroom", 1);
  setup();
 
}

