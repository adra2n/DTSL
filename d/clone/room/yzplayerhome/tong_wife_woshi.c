
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIM"卧室"NOR);
	set("long", @LONG
这里是霜刀居的卧室。中间放着一张大床，床上的被褥叠得
整整齐齐。右边有一个梳妆台，梳妆台的旁边还挂着两把刀，分
别刻着君子和淑女二字。床头上还放着几本书，看名字似乎是谈
论当今天下帮会大事的内容。屋子的左边有一个衣架，上面挂着
几件衣服。
LONG);
    set("exits", ([
	        "east":__DIR__"tong_and_wife",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
