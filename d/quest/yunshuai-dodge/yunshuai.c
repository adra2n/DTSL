
inherit NPC;
#include <ansi.h>

int do_action1();

void create()
{
        int i;
        object *ob;
        
        set_name("云帅",({ "yun shuai","yun","shuai"}) );
        set("gender", "男性" );
        set("age", 42);
        set("str",30);
        set("long","他身形并不魁梧，却高挺潇洒，浑身含蕴非凡的力量。\n");
        set("combat_exp",700000);
        
        set("max_kee",2000);
        set("max_sen",2000);
        set("max_gin",2000);
        set("max_force",2000);
        set("force",2000);
        set_skill("parry",150);
        set_skill("dodge",150);
        set_skill("force",150);
        
        set_skill("blade",150);
        set_skill("leveltwo-blade",150);
        set_skill("jiuying-dodge",150);
        
        set("inquiry",([
          "莲柔":(:do_action1:),
        ]));
        
    setup();
   ob=children(__DIR__"obj/wanyue-dao");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"你手中的"+ob[i]->query("name")+"被它的主人收回去了！\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"被一阵风卷走了。\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/wanyue-dao")->wield();
  
}

void init()
{
  object *ob;
  int i;
  
  ob=all_inventory(environment(this_object()));
  
  if(!sizeof(ob)) return;
  for(i=0;i<sizeof(ob);i++){
   if(ob[i]->query("daughter")=="lianrou")
    command("guard "+ob[i]->query("id"));
  }
   
}

int do_action1()
{
  object ob;
  int flag=0;
  
  ob=this_player();
  
  if(ob->query("dtsl_quest_ysdodge_ok")){
    command("bow "+ob->query("id"));
    return 1;
  }
  
  if(ob->query_skill("jiuying-dodge",1)<100){
    command("say 莲柔是我女儿，你找她有什么事？");
    return 1;
  }
  command("say 敢随便打听我女儿的消息，我看你是欠扁！！\n");
  flag+=COMBAT_D->do_attack(this_object(),ob,query_temp("weapon"),0,1);
  flag+=COMBAT_D->do_attack(this_object(),ob,query_temp("weapon"),0,1);
  flag+=COMBAT_D->do_attack(this_object(),ob,query_temp("weapon"),0,1);
  if(flag>=3){
   command("say 你的武功太低了，嘿嘿，简直不值得我动手！");
   return 1;
  }
  command("? "+ob->query("id"));
  command("say 你怎么会我的轻功？是她交给你的吗？");
  ob->set_temp("dtsl_quest_ysdodge_action1",1);
  
  return 1;
}

int accept_object(object ob,object obj)
{
   object book;
   
   if(!obj->query("lianrou_blade"))
    return 0;
   if(obj->query("user")!=ob->query("id"))
    return notify_fail("这是她给你的刀吗？？\n");
   
   command("say 原来你就是救她的英雄！");
   command("bow "+ob->query("id"));
   
   book=new(__DIR__"obj/miji2");
   
   book->move(ob);
   message_vision("$N给了$n一"+book->query("unit")+book->query("name")+"。\n",
   this_object(),ob);
   ob->set("dtsl_quest_ysdodge_ok",1);
   
   return 1;
}
   