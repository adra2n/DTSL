
inherit ITEM;
#include <ansi.h>
int do_mix(string arg);
void create()
{
        set_name(HIW"面粉"NOR, ({"mianfen"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "块");
           set("yrs","mianfen");
           set("long", "这是一块凝固的面粉．\n");
        }
}

void init()
{
  add_action("do_mix","mix");
}

int do_mix(string arg)
{
  object ob;
  object target;
  object result;
  string name;
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return notify_fail("你把面粉翻来覆去地看，看不出什么端倪.\n");
  if(!arg||sscanf(arg,"with %s",name)!=1)
  return notify_fail("你要把面粉同什么混合在一起？\n");
  if(!objectp(target=present(name,ob)))
  return notify_fail("你身上没有这个东西！\n");
  if(target->query("yrs")!="shila")
  return notify_fail("面粉不能同"+target->name()+"混合在一起！\n");
  message_vision(YEL"$N把"+query("name")+"和"+target->name()+"混合起来。\n"NOR,ob);
  result=new(__DIR__"mixed");
  result->move(ob);
  destruct(target);
  destruct(this_object());
  return 1;
}