
#include <ansi.h>
#include <job_money.h>
inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangan1"
#define TO __DIR__"jiangan2"
#include "/std/shiproom.c";
void create ()
{
  set ("short","长江北岸");
  set ("long", @LONG
这里是长江的北岸。过了长江，就到了云南的境地了。眼前江水滚
滚，只有一叶扁舟摆渡来往的行人。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"caodi1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

