
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是片草地。草地细密柔软，走起路来非常舒服。有几个丫鬟从
东边进进出出。东边就是宋玉致的卧室了。
LONG);

  set("exits", ([ 

  "north":__DIR__"huayuan3",
 "east":__DIR__"woshi3",
     ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

