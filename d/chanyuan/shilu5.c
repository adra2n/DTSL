
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","石路");
  set ("long", @LONG
这里是净念禅院的石路。往西走就是禅院的禁地了。有几个和尚在
这里守护。阵阵梵呗诵经之声，悠悠扬扬的似从遥不可知的远处传来，
传遍寺院。
LONG);

  set("exits", ([ 
	  "east":__DIR__"houmen",
	  "west":__DIR__"shilu4",
  
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(dir=="east"&&objectp(present("bu pen",environment(me)))&&objectp(present("bu tan",environment(me)))&&!wizardp(me))
		return notify_fail("只听一声洪亮的声音说道：施主请留步!\n");
	return ::valid_leave(me,dir);
}
