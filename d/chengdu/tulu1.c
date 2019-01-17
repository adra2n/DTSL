
inherit ROOM;
 void create()
{
       set("short", "土路");
       set("long", @LONG
这是一条尘土飞扬的小路，因为四川自古就是富庶之地，所以放眼
望去，四周的田垅里郁郁青青。往南边走就是长江的岸边了。
LONG);
       set("exits", ([
               "northeast" : __DIR__"tulu2",
               "south" : __DIR__"caodi1",
                    ]));

       setup(); 
       replace_program(ROOM);
}


