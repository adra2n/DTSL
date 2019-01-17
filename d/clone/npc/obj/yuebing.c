
#include <ansi.h>
inherit ITEM;

int do_eat(string arg);

void create()
{
   set_name(HIY"月饼"NOR, ({ "yue bing","bing"}) );
   set_weight(150);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一块「桂圆蟹仁」月饼，看起来非常好吃。\n");
     set("material", "豆沙馅");
     set("unit", "块");
     set("value",100);
     set("no_sell",1);
   }
   setup();
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
   object ob;
   ob=this_player();
   if(!arg)
   return notify_fail("你要吃什么？\n");
   if(!present(arg,ob))
   return notify_fail("你身上没有这个东西！\n");
   if(this_object()!=present(arg,ob))
   return notify_fail("你还是先吃了月饼吧！\n");
   if(ob->query("combat_exp")<200000)
   return notify_fail("这个月饼不是给你的，你不能吃。\n");
   if(ob->query("give_present_eat"))
   return notify_fail("吃一块月饼就够了，吃多了会噎到的！\n");
   ob->set("give_present_eat",1);
   ob->set_skill("literate",ob->query_skill("literate",1)+5);
   if(ob->query_skill("literate",1)>300)
   ob->set_skill("literate",300);
   tell_object(ob,YEL"你几口吃掉了月饼，觉得"+HIC+"「读书识字」"+NOR+YEL+"有了些进步！\n"NOR);
   ob->set("food",1000);
   ob->set("water",1000);
   destruct(this_object());
   return 1;
}