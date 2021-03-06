
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
#include <job_money.h>

int do_action1();

void create()
{
   set_name("宋法亮",({ "song faliang","song","faliang" }) );
   set("gender", "男性" );
   set("age", 28);
   set("long", "他就是宋家堡的宋法亮，他是宋家堡年轻一代中的高手。\n");
       
   set("combat_exp", 600000);
   
   set_skill("blade",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   
   set_skill("tiandao-bajue",150);   
   set_skill("literate",150);
   set_skill("anxiang-fuying",150);
   set_skill("tiangang-sanjue",150);
   set_skill("wangdao-jue",150);
   
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   
   set("inquiry",([
     "考验":(:do_action1:),
     ]));
   
   create_family("宋家堡",5,"门人");
   set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   carry_object(__DIR__"obj/blade")->wield();
  
}

void attempt_apprentice(object ob)
{   
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="宋家堡")
	if((int)ob->query("family/generation",1)<=5)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	
        if(ob->query_skill("tiangang-sanjue",1)<100){
        command("say 你的天罡三诀修为太低了，我不收这样的弟子！");
        return;
        }
	if(ob->query("office_number")<30){
        command("say 你的功绩这么低，宋家堡可不要这么懒惰的弟子！\n");
        return;
        }
        if(ob->query("deposit")<100000){
         command("say 我们宋家堡乃岭南一大阀，象你这么不懂敛财的人我可不要！");
         return;
        }
        if(!ob->query_temp("bai_songfaliang/action2",1)){
          command("say 你没经过我的考验，我如何知道你的胆量？");
          return;
        }
        
        lev=ob->query_skill("cuff",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("blade",lev);
        tell_object(ob,HIY"你从基本拳法中领略到了基本刀法！\n"NOR);

	command("say 你可要好好练习武艺，宋家堡的兴衰就看你们了！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song2");
}

string *dirs=({
"/d/huashan","/d/emeishan","/d/taishan",
});

int do_action1()
{
  object ob,target;
  
  ob=this_player();
  
  if(ob->query("family"))
  if(ob->query("family/family_name")!="宋家堡"){
      command("say 此话从何说起？\n");
      return 1;
  }
  if(ob->query("family"))
  if(ob->query("family/family_name")=="宋家堡")
  if((int)ob->query("family/generation",1)<=6){   
      command("say 此话从何说起？\n");
      return 1;
  }
  if(ob->query_temp("bai_songfaliang/action1")){
    command("say 你到底有没有胆量去？");
    return 1;
  }
  if(ob->query_temp("bai_songfaliang/action2")){
    command("say 既然你这么有胆量，就拜我为师吧！");
    return 1;
  }
  ob->set_temp("bai_songfaliang/action1",1);
  target=new(__DIR__"tigger");
  if(!target->set_status(ob)){
  	command("say 你等一下，我想想考你什么题目。");
  	return 1;
  }
  ob->add_temp_array("job_temp_killer",target);
  
  if(!random_place(target,dirs)){
  	command("say 你等一下，我想想考你什么题目。");
  	return 1;
  }
  if(!environment(target)){
  	command("say 你等一下，我想想考你什么题目。");
  	return 1;
  }
  command("say 好吧！我就看看你的胆量到底如何！\n"+
          "据说在"+MISC_D->find_place(environment(target))+"有一只"+target->name()+"，\n"+
          "你去把它杀死吧！");
  return 1;
}
  