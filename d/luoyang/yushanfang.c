
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"御膳房"NOR);
  set ("long", @LONG
这里是洛阳皇宫的御膳房。这里供应每天皇宫的饭菜。厨子们正在
紧张地忙碌着，一道道菜不断地做出来，什么“扬州蒸鸡”、“西湖醋
鱼”、“雪里艳梅”，都是上等的好菜。阵阵的香气不觉得让你流下了
口水。
LONG);

  set("exits", ([ 
  
  "north":__DIR__"shijie3",
  "south":__DIR__"dongdian",
         ]));

  set("objects",([
   __DIR__"npc/chuzi1":2,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

