
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","武德殿");
  set ("long", @LONG
武德殿建于单层石台基之上，四周以黄绿琉璃砖围砌透风灯笼矮墙。
宫面阔七间，进深三间，单檐歇山式顶。檐廊柱枋间为镂空云龙套环枋
下云龙雀替，皆饰浑金，堂皇富丽。齐王李元吉就住在这里。
LONG);

  set("exits", ([ 
 "west":__DIR__"xineiyuan",
         ]));
  set("objects",([
          "/d/cahc/npc/liyuanji":1,
          ]));

    
  set("valid_startroom", 1);
  setup();
 
}

