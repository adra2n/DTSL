
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"安国门"NOR);
  set ("long", @LONG
这里是洛阳西门。旁边还有两个边门。这里站着几个官兵，在检查
着来往的百姓。在群雄争霸的时候，洛阳城主王世充更是小心翼翼。王
世充的势力庞大，所以来投靠他的人也不少。
LONG);

  set("exits", ([ 
  

  "east":__DIR__"luoshenjie1",
  "north":__DIR__"xibianmen1",
  "southup":__DIR__"xichenglou",
  "west":"/d/changan/lguanlu2",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

