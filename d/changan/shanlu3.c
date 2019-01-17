
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。此路通往西岳华山。这里地势险要，乱石从生，
是历来兵家、草寇必争之地。抬头望去，巍峨华山向一面铜墙铁壁耸立
于渭水之滨。
LONG);

  set("exits", ([ 
"northup":__DIR__"shanlu4",
"southwest":__DIR__"tulu2",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

