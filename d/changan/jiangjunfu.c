
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","将军府");
  set ("long", @LONG
这里是长安的一所将军府，这里安静极了，普通百姓走到这里，无
不放慢了脚步。里面住的是天策府的名将李靖和红佛女夫妇，令人不禁
肃然起敬。
LONG);

  set("exits", ([ 
 "west":__DIR__"ahdajie3",
        ]));
  set("objects",([
      "/d/job/questjob/npc/hongfu":1,
      ]));
  set("valid_startroom", 1);
  setup();
 
}

