
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","京兆联总堂");
  set ("long", @LONG
这里是关中第一大派－京兆联的总堂所在，近年来，杨文干率领手
下兄弟子投靠了太子党，处处和天策府作对，形势已经到了十分危急的
时刻。
LONG);

  set("exits", ([ 
 "west":__DIR__"qydajie1",
         ]));
set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}
