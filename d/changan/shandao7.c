
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","终南山道");
  set ("long", @LONG
这里是一条终南山脚的山路。这里的行人不是很多，四周丛林密布，
鲜花绿草若隐若现，随着山谷里吹来的阵阵清风，传来哗哗的松涛声和
一些淡淡的花香。
LONG);

  set("exits", ([ 
"northdown":__DIR__"shangu",
"southeast":"/d/luoyang/caishichang",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

