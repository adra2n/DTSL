
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。宋家堡已经可以清晰的看到了。据说在岭南，宋家
堡是称雄一方，就是朝廷也奈何他们不得。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu3",
 "southwest":"/d/lingnan/dalu2",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

