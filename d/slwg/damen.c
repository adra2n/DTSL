
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "大门");
	set("long", @LONG
这里是石龙武馆的大门。两扇黑漆木门两边是一对石刻的狮子，大
门上横悬的匾额上是用隶书写成的石龙武馆四个大字。有很多石龙弟子
在这里出出入入，显得非常热闹。
LONG
);


	set("exits", ([
		"north" :__DIR__"zoulang1",
                "southeast":"/d/yangzhou/xidajie2",
	]));
	set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    __DIR__"npc/shifu2":1,
	    "/d/quest/csj/npc/shilong":1,
	    ]));
       set("outdoors", "扬州");
	setup();
}

int valid_leave(object ob,string dir)
{
   if(ob->query("combat_exp")>=20000&&dir=="north")
     return notify_fail("里面弟子喊道：阁下武功这么高，难道是想踢馆么？\n");
   return ::valid_leave(ob,dir);
}