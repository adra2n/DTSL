
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","终南山道");
  set ("long", @LONG
这里是一条终南山脚的山路。这里的行人不是很多，四周丛林密布，
鲜花绿草若隐若现，随着山谷里吹来的阵阵清风，传来哗哗的松涛声和
一些淡淡的花香。
LONG);

  set("exits", ([ 
"northdown":__DIR__"guanlu4",
"southup":__DIR__"shandao1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_jump","jump");
	
}

int do_jump(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(!arg) return 0;
   if(arg!="ya"&&arg!="崖") return 0;
   
   message_vision("$N纵身朝山崖下跳去！\n",ob);
   
   ob->move("/d/clone/room/iron/room2");
   
   return 1;
   
}