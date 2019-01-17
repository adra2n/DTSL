
 
inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
   set_name(HIR"心"NOR, ({"heart"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",HIR"这是一颗血淋淋的心，还微微跳动着。\n"NOR);
                set("unit", "颗");
                set("food_remaining", 15);
                set("food_supply", 60);
                set("no_drop",1);
                set("no_give",1);
                set("no_steal",1);
        }
}

int do_eat(string arg)
{
   object ob,obj;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("你要吃什么？\n");
   
   if(!objectp(obj=present(arg,ob)))
   return 0;
   
   if(obj!=this_object())
   return 0;
   
   message_vision("$N看着手中的"+query("name")+"，不禁有些发抖。\n"+
     "连忙闭上双眼，猛地张口将"+query("name")+"吞进了肚子里！！\n",ob);
   message_vision(HIB"\n$N"+HIB+"擦了擦嘴，微微抬起头，只见目光中早已充满了邪恶！\n"NOR,ob);
   
   ob->set_temp("bai_yingui/step1",1);
   
   destruct(this_object());
   return 1;
}