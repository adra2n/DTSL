
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","扁舟");
  set ("long", @LONG
这是一艘扁舟。四周是滚滚长江，浪花拍打着船头。梢公在吃力地
摆着舵。
LONG);

 set("outdoors","ship");
  set("valid_startroom", 1);
  setup();
 
}

