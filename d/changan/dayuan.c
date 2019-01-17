
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","镖局大院");
  set ("long", @LONG
这里是威远镖局的大院。远处有几个弟子在练习武艺，旁边还有几
名镖师在指点他们。这里经常进进出出几个有钱的财主，或是长安的官
宦，看来是要托镖的。
LONG);

  set("exits", ([ 
 "west":__DIR__"biaoju",
       ]));
  set("objects",([
	  __DIR__"npc/wushi":1,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

