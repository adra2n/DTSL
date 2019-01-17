
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是一条土路。大风吹起，卷起黄沙阵阵，几乎迷住了你的双眼。
不时有几个人骑着马从你的身旁驰过。东北处就是陕西的名山华山了，
遥遥望去，华山隐约可见。
LONG);

  set("exits", ([ 
"northwest":__DIR__"shanlu2",
"southeast":__DIR__"tulu2",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

