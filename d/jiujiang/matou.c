
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"matou"
#define TO __DIR__"jiangbei"
#include "/std/shiproom.c";
void create ()
{
  set ("short","九江码头");
  set ("long", @LONG
这里是九江的码头，这里船只非常多，多为南来北往的商人。南边
就是就是九江的北门了。在这里你可以叫船(yell boat)来过江。
LONG);

  set("exits", ([ 

  "south":__DIR__"beimen",
  "west":"/d/job/sjbjob/gangkou2",
         ]));
set("outdoors","jiujiang");
  set("valid_startroom", 1);
  setup();
 
}

