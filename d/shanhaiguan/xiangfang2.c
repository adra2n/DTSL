// /d/gaoli/xiangfang2.c
// Room in 山海关
// rich 99/04/05
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
void create()	
{
	set("short", "厢房");
	set("long", @LONG
屋的中间有一张方桌，几个教头打扮的正在那喝酒，酒坛子遍地都
是，墙上挂着几把钢刀，还有几个人倒在床上呼呼大睡。
LONG);
set("exits", ([
                "north" : __DIR__"siheyuan",       
	]));
       setup();
	
}	
