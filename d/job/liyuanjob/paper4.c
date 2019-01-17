
#include <ansi.h>
inherit ITEM;

int do_find();

void create()
{
        set_name("藏宝图", ({ "paper" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这是一张藏宝图，你可以使用[soucha]来查找宝物。");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("value", 300);
                set("material", "wood");
        }

        setup();
}

void init()
{
  add_action("do_find","soucha");
}
int do_find()
{
  object ob;string here;
  object baowu;
  
  ob=this_player();
  if(!ob->query_temp("liyuan_job/step"))
  return notify_fail("你看了看四周，发现宝物好象不是在这里。\n");
  here=base_name(environment(ob));
  if(here!=query("target_where"))
  return notify_fail("你看了看四周，发现宝物好象不是在这里。\n");
  baowu=new(__DIR__"baowu");
  baowu->set("target",ob);
  baowu->move(environment(ob));
  message_vision("$N找到了一个宝物！\n",ob);
  destruct(this_object());
  return 1;
}
