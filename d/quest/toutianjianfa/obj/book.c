
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"偷天剑谱" NOR, ({ "book","jian pu","pu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一本讲述偷天剑法的书籍。\n");
                set("unit", "本");
	        set("material", "纸");              
                set("no_save",1);               
        }
        setup();
}

int is_get_of(object ob,object obj)
{
  if(ob->query("job_office_number/马贼打劫任务")<10
  ||ob->query_skill("toutian-jianfa",1)
  ||ob->query("dtsl_quest_toutianjf_fail")
  ||ob->query("dtsl_quest_toutianjf_ok")
  ||ob->query_temp("cannot_get_jianpu")
  )
  return 0;
  
  set("owner",ob);
  
  return 1;
}

string long()
{
  object ob=this_player();
  
  if(query("owner")!=ob||
  ob->query("dtsl_quest_toutianjf_ok")
  ||query("no_use"))
   return query("long");
  
  ob->set("dtsl_quest_toutianjf_ok",1);
  ob->set_skill("toutian-jianfa",10);
  set("no_use",1);
  
  if(random(ob->query_quest_kar())<27)
  	tell_object(ob,"\n你从中领会到了一点偷天剑法的皮毛！\n");
  else{
  	tell_object(ob,"\n你从中领会到了一点偷天剑法的精髓！\n");
  	ob->set("perform_quest/toutian",1);
  }
  
  return "";
}