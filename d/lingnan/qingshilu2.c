
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是条青石路。北面是一个凉亭。清新的空气扑鼻而来，你不觉
精神一振。北边是一个凉亭，西边是宋家堡的账房，不时有外出查账的
宋家堡弟子朝里面走去。
LONG);

  set("exits", ([ 

  "south":__DIR__"qingshilu1",
  "north":__DIR__"liangting2",
  "west":__DIR__"zhangfang",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

