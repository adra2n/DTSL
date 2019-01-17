

#include <ansi.h>
inherit ROOM;
#include <job_money.h>

void create ()
{
  set ("short","城隍庙");
  set ("long", @LONG
这里是长安的城隍庙，这座寺庙的规模很大，几乎可以和扬州的城
隍庙相媲美。每天来这里烧香供佛的人络绎不绝。这里供着一尊神仙，
高高在上，面含微笑。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshidongjie5",
 
        ]));
  set("objects",([
   "/d/clone/npc/potnpc":1,
   ]));
   
  set("valid_startroom", 1);
  setup();
 
}
