
inherit F_MASTER;
inherit NPC;
#include <ansi.h>
string do_quest();
string move_room();
string do_skill_quest();
string do_skill_quest2();
string do_tmd_quest1();
string do_tmd_quest2();
int do_give();
int do_syxf_quest();

void create()
{
   int i;
   object *ob;
   set_name("祝玉妍",({ "zhu yuyan","zhu","yu","yan" }) );
        set("gender", "女性" );
	set("nickname","阴后");
        set("age", 42);
   set("long", "他是阴癸派的教主,她的武功在武林可是数\n"+
               "一数二的。她的魔功更是独步天下!\n");
       
    set("combat_exp",5000000);
   set("str", 25);
   set("dex",30);
   set("per", 28);
 
    set_skill("whip",450);
    set_skill("dodge",450);
    set_skill("parry",450);
    set_skill("force",500);
    set_skill("literate",500);
    set_skill("tianmo-jue",450);
    set_skill("tianmo-dafa",500);
    set_skill("tianmo-huanzong",450);
    set_skill("tianmo-dai",450);

    set("perform_quest/yulong",1);
    set("apply_points",1000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("exert huihun") :),
        (: command("exert jufen") :),
        (: command("perform yulong") :),
    }));

    set("max_gin",5000);
    set("max_sen",6000);
    set("max_kee",7000);
    set("max_force",11000);
    set("force",11000);
   create_family("阴癸派",3,"掌门");
   set("inquiry",([
	   "阴癸尊者":(:do_quest:),
	   "密室":(:move_room:),
	   "天魔带":(:do_tmd_quest1:),
	   "纤手驭龙":(:do_tmd_quest2:),
	   "水云袖法":(:do_syxf_quest:),
	   //"衣服":(:do_give:),
	  // "搜心剑法":(:do_skill_quest:),
	 //  "暗器":(:do_skill_quest2:),
	   ]));  
   set("perform_quest/yulong",1);//NPC应该解得此迷题，不然perform威力会小。
   setup();
   
   ob=children(__DIR__"obj/jueqing-bian");
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
   carry_object(__DIR__"obj/jueqing-bian")->wield();
  
  
}
void attempt_apprentice(object ob)
{
	
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="阴癸派")
	if((int)ob->query("family/generation",1)<=3)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	if(ob->query("family/master_name")=="婠婠"){
	command("heng "+ob->query("id"));
	command("say 既然你已经拜了婠婠为师，就不必再找本宗了！\n");
	return;
	}
	if(ob->query("gender")=="男性"){
	
	command("say 我不收男弟子的！你如果诚心投入本派，去找林士宏吧！\n");
	return;
        }
        if(ob->query_skill("tianmo-dafa",1)<150){
        command("say 你的天魔大法修为不够，还是再去修习一下再拜我为师吧！\n");
        return;
        }
        if(ob->query("office_number")<50){
        command("say 你的功绩这么低，我可不要这么懒惰的弟子！\n");
        return;
        }
        if(ob->query("bellicosity")<1000){
        command("say 你的杀气不够多，如何成为我门下的魔门弟子？\n");
        return;
        }
        if(ob->query_per()<28){
	 command("hmm1");
	 command("say 你的样子不够漂亮，我可不收这样的弟子！\n");
	 return;
	}
        
        lev=ob->query_skill("cuff",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("whip",lev);
        tell_object(ob,HIY"你从基本拳法中领略到了基本鞭法！\n"NOR);
                
	command("say 好！希望你将来能一统魔道，长我阴癸派名声！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin3");
}

//force quest
string do_quest()
{
  object ob,obj;
  
  ob=this_player();
  if(ob->query_skill("tianmo-dafa",1)<200)
  return "你的功夫太低了，现在还无法超越的！\n";
  if(ob->query("family_lingwu")=="yingui")
  return "长江后浪推前浪，你已经超越我了，还是快去领悟吧！\n";
  if(ob->query_temp("quest_fighter"))
  return "你还是快去战胜木人吧！\n";
  ob->set_temp("gage_zhu",1);
  
  obj=new(__DIR__"q_zhuyuyan");
  obj->set("name",ob->name()+"的木人");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
  return "好啊，你想成为阴癸尊者，必须先打赢这个木头人！\n";
}
/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_zhu"))
   return 1;
   message_vision(HIR"$N仰天长笑道：我魔界终于后继有人了！\n"NOR,victim);
   message_vision(HIR"$N突然脸色一变，既然能打得过我，你就去我的密室学习吧！\n"NOR,victim); 
   killer->set("family_lingwu","yingui");
   killer->set("title","阴癸尊者");
   killer->move("/d/clone/room/lingwu/yingui/mishi");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_zhu"))
   return 1;
  message_vision("$N朝$n叹了口气，你还是回去再磨练磨练吧！\n",killer,victim);
  return 1;
}*/
string move_room()
{
  object ob;
  ob=this_player();
  if(ob->query("pker"))
  return "你是个通缉犯，还是老实点吧！\n";
  if(ob->query("family_lingwu")!="yingui")
  return "你再说什么？我一点也不懂。\n";
  ob->move("/d/clone/room/lingwu/yingui/mishi");
  return "但愿你能让我们魔教纵横江湖，一统武林！\n";
}


