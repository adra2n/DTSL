
#include <ansi.h>
inherit ROOM;


void create ()
{
    set ("short","水坊桥");
  set ("long", @LONG
这里是洛阳的水坊桥了。这里的风景更是令人留连忘返。正所谓[
白虎御柳碧遥遥，轩骑相从半下朝]。
LONG);

  set("exits", ([ 
  

  "northdown":__DIR__"baihujie3",
  "southdown":__DIR__"baihujie4",

	  ]));
set("outdoors","luoyang");
  
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
   string msg;
   
   ob=this_player();
   
   if(!arg||arg!="down")
   return 0;
   
/*
   if(ob->query("family/family_name")!="花间派")
   return 0;
   if(ob->query("execute_quest/busiyin"))
   return 0;
*/
   msg="$N看看四下无人，纵身一跃，朝桥下的船中跳去！\n";
   message_vision(msg,ob);
   ob->move(__DIR__"xiaochuan");
   return 1;
}
