
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","隆中");
  set ("long", @LONG
这就是三国时期诸葛孔明隐居世外之处。昔日的桃源之景依稀可见。
四周树木茂盛，远处秀丽的风景映入眼帘，四周四周丛林密布，鲜花绿草
若隐若现，不时有鸟儿从你的头上飞过。
LONG);

  set("exits", ([ 
  "southwest":__DIR__"shulin1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","xiangyang");
  setup();
 
}