string do_skill_quest()
{
    object ob;
    
    ob=this_player();
    
    if(ob->query("class")!="yin3")
     return "这样高深的剑法，你现在无法领会其中的诀窍的！\n";
     
    if(ob->query("bellicosity")<600000)
     return "象这样狠毒的剑法，凭你现在的能力是无法掌握的！\n";
    
    ob->set("dtsl_quest_sxjianfa_ok",1);
    
    return "既然你心地足够狠毒，看来足够可以学习我这套自创的剑法了！\n";
}

string do_skill_quest2()
{
   object ob;
    
    ob=this_player();
    
   if(ob->query("class")!="yin3")
     return "我们阴癸的暗器手法独步天下，你学习一阵子再来问我这个问题吧！\n";
   
   ob->set("dtsl_quest_throw_ok",1);
   
   return "好吧，我现在就将此暗器手法传授与你！\n";
}

string do_tmd_quest1()
{
    object ob;
    string msg;
    
    ob=this_player();
    
    if(ob->query_skill("tianmo-dai",1)<160)
    return "你现在是无法领会天魔带的内在威力的！\n";
    
    if(ob->query("perform_quest/yulong"))
    return "你已经领会了天魔带的绝学，我没什么可教的了。\n";
    if(ob->query("perform_quest/wanhuan"))
     return "你已经领会了千变铜萧的诀窍，无法再领会天魔带的诀窍了！";
    if(ob->query("perform_quest/lingxiao"))
       return "你已经领会了天魔斩的诀窍，无法再领会天魔带的诀窍了！";
    if(ob->query_skill("tianmo-zhen",1))
       return "你学了天魔阵，无法再学习天魔带的诀窍了！\n";
    
    ob->set_temp("tmd_quest_action1",1);
    
    msg="天魔带中有一招「纤手驭龙」，厉害非凡。\n"+
        "但是本派中能真正领会其中诀窍的人却不是很多。\n";
    return msg;
}

string do_tmd_quest2()
{
    object ob;
    string msg;
    
    ob=this_player();
    
    if(is_fighting())
       return "没看到我和人打仗呢吗？你等会再来吧！\n";
    
    if(!ob->query_temp("tmd_quest_action1"))
    return "这样厉害的功夫，你难道想尝试一下吗？\n";
    
    ob->delete_temp("tmd_quest_action1");
    msg="$N朝$n微微一笑：好吧！既然你想领会此决计，那我就亲手告诉你！\n";
    message_vision(msg,this_object(),ob);
    fight_ob(ob);
    remove_call_out("do_action2");
    call_out("do_action2",2,ob);
    return "你可要小心了！\n";
}

void do_action2(object ob)
{
   if(!ob) return;
   if(!living(ob)) return;
   if(ob->is_ghost()) return;
   if(environment(ob)!=environment(this_object())) return;
   if(!this_object()->is_fighting(ob)){
    tell_object(ob,query("name")+"朝你冷笑道：没想到你胆量如此小，如何领会本门绝技？\n");
    return;
   }
   set("apply_points",316);//气势满。
   command("perform yulong");
   call_out("do_action3",2,ob);
   return;
}

void do_action3(object ob)
{
   string msg;
   
   if(!ob) return;
   if(!living(ob)) return;
   if(ob->is_ghost()) return;
   if(environment(ob)!=environment(this_object())) return;
   if(!this_object()->is_fighting(ob)){
    tell_object(ob,query("name")+"朝你冷笑道：没想到你胆量如此小，如何领会本门绝技？\n");
    return;
   }
   remove_enemy(ob);
   ob->remove_enemy(this_object());
   
   msg="$N朝$n微微一笑：好，看来你的功夫还不错！\n"+
       "怎么样？领会到其中的诀窍了吗？\n";
   msg +="\n$n低头思索了一会，突然欢笑起来，朝$N一鞠躬：多谢师傅指点！\n";
   message_vision(msg,this_object(),ob);
   ob->set("perform_quest/yulong",1);
   ob->save();
   return;
}

int do_give()
{
   object ob,obj;
   
   ob=this_player();
   
   if(present("yulong_cloth",ob)){
     command("say 你已经有「彩魅幻衣」了，别这么贪心了！");
     return 1;
   }
   obj=new(__DIR__"obj/caimei-huanyi");
   obj->move(ob);
   tell_object(ob,query("name")+"给了你一"+obj->query("unit")+
              obj->query("name")+"。\n");
   command("pat "+ob->query("id"));
   return 1;
}

int do_syxf_quest()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/yanyu_action1")){
     command("say 此袖法是我女儿所创，确实很厉害！");
     return 1;
   }
   command("say 好，我就让你看看如何才能掌握袖法的精髓！");
   
   msg="\n$N的双袖朝你卷来，但是到了近前，双袖突然由卷变打，上面的力量刚柔并进，\n"+
       "如同两个灵活的双手一般！$n只觉得四周没有退路可逃，终于被$N的双袖拍在了\n"+
       "胸口和额头上！\n\n";
   msg+="$N淡淡一笑：你是我女儿的弟子，我不杀你。\n\n";
   message_vision(msg,this_object(),ob);
   ob->set("perform_quest/yanyu",1);
   ob->delete_temp("perform_quest/yanyu_action1");
   ob->unconcious();
   return 1;
}
