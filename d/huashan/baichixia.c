
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","百尺峡");
  set ("long", @LONG
百尺峡是登华山的第二个险境。“百尺峡”也叫“百丈崖”，乃是
一处危石耸峙，直插云表，令人望而生畏的地方。峡的两壁几乎就要紧
贴在一起，中间却被两颗石块撑开，人从石头下钻过，胆战心惊，生怕
石块从两壁间掉下来。
LONG);

  set("exits", ([ 
 "eastup":__DIR__"konglingfeng",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
