
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string do_quest1();
string do_quest2();
string do_jzzy_quest1();
string do_jzzy_quest2();
string do_jzzy_quest3();
int do_skjf_quest1();
int do_skjf_quest2();
int do_skjf_quest3();

void create()
{
   int i;
   object *ob;
   
   set_name("师妃喧",({ "shi feixuan","shi" }) );
   set("gender", "女性" );
   set("age", 23);
   set("long", "这是慈航静斋的师妃喧。\n");
       
    set("combat_exp",5000000);
   set("int", 30);
   set("per", 30);
    set("max_gin",5000);
    set("max_sen",6000);
    set("max_kee",7000);
    set("max_force",9000);
    set("force",9000);
    set_skill("sword",300);
    set_skill("parry",300);
    set_skill("dodge",300);
    set_skill("finger",300);
    set_skill("literate",300);
    set_skill("force",300);
    set_skill("sekong-jianfa",300);
    set_skill("xiuluo-zhi",300);
    set_skill("wuwang-jing",320);
    set_skill("qingxin-force",300);
    set_skill("lingyun-shenfa",300);

    set("perform_quest/kong",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform kong") :),
        (: command("perform lingxi") :),
        (: command("execute wuwang") :),
        (: command("exert qingxin") :),
    }));

  
   create_family("慈航静斋",4,"弟子");
   set("inquiry",([
      "徐子陵":(:do_skjf_quest3:),
      "寇仲":"他的刀法的确高明，如今谁又敢和他比试武艺呢？\n",
      "梵清惠":(:do_quest1:),
      "玄女":(:do_quest2:),
      "大石寺":(:do_jzzy_quest1:),
      "罗汉":(:do_jzzy_quest2:),
      "鸠摩罗什":(:do_jzzy_quest3:),
      "色空剑法":(:do_skjf_quest1:),
      "正邪之战":(:do_skjf_quest2:),
      ]));
   setup();
   carry_object(__DIR__"obj/baiyi")->wear();
   ob=children(__DIR__"obj/sekongjian");
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
   carry_object(__DIR__"obj/sekongjian")->wield();
  
}

