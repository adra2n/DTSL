
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","解脱坡");
  set ("long", @LONG
这里是峨嵋胜地解脱坡。坡下一座小桥，叫解脱桥。行人至此，坐
桥上听泉声甚美。当此良辰美景，心无芥蒂，心即解脱。坡上一座庵堂。
LONG);

  set("exits", ([ 
 "eastup":__DIR__"guanyintang",
 "west":__DIR__"shiqiao",
 "southdown":__DIR__"shanlu3",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

