
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","春明门");
  set ("long", @LONG
这是长安城的东门--春明门，城门正上方刻着“春明门”几个楷书大
字，城墙上贴着几张官府告示。官兵们警惕地注视着过往行人，你最好
小心为妙。一条笔直的青石板大道向东西两边延伸。东边是郊外，隐约
可见一片一望无际的树林及山脉，神秘莫测。
LONG);

  set("exits", ([ 
"west":__DIR__"gmdajie1",
"east":__DIR__"guanlu1",
"north":__DIR__"xiaolu0",
"south":__DIR__"xiaolu7",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

