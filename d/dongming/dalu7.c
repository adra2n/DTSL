
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "大路");
	set("long", @LONG
这里是一条大路。经常有人骑着马从你的身旁驰过。一条笔直的石
板大道通向前方，路上不时的有南来北往的车马经过，不少行人手持各
种兵器，看来都是习武之人。
LONG);
	set("exits", ([
                "south":__DIR__"dalu6",
		"northwest":__DIR__"guanlu1",
   "north":"/d/quest/yrs/heidian",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

