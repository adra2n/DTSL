
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_quest1();
int do_tell(string arg);

void create()
{
   int i;
   object *ob;
   
   set_name("辟守玄",({ "pi shouxuan","pi","shouxuan" }) );
        set("gender", "男性" );
	set("nickname","云雨双修");
        set("age",46);
   set("long", "这是阴癸派元老级的高手。\n");
       
   set("combat_exp",1000000);
   set_skill("dodge",400);
   set_skill("parry",400);
   set_skill("force",400);
   set_skill("strike",400);
   set_skill("qianbian-tongxiao",400);
   set_skill("sword",400);
   set_skill("literate",400);
   set_skill("tianmo-dafa",400);
   set_skill("tianmo-jue",400);
   set_skill("tianmo-huanzong",400);
   
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   set("perform_quest/wanhuan",1);
   create_family("阴癸派",3,"长老");
   set("inquiry",([
       "游秋雁":(:do_quest1:),
      
      ]));
   setup();
   
   ob=children(__DIR__"obj/tongxiao");
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
   carry_object(__DIR__"obj/tongxiao")->wield();
  
}

void init()
{
   add_action("do_tell","gaosu");
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
	if(ob->query("gender")=="女性"){
	
	command("say 我不收女弟子的！你如果诚心投入本派，去找旦梅吧！\n");
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
        command("say 你的杀气太低了！\n");
        return;
        }
        
        lev=ob->query_skill("strike",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("sword",lev);
        tell_object(ob,HIY"你从基本掌法中领略到了基本剑法！\n"NOR);
        
	command("say 好！希望你将来能一统魔道，长我阴癸派名声！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin3");
}

int accept_ansuan(object me,int flag)
{
    if(flag==2)
     set("ansuan_ob",me);
    if(flag==1)
     set("ansuan_ob_ok",me);
    return 1;
}

int do_quest1()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(query("ansuan_ob")==ob){
     msg="$N朝$n喝道："+RANK_D->query_rude(ob)+"，你刚刚暗算我，现在还敢来？\n"+
         "等死吧！！\n";
     message_vision(msg,this_object(),ob);
     kill_ob(ob);
     return 1;
   }
   if(query("ansuan_ob_ok")!=ob){
     command("say 刚才我被别人暗算了，真是倒霉！");
     return 1;
   }
   if(ob->query_skill("qianbian-tongxiao",1)<160){
     command("say 你问这个问题干什么？想干什么？");
     return 1;
   }
   ob->set_temp("wanhuan_quest1",1);
   command("say 师傅刚才被人暗算，需要这个小妮子来泻泻火！\n她来的时候告诉我一声！");
   return 1;
}

int do_tell(string arg)
{
   object ob,target,obj;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("wanhuan_quest1"))
   return notify_fail("辟守玄烦道：你快给我走开！\n");
   if(!arg)
   return notify_fail("辟守玄烦道：要说什么就快点！\n");
   if(arg!="游秋雁来了")
   return notify_fail("辟守玄烦道：我现在只等游秋雁，其他什么都不管！\n");
   if(!objectp(target=present("you qiuyan",environment(ob))))
   return notify_fail("辟守玄烦道：人在哪里呢？\n");
   
   msg="\n$N露出笑容，拉着$t的手朝里屋走去。$t回头看了$n一眼。\n";
   msg +="\n过了一会，$t从里屋走出来，衣衫有些凌乱，匆忙给了$n一封信，"+
         "然后转身走了。\n\n";
   msg=replace_string(msg,"$t",target->name());
   message_vision(msg,this_object(),ob);
   destruct(target);
   obj=new(__DIR__"obj/letter");
   obj->move(ob);
   ob->delete_temp("wanhuan_quest1");
   return 1;
}

int accept_object(object ob,object obj)
{
   string msg;
   
   if(!obj->query("wanhuan_quest"))
   return 0;
   
   msg="$N露出恐惧的表情，朝$n叹道：果真是长江后浪推前浪！\n"+
       RANK_D->query_respect(ob)+"能不能放我一次？\n\n";
   msg +="$N朝$n道：让我先来看看你的功夫学得怎么样了！\n\n";
   message_vision(msg,this_object(),ob);
   ob->set_temp("wanhuan_quest2",1);
   fight_ob(ob);
   return 1;
}

int end_fight(object killer,object victim)
{
    if(!victim->query_temp("wanhuan_quest2"))
    return 1;
    message_vision("$N朝$n冷笑一声：你知道的秘密太多了，受死吧！\n",
          killer,victim);
    kill_ob(victim);
    return 1;
}

int surrender(object killer,object victim)
{
   if(!killer->query_temp("wanhuan_quest2"))
    return 1;
   message_vision("$N朝$n长叹一声：罢了，罢了！！我就传授给你千变铜萧的绝学吧！\n",
                victim,killer);
   if(killer->query("perform_quest/lingxiao")){
     command("say 你已经领会了天魔斩的诀窍，无法再领会千变铜萧的诀窍了！");
     return 1;
   }
   if(killer->query("perform_quest/yulong")){
     command("say 你已经领会了天魔带的诀窍，无法再领会千变铜萧的诀窍了！");
     return 1;
   }
   if(killer->query_skill("tianmo-zhen",1)){
     command("say 你学了天魔阵，无法再学习千变铜萧的诀窍了！");
     return 1;
   }
   message_vision("$N阴险地笑了笑，终于领略了千变铜萧的绝学！\n",killer);
   killer->set("perform_quest/wanhuan",1);
   killer->save();
   return 1;
}
