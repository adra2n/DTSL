#include <room.h>
inherit ROOM;
void create()
{
        set("short", "独一味");
        set("long", @LONG
提起“独一味”方圆百里无人不知。这里各式菜肴均是一绝。可是
由于战乱的原因。整个大堂里没有几个人。店小儿在那里打瞌睡。
LONG);
        set("exits", ([
            "north"  : __DIR__"dongdajie",
        ]));
        set("objects", ([
            __DIR__"npc/xiaoer2" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
