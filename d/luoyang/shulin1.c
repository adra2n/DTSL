
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一个树林。不时有武林人士结伴而过。一阵冷风吹来，你不
禁提高了警惕。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"xiaolu8",
  "southwest":__DIR__"shulin2",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

