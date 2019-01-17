
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","云步桥");
  set ("long", @LONG
这里是泰山的云步桥。走到这里，你已经是身入云端了。白云就飘
散你的周围，下面是深不见底的深渊。
LONG);

  set("exits", ([ 

   "eastup":__DIR__"wusongting",
   "southdown":__DIR__"zhongtianmen",
          ]));
  set("objects",([
     __DIR__"npc/xiake":1,
     ]));
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

