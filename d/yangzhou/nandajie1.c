
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是扬州城的南大街。北面是扬州的中心了。远远可以听到热闹
的声音。东面是扬州最著名的妓院--春风楼，有很多姑娘站在门口招呼
来往的行人。许多喝得醉熏熏的江湖豪客正朝那边走去。
LONG);

  set("exits", ([ 
 "east":__DIR__"chunfenglou",
 "northwest":__DIR__"nanhudi2",
 "south":__DIR__"nandajie2",
        ]));
  set("objects",([
     "/d/clone/npc/dugu-xiong":1,
     ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

