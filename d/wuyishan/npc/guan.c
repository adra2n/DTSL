
inherit F_MASTER;
inherit NPC;
void create()
{
   int i;
   object *ob;
   set_name("婠婠",({ "wan wan","wan"}) );
        set("gender", "女性" );
	set("title","阴癸仙子");	
        set("age", 22);
   set("long", "这是阴癸派的婠婠，她的魔功也是阴癸派数一数二的。\n");
       
   set("combat_exp",3000000);
   set("str", 25);
   set("per", 29);
   set("attitude", "peaceful");
   set_skill("unarmed",280);
   set_skill("dodge",280);
   set_skill("parry",280);
   set_skill("force",280);
   set_skill("sword",280);
   set_skill("strike",280);
   set_skill("cuff",280);
   set_skill("jiutian-huanzhang",280);
   set_skill("linglong-yuquan",280);
   set_skill("tianmo-dafa",280);
   set_skill("tianmo-jianfa",280);
   set_skill("tianmo-huanzong",280);
   set_skill("tianmo-dai",300);
   set_skill("dagger",300);
   set_skill("tianmo-zhan",300);
   set("hand",({"tianmo-dai","jiutian-huanzhang","linglong-yuquan"}));
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"tianmo-dafa"}));
   set("sword",({"tianmo-jianfa"}));
   set("dagger",({"tianmo-zhan"}));
   set("gin",6000);
   set("max_gin",6000);
   set("kee",6000);
   set("max_kee",6000);
   set("sen",6000);
   set("max_sen",6000);
   set("force",6000);
   set("max_force",6000);
   create_family("阴癸派",3,"弟子");
   set("class","yin_guan");
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
	   (:perform_action,"lingxiao":),
   }));
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   ob=children(__DIR__"obj/dagger");
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
   carry_object(__DIR__"obj/dagger")->wield();
  
}
void attempt_apprentice(object ob)
{
	
	if(ob->query("gender")!="女性")
	{
	  command("say 我只收女弟子的，你还是算了吧！\n");
	  return;
	}
	if(ob->query_int()<31)
	{
	  command("say 你的悟性太低了，我无法收你为徒。\n");
	  return;
	}
	if(ob->query("family")&&ob->query("family/family_name")=="慈航静斋")
	{
	  command("say 哼，我不去找你就算了，你还敢来撒野？！\n");
	  this_object()->kill_ob(ob);
	  return;
	}
	if((int)ob->query_skill("tianmo-dafa",1)<160)
	{
		tell_object(ob,"你的[天魔大法]火候还未到,怎能拜我为师?\n");
		return;
	}
	command("say 好,你要好好和我学，将来打败慈航静斋!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin_guan");
}

