
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是襄阳的西街。北面是襄阳的官府。由于现在各路英雄各自称
王，所以官府也就是名存实亡。只有几个官兵懒散地站在那里，一副恹
恹欲睡的样子。东边就是襄阳城的中心了。
LONG);

  set("exits", ([ 
 "east":__DIR__"guangchang",
 "west":__DIR__"xidajie2",
 "enter":"/d/clone/room/cityroom/xiangyang",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

