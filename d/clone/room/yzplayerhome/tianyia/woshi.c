
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","卧室");
	set("long", @LONG
这里是主人夫妇的卧室。中间放着一张大床，床上的被褥叠
得整整齐齐。右边有一个衣柜，屋子的左边有一把椅子 (chair)
和一个写字台(desk)，上面放着几本书。里面就是婴儿室了。
LONG);
    set("exits", ([
	        "enter" : __DIR__"yingershi",
	        "down":__DIR__"shanzhuang",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
