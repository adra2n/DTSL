
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里的景色十分秀丽。不时有游人和你擦肩而过。鲜花绿草若隐若
现，随着山谷里吹来的阵阵清风，传来哗哗的松涛声和一些淡淡的花香。
沿这条路上去，就是峨眉山了。
LONG);

  set("exits", ([ 
 "westup":__DIR__"shanlu4",
 "eastdown":"/d/chengdu/tulu2",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

