
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","威远镖局");
  set ("long", @LONG
这里是长安最大的镖局--威远镖局的门口。门口的两旁是两个石狮
子，威武无比。门口立着一个大旗杆，上面飘扬着一面大旗，上面写着
四个大字：威远镖局。有很多人进进出出，来这里托镖。门口站着几个
护卫，招呼着进出的客人。
LONG);

  set("exits", ([ 
 "west":__DIR__"csdajie2",
 "east":__DIR__"dayuan",
       ]));
  set("objects",([
	  __DIR__"npc/biaoshi":1,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

