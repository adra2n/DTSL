
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("单霞",({ "shan xia","shan","xia" }) );
   set("gender", "女性" );
   set("age", 22);
   set("long", "这是东溟派的弟子。\n");
       
   set("combat_exp",100000);
   set("per", 25);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   
   set_skill("dongming-xinfa",100);
   set_skill("bihai-force",100);
   set_skill("youyue-zhangfa",100);
   set_skill("nishang-piaoming",100);
   set_skill("literate",100);
  
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("东溟派",7,"弟子");
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
  
}

void attempt_apprentice(object ob)
{   
	string name,newname;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="东溟派")
	if((int)ob->query("family/generation",1)<=7)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	
	if(ob->query("gender")=="男性"){
	
	command("say 我不收男弟子的！你如果诚心投入本派，去找尚仁吧！\n");
	return;
        }
        
        if(!ob->query_temp("bai_dongming/action4")){
        command("say 你当我东溟派是什么地方，我们怎么能随便收徒弟？");
        return;
        }
	
	ob->delete_temp("bai_dongming/action4");
	
	name=ob->query("name");
	newname="单"+name[2..3];
	ob->set("name",newname);
	tell_object(ob,"以后你的名字是"+HIY+newname+NOR+"。\n");
		
	command("say 我们东溟派向来不介入中原的纷争，你将来行侠时可要小心谨慎！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming1");
}