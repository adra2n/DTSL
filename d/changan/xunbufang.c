
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","巡捕房");
  set ("long", @LONG
这里是长安的巡捕房，每天有很多犯人都被抓到这里。近来由于战
乱，作奸犯科的事更是屡屡发生，所以这里的捕头近来都是很忙。
LONG);

  set("exits", ([ 
 "west":__DIR__"csdajie1",
      ]));
  set("objects",([
    "/d/job/butoujob/butou":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

