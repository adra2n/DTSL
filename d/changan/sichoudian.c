
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","丝绸店");
  set ("long", @LONG
长安的丝织名闻天下，故有“ 南山树尽，织绢不竭” 之语，这里的
丝绸店就专门买以彩缬法印花成纹的绢布，把织料以针线绣出不同花纹，
染印时花纹处不能接触染料，染色后，解去线结，花纹可保留原色，倍
显华采。 
LONG);

  set("exits", ([ 
 "west":__DIR__"dongshixijie3",
         ]));
  set("objects",([
         __DIR__"npc/huoji3":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}
