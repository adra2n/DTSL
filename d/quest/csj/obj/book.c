
#include <ansi.h>
inherit ITEM;
int do_look(string arg);

void create()
{
        set_name(YEL"长生诀" NOR, ({ "book"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	        set("material", "纸");
                set("no_drop",1);
                set("no_sell",1);
                set("no_give",1);
                set("no_steal",1);
                set("no_save",1);
        }
        setup();
}
void init()
{
  add_action("do_look","kan");
 
}
int do_look(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="长生诀")
  return notify_fail("你要看什么？\n");
  if(ob->query_skill("changsheng-jue",1)>=20)
  return notify_fail("这本书已经没什么用了，你还是在山洞中领悟吧！\n");
  if(ob->query("gin")<20)
  return notify_fail("你精神恍惚，无法继续看下去！\n");
  if(ob->query("kee")<20)
  return notify_fail("你感觉气血翻泳，无法继续看下去！\n");
  tell_object(ob,"你排除心中的杂念，看着书上的文字，觉得有了些收获。\n");
  ob->receive_damage("gin",20);
  ob->receive_damage("kee",20);
  ob->improve_skill("changsheng-jue",ob->query_int()/6+5);
  return 1;
}

int is_get_of(object pal,object ob)
{
 if(!pal->query("dtsl_quest_csj_ok"))
 return notify_fail("你不能拿起那本书！\n");
 return 1;
}
