
inherit ROOM;
 void create()
{
       set("short", "沙石路");
       set("long", @LONG
这里是条沙石路。这里的天气非常热，空气也是非常潮湿，所以路
上没有什么尘土。
LONG);
       set("exits", ([
               "north" : __DIR__"jiangan2",
               "southwest" : __DIR__"shalu2",
                    ]));

       setup(); 
       replace_program(ROOM);
}


