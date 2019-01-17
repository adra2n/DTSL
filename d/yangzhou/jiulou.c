
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","飘香酒楼");
  set ("long", @LONG
这里是扬州城的一家历史悠久的酒楼。许多江湖好汉到了扬州，都
要到这里喝点酒。只听呼喝劝酒的声音，一派热闹的景象。店小二端着
盘子，繁忙地穿梭于各个酒桌之间，忙个不停。
LONG);

  set("exits", ([ 
 "east":__DIR__"nandajie2",
        ]));
 set("objects",([
	 __DIR__"npc/li":1,
	 ]));
 set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

