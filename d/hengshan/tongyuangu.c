// Room: /d/hengshan/tongyuangu.c
#include <room.h>
inherit "/std/lingwuroom2";

void create()
{
        set("short", "通元谷");
        set("long", @LONG
通元谷孤处见性峰下，相传为张果老成仙前修道之所，由于他道号
 "通元" ，这里也就成了通元谷。
LONG);
        set("exits", ([
           "eastup"  : __DIR__"guolaoling",
        ]));
        set("outdoors", "hengshan");
        setup();
}