void attempt_apprentice(object ob)
{   
	
	int lev;
	
	if(ob->query("gender")=="男性")
	{
	  command("say 我们慈航静斋不收男弟子的，如果你一心向佛，去净念禅院吧！\n");
	  return;
	}
	if(ob->query("family")&&ob->query("family/family_name")=="慈航静斋"
	  &&ob->query("family/generation")<=4)
	{
	  command("say 这话从何说起？\n");
	  return;
	}
	if(ob->query("kar")<24)
	{
	  command("say 唉，看你面象于佛无缘，你还是投靠其他门派吧！\n");
	  return;
	}
	if(ob->query("per")<25){
	  command("say 你的相貌太差了，我可不要这样的弟子！");
	  return;
	}
	if(ob->query_int()<31)
	{
	  command("say 你的头脑不够聪明啊，好好学学再来吧！\n");
	  return;
	}
	
	if(ob->query("PKS")>=5){
	  command("say 你身上罪孽太多，我可不要这样的弟子！");
	  return;
	}
	
	if(ob->query("bellicosity")>=100){
	  command("say 你身上杀气重重，如何修炼本门的武功？");
	  return;
	}
	
	if(ob->query_skill("qingxin-force",1)<100){
	  command("say 你的清心普善诀修为太低了，我无法收你为弟子！");
	  return;
	}
	if(ob->query("office_number")<20){
        command("say 你的功绩这么低，我可不要这么懒惰的弟子！\n");
        return;
        }
        lev=ob->query_skill("finger",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("sword",lev);
        tell_object(ob,HIY"你从基本指法中领略到了基本剑法！\n"NOR);
	
	command("say 好，既然能拜到我的门下，说明你真的能够忍受修炼的艰苦!\n");
	command("say 希望你以后能普善济世，为武林造福！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "jingzhai2");
}

string do_quest1()
{
  object ob;
  ob=this_player();
  if(ob->query("family_lingwu")=="jingzhai")
  return "你已经是本门玄女了，还是直接去找师傅她老人家吧！\n";
  
  if(ob->query_temp("quest_fighter"))
  return "你还是快去战胜自己的木人吧！\n";
  
  if(ob->query_skill("qingxin-force",1)<200)
  return "你的武功这么低，师傅她老人家是不会见你的。\n";
  ob->set_temp("dtsl_fquest_jz/step1",1);
  return "师傅他老人家喜欢清净，你还是别打扰他了。\n";
}

string do_quest2()
{
  object ob,obj;
  
  ob=this_player();
  if(!ob->query_temp("dtsl_fquest_jz/step1"))
  return "是否能成为本门的玄女，是师傅她老人家决定的，我可不敢做主！\n";
  ob->delete_temp("dtsl_fquest_jz/step1");
  ob->set_temp("dtsl_fquest_jz/step2",1);
  
  obj=new(__DIR__"q_shi");
  obj->set("name",ob->name()+"的木人");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
  return "如果想成为本门的玄女，必须要先战胜这个木人才可以。\n";
}
/*
int surrender(object killer,object victim)
{
   if(killer->query_temp("dtsl_fquest_jz/step2")){
    killer->delete_temp("dtsl_fquest_jz/step2");
    killer->set_temp("dtsl_fquest_jz/step3",1);
    message_vision("$N长叹一生：没想到本门中还有你这么出色的弟子！\n",this_object());
    tell_object(killer,"师妃喧朝你招招手：到我这里来，我告诉梵师傅她老人家的主处。\n");
    tell_object(killer,"师妃喧悄声说道：据说她老人家在长白上卧龙岭白云洞修行，你去找找看吧！\n");
    return 1;}
    return 1;
}
*/

string do_jzzy_quest1()
{
   object ob;
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_jzzy/step5"))
   return "你说的事我可是一点都没听说过。\n";
   ob->set_temp("dtsl_quest_jzzy/step6",1);
   ob->delete_temp("dtsl_quest_jzzy/step5");
   return "我也是入川后方由川帮帮主范卓告知此事，此人\n"+
          "名列邪道八大高手榜上，一向非常低调，行藏诡秘，与大石寺\n"+
          "的上代主持大德圣僧乃死敌，最近不知是否魔功大成，从西域\n"+
          "赶回来挑战大德，岂知大德刚於十天前圆寂火化。他竟把怨恨\n"+
          "发泄在他不懂武功的徒子徒孙身上，说若有人逗留寺内，他将\n"+
          "尽杀方圆十里内所有生人，寺僧为免祸及附近无辜乡民，只好\n"+
          "弃寺离开。\n";
}
string do_jzzy_quest2()
{
   object ob;
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_jzzy/step6"))
   return "你说的事我可是一点都没听说过。\n";
   ob->set_temp("dtsl_quest_jzzy/step7",1);
   ob->delete_temp("dtsl_quest_jzzy/step6");
   return "这些罗汉均是依后秦圣僧鸠摩罗什亲绘的手本敬制。\n";
}
  
string do_jzzy_quest3()
{
object ob;
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_jzzy/step7"))
   return "你说的事我可是一点都没听说过。\n";
   ob->set_temp("dtsl_quest_jzzy/step8",1);
   ob->delete_temp("dtsl_quest_jzzy/step7");
   return "鸠摩罗什乃天竺来中士传法有大德大智的高僧，广\n"+
          "究大乘佛法而尤精於般若性空的精义，武技更是超凡入圣，却从\n"+
          "不以武学传人，只论佛法。来中土后在长安的逍遥园从事翻译佛\n"+
          "经的工作。\n";
}

int do_skjf_quest1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("perform_quest/kong")){
     command("say 你已经掌握了色空剑法的精髓，自己去提高吧！");
     return 1;
   }
   if(ob->query_skill("sekong-jianfa",1)<160){
     command("say 你的色空剑法太低了，无法领会其中的精髓！");
     return 1;
   }
   ob->set_temp("perform_quest/kong_action1",1);
   command("say 色空剑法博大精深，我还是在正邪之战时领悟了剑法精髓。");
   return 1;
}

int do_skjf_quest2()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/kong_action1")){
     command("say 正邪之战凶险无比，要不是子陵出手相助，我也无法战胜绾绾。");
     return 1;
   }
   
   ob->set_temp("perform_quest/kong_action2",1);
   ob->delete_temp("perform_quest/kong_action1");
   command("say 当年，我和绾绾一战凶险无比，要不是子陵出手相助，我也无法战胜绾绾。\n子陵还被绾绾杀得重伤。");
   return 1;
}

int do_skjf_quest3()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/kong_action2")){
     command("say 我很久没看到他了，不知道他现在在哪里。");
     return 1;
   }
   
   ob->set_temp("perform_quest/kong_action3",1);
   ob->delete_temp("perform_quest/kong_action2");
   command("say 当年子陵和我在龙泉的精神之恋，是我生命中最美好的一段回忆。");
   return 1;
}
