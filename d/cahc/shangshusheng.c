
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","尚书省");
  set ("long", @LONG
朝廷理政分设三省，相互制衡。分别为“尚书省”，“中书省”，“ 门
下省 ”，其中以尚书省权势最大，渐渐有了权高镇主的形势，于是朝廷
正在逐步的削减尚书省的权力，一步步把他排挤出宰相行列。
LONG);

  set("exits", ([ 
 "east":__DIR__"tianjie2",
         ]));
  
  
  set("valid_startroom", 1);
  setup();
 
}

