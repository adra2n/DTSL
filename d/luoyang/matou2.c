
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","码头");
  set ("long", @long
洛阳城中河流交错纵横，可是说到处都能泊船，但是停泊大型舰船
也必须要专用码头才可以。这里就是经过开合桥后停泊船只的地方。
long);

  set("exits", ([ 
      "south":__DIR__"shennvdi1",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

