

inherit ROOM;

void create ()
{
        set ("short", "乐泉馆");
        set ("long", @LONG
这里是除了明堂窝和六福赌馆之外，长安最有名的赌场。由于最近
以来，那两个赌场一直都在明争暗斗，经常出事，所以不少赌客都改到
这里来碰运气。
LONG);

        set("exits", 
        ([
     "west" : __DIR__"hgdajie3",
        ]));
        set("objects",([
         "/obj/mj":1,
         ]));
         
        setup();
   replace_program(ROOM);
}


