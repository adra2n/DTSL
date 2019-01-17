
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","永安大街");
  set ("long", @LONG
这是永安大街，北面连接长安城的景耀门，西面和永安大渠平行纵贯
长安。这里属于长安北里，是最有名的娱乐场所，青楼赌馆满街林立，东
面是风雅阁，西面是赫赫有名的上林苑。在这些青楼赌馆门外，有人大做
买卖，有摆小摊卖烧饼与脆麻花的，有炸油糕、卖鸡蛋的，热闹非常。 
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie2",
 "south":__DIR__"yadajie2",
 "east":__DIR__"fengyage",
 "west":__DIR__"shanglinyuan",
       ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

