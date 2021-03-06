
inherit F_MASTER;
inherit NPC;
#include <ansi.h>

int do_action1();

void create()
{
   set_name("宋邦",({ "song bang","song","bang" }) );
   set("gender", "男性" );
   set("age", 25);
   set("long", "他就是宋家堡的宋邦，他是宋家堡年轻一代中的高手。\n");       
   set("combat_exp", 300000);
   
   set_skill("cuff",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   
   set_skill("poyu-quan",100);   
   set_skill("literate",100);
   set_skill("anxiang-fuying",100);
   set_skill("tiangang-sanjue",100);
   set_skill("wangdao-jue",100);
   
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   
   set("inquiry",([
     "考验":(:do_action1:),
     ]));
   
   create_family("宋家堡",7,"门人");
   set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   
}

void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="宋家堡")
	if((int)ob->query("family/generation",1)<=7)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	
        if(!ob->query_temp("bai_sjb/step2")){
        command("say 你没经过我的考验，我怎么会轻易让你成为宋家堡弟子？");
        return;
        }
	
	ob->delete_temp("bai_sjb/step2");
	
	command("say 希望你能成为宋家堡新一代的高手，助我们称霸天下！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song1");
}

int do_action1()
{
   object ob,obj;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family")
     &&ob->query("family/family_name")!="宋家堡"){
    command("say 你已经是其他门派的弟子，我们宋家堡不会要的！");
    return 1;
   }
   
   if(ob->query("family")
   &&ob->query("family/family_name")=="宋家堡"
   &&ob->query("family/generation",1)<=7){   
    command("say 你已经经过考验了。");
    return 1;
   }
   
   if(present("sjb_mengshi_bishou",ob)){
     command("say 你到底有没有胆量盟誓？");
     return 1;
   }
   
   obj=new(__DIR__"obj/xiaodao");
   obj->move(ob);
   msg="$N给了$n一"+obj->query("unit")+
      obj->query("name")+"。\n";
   msg +="\n$N说道：想成为宋家堡弟子，先弑血盟誓(mengshi)吧！\n\n";
   
   message_vision(msg,this_object(),ob);
   ob->set_temp("bai_sjb/step1",1);
   return 1;
}
   