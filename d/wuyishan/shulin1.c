
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片茂密的树林。树木遮住了阳光，显得这里清爽凉快。东
边是武夷山的上山之路。南边有一片草地。
LONG);

  set("exits", ([ 

   "east":__DIR__"shanlu1",
   "south":__DIR__"caodi1",
             ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

