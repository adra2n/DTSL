
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长廊");
  set ("long", @LONG
这里是净念禅院的长廊。北面是禅院的诵经房。往西走可以到禅院
的厨房，从那里传来了阵阵的饭香。阵阵梵呗诵经之声，悠悠扬扬的似
从遥不可知的远处传来，传遍寺院。
LONG);

  set("exits", ([ 
	  "north":__DIR__"changlang4",
	  "southdown":__DIR__"songjingfang",
	  "westdown":__DIR__"xiaolu5",

       ]));

  
  set("valid_startroom", 1);
  setup();
 
}

