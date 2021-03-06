
#include <ansi.h>

inherit NPC;

int do_action1();
int do_action2();

void create()
{
   set_name("郑石如",({ "zheng shiru","zheng"}) );
        set("gender", "男性" );
	set("title","河南狂士");
        set("age",32);
   set("long", "他就是人称「河南狂士」的郑石如。\n");
       
   set("combat_exp",300000);
   set("str", 25);
   set("per", 25);
  
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",150);
   set_skill("sword",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-huanzong",130);
   set_skill("jiutian-huanzhang",130);
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1500);
   set("max_force",1500);
   
   set("inquiry",([
     "阴癸派":(:do_action1:),
     "拜师":(:do_action2:),
     ]));
  
   setup();
  
}


int do_action1()
{
    object ob,heart;
    
    ob=this_player();
    
    if(ob->query("family")){
      if(ob->query("family/family_name")!="阴癸派"){
        command("kok "+ob->query("id"));
        command("say 阴癸派乃江湖神秘之派，你连这都不知道？？\n");
        return 1;
      }
      
      command("hi "+ob->query("id"));
      command("say 原来是阴癸派的人，久仰，久仰！\n");
      return 1;
   }
   
   if(ob->query("no_family")){
    command("say 你已经不能投入到任何门派之中了，问我这个问题干什么？\n");
    return 1;
   }
   
   if(present("heart",ob)){
     command("kao1 "+ob->query("id"));
     command("say 你当这是猪心吗？？这可是人心啊！阴癸派只给我很少的！！\n");
     return 1;
   }
   
   heart=new(__DIR__"obj/heart");
   heart->move(ob);
   tell_object(ob,query("name")+"给了你一"+heart->query("unit")+heart->query("name")+"\n");
   command("whisper "+ob->query("id")+" 要拜阴癸派必须先“种魔心”！\n"+
           "这颗心你敢不敢吃呢？\n");
   return 1;
}

int do_action2()
{
    object ob,obj;
    
    ob=this_player();
    
    if(!ob->query_temp("bai_yingui/step1")){
     command("heihei");
     command("say 虽然我不在阴癸派收弟子，可也知道要入阴癸派，要做一些事的！");
     return 1;
    }
    
    if(present("yinguibaishimihan",ob)){
     command("say 我已经给你密函了，如果你有诚意，就去拜师吧！");
     return 1;
    }
    
    obj=new(__DIR__"obj/mihan");
    obj->move(ob);
    
    command("say 好！"+RANK_D->query_respect(ob)+"，够胆量！");
    command("whisper "+ob->query("id")+" 我给这封信，你去找林士宏或旦梅拜师吧！");
    return 1;
}