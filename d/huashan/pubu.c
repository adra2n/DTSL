
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"瀑布"NOR);
  set ("long", @LONG
这里是一瀑布。瀑布从上而降，看起来有两三丈高，阵阵的轰鸣声
音阵得你耳朵有些发麻。水流飞溅，你的衣衫有些湿了。你不禁想到，
站到瀑布下面的感觉会是什么样子？
LONG);

  set("exits", ([ 
 "west":__DIR__"liandanlu",
 "enter":__DIR__"shui",
      ]));
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
