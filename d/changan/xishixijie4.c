
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市西街");
  set ("long", @LONG
你来到了闻名长安的西市－利人市，这里是利人市的西街，到处都
是前来逛集市的人。吆喝声，叫卖声不绝于耳。
LONG);

  set("exits", ([ 
  "north":__DIR__"xishixijie3",
  "south":__DIR__"xishixijie5",
  "west":__DIR__"xishixikou2",
  "east":__DIR__"xishidongjie4",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

