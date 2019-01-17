/*
 * File    : 屏风山口 (/u/yanyan/dmjob/dmjob_0_13.c)
 * Author  : [1;37m真冰河[2;37;0m(yanyan@大唐双龙  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "屏风山口");
        set("long", @LONG
这里是屏风山口的入口处了。只见两旁山林耸立，深入云端，地势
非常险要。前方是一条碎石路，四周不时传来鸟鸣叫的声音。这里景色
秀丽，空气清新。
LONG
);
        set("exits",([
        "northup":"/d/dongming/shanya2",
	"south" : __DIR__"dmjob_2_13",
        ]));
set("outdoors","dmjob");
        setup();
        replace_program(ROOM);
}
