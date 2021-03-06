
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int do_action1();

void create()
{
   set_name("宋智",({ "song zhi","song","zhi" }) );
   set("gender", "男性" );
   set("nickname",HIC"地剑"NOR);
   set("age", 48);
   set("long", "他就是宋家堡人称「地剑」的宋智。\n");
       
   set("combat_exp",1500000);
   set("str", 28);
   set("per", 25);
   
   set_skill("sword",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   
   set_skill("dijian-jue",200);   
   set_skill("anxiang-fuying",200);
   set_skill("tiangang-sanjue",200);
   set_skill("wangdao-jue",200);
   set_skill("literate",200);
  
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   
   set("perform_quest/ditian",1);
   
   create_family("宋家堡",3,"门人");
   set("shili",([
      "name":"songjia_b",
      ]));
   set("inquiry",([
      "李世民":(:do_action1:),
   
   ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

void attempt_apprentice(object ob)
{   
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="宋家堡")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	
        if(ob->query_skill("tiangang-sanjue",1)<150){
        command("say 你的天罡三诀修为太低了，我不收这样的弟子！");
        return;
        }
	if(ob->query("office_number")<50){
        command("say 你的功绩这么低，宋家堡可不要这么懒惰的弟子！\n");
        return;
        }
	if(ob->query("deposit")<500000){
         command("say 我们宋家堡乃岭南一大阀，象你这么不懂敛财的人我可不要！");
         return;
        }
        if(ob->query("char_lev/bai_songque_fail")){
          lev=ob->query_skill("blade",1);
          ob->set_skill("sword",lev/3);
          tell_object(ob,query("name")+"道：既然你不能学刀，我就指点你几招剑术吧！\n");
          tell_object(ob,"你领会了些基本剑法。\n");
        }
        if(!ob->query("menpai/songjia3")){         
          ob->set("menpai/songjia3",1);
	}
	command("say 真是长江后浪推前浪！希望你能助宋家堡称霸天下！\n"+
	        "宋家堡的剑法以防守为主，不在伤敌，你可要好好学习！");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song3");
}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query("perform_quest/bajue")){
    command("say 凭你的能力还做不了这样的事！");
    return 1;
  }
  if(ob->query("dtsl_quest_ssbp_help_ok")){
    command("say 你已经做过一次了，就不要勉强了。\n");
    return 1;
  }
  if(ob->query("dtsl_quest_ssbp_ok")){
    command("say 你领悟了散手八扑，很难说你会全力对付宁道奇。");
    return 1;
  }
  
  ob->set_temp("help_ssbp_action1",1);
  
  command("say 李世民是汉人统一的心腹大患。有机会就杀了他。");
  
  return 1;
}