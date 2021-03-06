
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   int i;
   object *ob;
   
   set_name("可达志",({ "ke dazhi","ke" }) );
   set("gender", "男性" );		
   set("age", 30);
   set("combat_exp",6500000);

   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("blade",350);
   set_skill("literate",200);

   set_skill("yanyang-dafa",300);
   set_skill("canglang-jue",200);
   set_skill("kuangsha-daofa",350);
   set_skill("youlong-shenfa",300);
   set("max_gin",6000);
   set("max_kee",6000);
   set("max_sen",6000);
   set("force",8000);
   set("max_force",8000);
   
   set("inquiry",([
     "考验":(:do_action1:),
     ]));
   
   create_family("突厥",3,"武士");
    set("perform_quest/kuangsha",1);
   set("chat_chance_combat",80);
   set("chat_msg_combat",({
                (: command("perform kuangsha") :),
                (: command("execute xiao") :),
        }));
    set("apply_points",200);
   
   ob=children(__DIR__"obj/kuangsha-dao");
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
   setup();
  
   carry_object(__DIR__"obj/kuangsha-dao")->wield();  
}
void attempt_apprentice(object ob)
{   
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="突厥")
	if((int)ob->query("family/generation",1)<=3)
	{   
	  command("say 此话从何说起？");
	  return;
	}
	if(ob->query("tujue_jun")!="金狼军"){
            command("say 你没加入我们金狼军，我可不要你这样的徒弟！");
            return;
        }
        if(ob->query_skill("yanyang-dafa",1)<150){
            command("say 你的炎阳大法修为太低了，叫我如何收你为徒？");
            return;
        }
        if(ob->query("office_number")<40){
        command("say 你的功绩这么低，我可不要这么懒惰的弟子！\n");
        return;
        }
        if(!ob->query_temp("bai_ke_ok")){
          command("say 你没经过考验，我怎么能收你？");
          return;
        }
        ob->delete_temp("bai_ke_ok");
        
	command("say 你可要努力学习武功，将来为突厥一统中原尽力！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue3");
}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("family")
  &&ob->query("family/family_name")!="突厥"
    ){
    command("say 你真是说笑了！");
    return 1;
  }
  if(ob->query("family"))
	if(ob->query("family/family_name")=="突厥")
	if((int)ob->query("family/generation",1)<=4)
	{   
	  command("say 此话从何说起？");
	  return 1;
	}
  if(!ob->query("family")
    ){
    command("say 你还不是我突厥弟子，如何接受我的考验？");
    return 1;
  }
  
  if(ob->query("tujue_jun")=="黑狼军"){
      command("say 你既然已经加入了黑狼军，就休想再为我办事！");
      return 1;
  }
  if(ob->query_temp("bai_ke_ok")){
     command("say 你已经经过考验了。");
     return 1;
  }
  if(ob->query_temp("bai_ke")){
     command("say 你到底敢不敢去？");
     return 1;
  }
  command("say 我们会近期支援长安李阀李元吉，不知道你的本领如何！\n"+
          "你如果能打赢天策府的李靖，我就收你为徒！");
  ob->set_temp("bai_ke",1);
  return 1;
}
