
inherit ITEM;
#include <ansi.h>

void create()
{
   set_name(HIB"《雷霆锤法》"NOR, ({ "book" }));
   set_weight(300);
   set("unit", "本");
   set("long","这是东溟派的武功秘籍《雷霆锤法》。\n");
  
 
}


int is_get_of(object me,object ob)
{
   if(me->query("family/family_name")!="东溟派"||
      query("owner_ob")!=me)
   return notify_fail("你捡不起来这本书！\n");
   return 1;
}

string long()
{
   object ob;
   
   ob=this_player();
   
   if(environment(this_object())!=ob
    ||ob->query("perform_quest/pili")
    ||ob->query("perform_quest/duomeng")
    ||ob->query("perform_quest/yanyu")
    ||query("owner_ob")!=ob
     )
   return query("long");
   tell_object(ob,"你看着书上的招式，终于明白了雷霆锤法的精髓之处！\n");
   ob->set("perform_quest/pili",1);
   return "";
}