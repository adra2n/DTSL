
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是条沙石路。风沙很大，你不由闭紧了双眼。再往南走就出了
河南的境地而进入安徽的境内了。
LONG);

  set("exits", ([ 
 "west":__DIR__"shalu3",
 "northeast": "/d/xingyang/xiaolu2",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

