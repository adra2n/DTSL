
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片绿油油的草地，上面已经有一条由过往行人踩出的一条
小路，地上有很多漂亮的野花、蒲公英等植物。不时有野兔从你的脚旁
跳过。前面不远处有一片树林。
LONG);

  set("exits", ([ 
  "north":__DIR__"shulin",
  "south":__DIR__"caodi2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","xiangyang");
  setup();
 
}

