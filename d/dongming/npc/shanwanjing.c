
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
#include <job_money.h>

int do_action1();
int do_action2();
int do_action3();

void create()
{
   set_name("单琬晶",({ "shan wanjing","shan","wanjing" }) );
   set("gender", "女性" );
   set("nickname","东溟公主");
   set("age", 24);
   set("long", "这是东溟派的公主。\n");
       
    set("combat_exp",3000000);
   set("per", 25);
    set_skill("dodge",300);
    set_skill("parry",300);
    set_skill("force",300);
    set_skill("sword",300);
    set_skill("dongming-xinfa",300);
    set_skill("bihai-force",300);
    set_skill("piaomeng-jianfa",300);
    set_skill("nishang-piaoming",300);
    set_skill("strike",300);
    set_skill("literate",300);

    set("perform_quest/duomeng",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform duomeng") :),
        (: command("exert shui") :),
        (: command("exert huo") :),
    }));

    set("max_gin",4000);
    set("max_sen",5000);
    set("max_kee",6000);
    set("max_force",8000);
    set("force",8000);
   create_family("东溟派",3,"公主");
   
   set("inquiry",([
     "东溟账本":(:do_action1:),
     "东溟檄":(:do_action2:),
     "飘梦剑法":(:do_action3:),
     ]));
   
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}
void attempt_apprentice(object ob)
{   
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="东溟派")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	
	if(ob->query("gender")=="男性"){
	
	command("say 我不收男弟子的！你如果诚心投入本派，去找尚仁吧！\n");
	return;
        }
        
        if(ob->query_skill("bihai-force",1)<150){
          command("say 碧海神功是我们东溟派的根基，你不好好学我怎么能收你为弟子呢？");
          return;
        }
        if(ob->query("office_number")<50){
        command("say 你的功绩这么低，我可不要这么懒惰的弟子！\n");
        return;
        }
        if(!ob->query_temp("bai_shanwanjing/ok")){
          command("say 我正在为东溟账本的事烦心，你等会吧！");
          return;
        }
        
        command("say 罢了罢了，账本被毁总比在人手上好。你做的不错，我就收你为徒吧。");
        ob->delete_temp("bai_shanwanjing/ok");

               
	command("say 近来战乱纷起，我们东溟未必能置身事外，你可以要好好练习武艺，保护我们门派！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming3");
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("family"))
   if(ob->query("family/family_name")=="东溟派")
   if((int)ob->query("family/generation",1)<=4){   
	 command("say 这件事情你帮不上忙的。\n");
	 return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")!="东溟派"){   
	 command("say 这件事情你帮不上忙的。\n");
	 return 1;
   }
   if(!ob->query("family")){   
	 command("say 这件事情你帮不上忙的。\n");
	 return 1;
   }
   if(ob->query_skill("bihai-force",1)<150){   
	 command("say 这件事情你帮不上忙的。\n");
	 return 1;
   }
   
   ob->set_temp("bai_shanwanjing/action1",1);
   command("say 东溟账本已被徐子陵和寇仲盗走，但辗转曲折，现在具体在谁手上我可不知道。\n"+
           "我已在江湖颁布「东溟檄」，希望可以寻回。\n");
   return 1;
}

string *dirs=({
"/d/hengshan","/d/taishan",
});

int do_action2()
{
   object ob,killer;
   
   ob=this_player();
   
   if(!ob->query_temp("bai_shanwanjing/action1")){   
	 command("say 这件事情你帮不上忙的。\n");
	 return 1;
   }
   
   if(ob->query("family"))
   if(ob->query("family/family_name")=="东溟派")
   if((int)ob->query("family/generation",1)<=4){   
	 command("say 这件事情你帮不上忙的。\n");
	 return 1;
   }
   if(ob->query("family"))
   if(ob->query("family/family_name")!="东溟派"){   
	 command("say 这件事情你帮不上忙的。\n");
	 return 1;
   }
   if(!ob->query("family")){   
	 command("say 这件事情你帮不上忙的。\n");
	 return 1;
   }
   if(ob->query_skill("bihai-force",1)<150){   
	 command("say 这件事情你帮不上忙的。\n");
	 return 1;
   }
   
   if(ob->query_temp("bai_shanwanjing/action2")){
     command("say 你到底有没有胆量去？");
     return 1;
   }
   
   
   killer=new(__DIR__"killer");
   killer->set_status(ob);
   
   if(!random_place(killer,dirs)){
     command("say 你等一下... ...");
     return 1;
   }
   if(!environment(killer)){
     command("say 你等一下... ...");
     return 1;
   }
   
   ob->set_temp("bai_shanwanjing/action2",1);
   ob->add_temp_array("job_temp_killer",killer);
   
   command("say 据说东溟账本被一个叫"+killer->name()+"拿着，此人目前藏身在"+
           MISC_D->find_place(environment(killer))+"。\n"+
           "你去把账本抢回来吧！\n");
   return 1;
}

int do_action3()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("piaomeng-jianfa",1)<160){
    command("say 你的飘梦剑法修为太低了，现在还无法领会其中的诀窍！");
    return 1;
   }
   if(ob->query("perform_quest/duomeng")){
    command("say 你已经掌握了飘梦剑法的诀窍，以后就自己的努力吧！");
    return 1;
   }
   if(ob->query("perform_quest/yanyu")){
    command("say 你已经掌握了水云袖法的诀窍，无法再掌握飘梦剑法的诀窍！");
    return 1;
   }
   if(ob->query("perform_quest/pili")){
    command("say 你已经掌握了雷霆锤法的诀窍，无法再掌握飘梦剑法的诀窍！");
    return 1;
   }
   
   ob->set_temp("perform_quest/duomeng_action1",1);
   command("say 我为了杀边不负而创出了此剑法。\n"+
           "他虽是我的生父，但我对他一点感情都没有，我一定要把他给杀了。\n");
   return 1;
}
