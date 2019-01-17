
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里道路崎岖，可谓是华山的险地之一。向东望去，可以看到华山
巍峨的朝阳峰。向北望去，可以看到华山秀丽的玉女峰。站在这里极目
远眺，四周群山起伏，云霞四披，周野屏开，万种俗念，一扫而空。
LONG);

  set("exits", ([ 
 "southdown":__DIR__"shanlu5",
 "westup":__DIR__"yunvfeng",
 "east":__DIR__"shulin1",
       ]));
       
  set("objects",([
	  "/d/clone/npc/beast/yeji":1,
	  ]));
   set("no_select",1);
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
