
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIB"碧海仙洞"NOR);
  set ("long", @LONG
这里是东溟派的碧海堂。看不出来在山洞之中还有这么舒服
的地方。这里摆设豪华，右边石洞口外就是一望无际的大海。一
阵风吹过，清凉的海风拂面，顿时觉得舒服多了。这里是东溟派
弟子领悟lingwu东溟内功心法--东溟心法的地方。
LONG);

  set("exits", ([ 
 "up":__DIR__"shanya",
        ]));
  set("no_channel","领悟中还是不要说话了\n");
  set("no_tell","领悟中还是不要说话了\n");
  set("valid_startroom", 1);
  set("force","bihai-force");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
