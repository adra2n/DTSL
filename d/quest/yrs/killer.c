
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("老板娘",({ "laoban niang","laoban"}) );
        set("gender", "女性" );
        set("age", 32);
   set("long","他是悦来客栈的老板娘。\n");
   set("max_kee",300);
   set("max_gin",300);
   set("max_sen",300);
   set("combat_exp",200000);
   setup();
   carry_object(__DIR__"obj/caidao")->wield();
   carry_object(__DIR__"obj/skin");
  
}
void die()
{
  message_vision(HIR"$N撕心裂肺地喊道：老娘做鬼也不会放过你们！！！\n"NOR,this_object());
  return ::die();
}