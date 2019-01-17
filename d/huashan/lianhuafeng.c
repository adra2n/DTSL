
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","莲花峰");
  set ("long", @LONG
莲花峰为一块完整巨石，浑然天成。西北绝崖千仗，似刀削锯截，
其陡峭巍峨、阳刚挺拔之势是华山山形之代表。因此古人常把华山叫莲
山。登西峰极目远眺，四周群山起伏，云霞四披，周野屏开，黄渭曲流，
置身其中若入仙乡神府，万种俗念，一扫而空。
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"julingzu",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
