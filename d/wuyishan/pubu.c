
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"瀑布"NOR);
  set ("long", @LONG
这里是个瀑布。阵阵的轰鸣声音震的你的耳朵有些发麻。瀑布宛如
一道白色帘子，从天而降，击打在岩石上，又蹦碎成粒粒的珍珠。
LONG);

  set("exits", ([ 

   "west":__DIR__"shanlu4",
          ]));
 set("objects",([
 "/d/yinkui/npc/wanwan":1,
     ]));
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

