
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"慈航静斋"NOR);
  set ("long", @LONG
这里是一个斋院的门前。只见门上横着一块「慈航静斋」的门匾。
这里寂静无声，隐隐约约能听到斋院里面诵经的声音。只觉这里超凡脱
俗，庄严肃穆。
LONG);

  set("exits", ([ 

  "enter":__DIR__"suishilu1",
  "southdown":"/d/changbaishan/shanlu5",
       ]));
  set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));
set("outdoors","jingzhai");
  
  set("valid_startroom", 1);
  setup();
  "/obj/board/party_jz_b.c"->foo();
}

int valid_leave(object me,string dir)
{
  if(me->query("gender")=="男性"&&
     present("di zi",environment(me))&&
     dir=="enter")
  return notify_fail("弟子伸手拦住了你：慈航静斋禁止男子入内！\n");
  return ::valid_leave(me,dir);
}
