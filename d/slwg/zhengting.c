
#include <room.h>

inherit ROOM;

string show_msg();

void create()
{
	set("short", "正厅");
	set("long", @LONG
这里是石龙武馆的正厅。北边可以到石龙的卧室。东边是武馆练习
武艺的练功房，西边是武馆弟子休息、吃饭的地方。方厅的正上方悬挂
着一个牌子，上面写着四个大字“石龙武馆”。这里还悬挂着一个大牌
子(pai)。
LONG
);


	set("exits", ([
		"north" :__DIR__"beilang1",
                "southdown":__DIR__"zoulang2",
                "eastdown":__DIR__"donglang1",
                "west":__DIR__"xilang1",
	]));
	
	set("item_desc",([
	    "pai":(:show_msg:),
	    ]));
	
	set("objects",([
	    __DIR__"npc/shifu":1,
	    ]));
       set("no_fight",1);
      // set("outdoors", "slwg");
	setup();
}

string show_msg()
{
  
write(@LONG
    欢迎你来到大唐双龙！做为新人，您需要在石龙武馆接受一定
的训练，才可以出去闯荡江湖。在武馆中，你可以通过切磋武艺和
练习武艺来增加经验。如果你想练习武艺，可以到花园找张教头，
向他询问“武艺”的消息，他会告诉你如何做。如果你想切磋武艺，
要先和练武场的弟子切磋功夫，等经验达到 10，000，你可以到练
功房去和教头切磋武艺来增加经验。当你的经验积累到 20，000，
你就可以出武馆去闯荡江湖了。武馆的西边有厨房和休息室。
    在武馆里学习武艺需要钱财，你可以到账房中取出存款。
    在厨房你可以向厨子询问“食物”或“水”来解决温饱问题。
    如果你在切磋武艺过程中受伤，请到北边的疗伤室疗伤。
    
    祝您在大唐双龙玩得开心！
LONG);
 return "\n";
}