

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","同兴社");
  set ("long", @LONG
这是一间营办水运生意的店铺，门口聚集着似属帮会人马的武装大
汉，透出一种紧张得异乎寻常的气氛。传闻这里的帮会背后有一股很强
大的力量在暗中支持，就连太子，齐王等力量也不一定能比得上。东面
就是永安大渠的码头。
LONG);

  set("exits", ([ 
 "south":__DIR__"tydajie1",
 "east":__DIR__"matou",
       ]));
  set("valid_startroom", 1);
  setup();
 
}

