/*
 * File    : 火山口外 (/u/yanyan/dmjob/dmjob_6_11.c)
 * Author  : [1;37m真冰河[2;37;0m(yanyan@大唐双龙  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "火山口外");
        set("long", @LONG
这里是屏风山的一个大火山口的外边。据说这座火山经常喷发，所
以这里非常炎热，四周的树木都已经枯萎。阵阵热浪已经让你觉得有些
口干舌燥了。
LONG
);
        set("exits",([
	"southeast" : __DIR__"dmjob_8_13",
	"northdown" : __DIR__"dmjob_4_11",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
