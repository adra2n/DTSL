
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","古董店");
  set ("long", @LONG
这里是一家古董店。最近钱财紧缺，似乎没有人愿意把钱财花费在
这里，所以这里的生意不是很好。由于官府无能，虽然老板同官府签定
保护和约，但强盗还是洗劫了这里多次。虽然门口的金字招牌还在，但
现在这里已经是人去楼空了。
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie3",
        ]));
set("valid_startroom", 1);
  setup();
 
}

