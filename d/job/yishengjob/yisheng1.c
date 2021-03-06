
inherit NPC;

#include <ansi.h>
#include <job_money.h>

int test_player();
int cancel_me();
mapping yaoname=([
RED"红花"NOR:"honghua",
YEL"陈皮"NOR:"chenpi",
HIY"人参"NOR:"renshen",
GRN"当归"NOR:"danggui",
HIC"雪莲"NOR:"xuelian",
BLU"生地"NOR:"shengdi",
MAG"何首乌"NOR:"heshouwu",
]);
void create()
{
  set_name("采药人", ({ "caiyao ren", "ren" }));
  set("age", 60);
  set("gender", "男性");
  set("long", "一个采药人。\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 1500);
  set("force", 1500);
  set("force_factor", 150);
  set_skill("unarmed", 90);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("force", 80);
  set("target_id","###");
  set("inquiry", ([
        "job":   (: test_player:),
        "放弃":   (: cancel_me:),
      ]));
  setup();

}


int test_player()
{
  string *strs = ({
    "$N对$n说道：  药师现在想给病人们炼制点丹药，需要",
    "$N想想说：我们这里现在急需",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  string *n,*id1;int z;

if(who->query("combat_exp")>100000){
	   	
		command("hehe");
		command(
 		  "say 你的技术已经够高的了，去帮药师的忙吧！\n");
		return 1;
	    }

  if (who->query_temp("quest/caiyao"))
  {
    message_vision ("$N对$n说道：你不是答应帮我找"+who->query_temp("quest/caiyao/name")+"吗？怎么还没来？\n",me,who);
    return 1;
  }
 if(time()-who->query("busy_time")<30){
	   	
		command("hehe");
		command(
 		  "say 我们这里暂时不缺东西，等会吧！\n");
		return 1;
	    }


   n=keys(yaoname);
  z=random(sizeof(n));  
  if(z%2!=0) z++;
   if(z==sizeof(yaoname)-1)
    z=z-2;  
   id1=yaoname[n[z]];
  who->set_temp("quest/caiyao/name", n[z]);
  who->set_temp("quest/caiyao/id", id1);
  who->set("busy_time",time()-20);
  str = strs[random(sizeof(strs))]+n[z]+
        "，\n这位"+RANK_D->query_respect(who)+
        "你去大巴山帮我采点回来吧？\n";

  message_vision (str,me,who);
  return 1;
}

int cancel_me()
{	
	
	object target,me=this_player();

           if(!me->query_temp("quest/caiyao"))
	   
	{
	   command("bite");
	   command("say 我又没叫你帮我采药，你放什么弃啊？！\n");
	   return 1;
       }
        
        JOBSYS_D->do_cancel_job("yishengjob1",me,this_object());
	
	command("say 没用的东西！！\n");
        return 1;
}

string no_color(string arg)
{
      arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}


int accept_object(object who, object ob)
{
  object me = this_object();
  string name,jname,reason;
  int t;


  if (! who->query_temp("quest/caiyao"))
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我现在不缺这个，你给我也没用。\n");
   
  }

  if(ob->is_character()) return notify_fail("\n");
  
  name=no_color(ob->query("name"));
  jname=no_color(who->query_temp("quest/caiyao/name"));
  if (jname !=name)
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我叫你帮我采"+
		    who->query_temp("quest/caiyao/name")+
                    "，您却给我个"+ob->query("name")+"，这是什么意思？\n");
   
  }

  if (who->query_temp("quest/caiyao/id") != ob->query("id"))
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我等着您的"+who->query_temp("quest/caiyao/name")+
                    "，东西倒挺象，但不是同一个货；我要的是("+who->query_temp("quest/caiyao/id")+")，您给的是("+
                    ob->query("id")+")！\n");
  }
  
  reason = "帮我采到"+ob->query("name")+"，";
  message_vision ("$N对$n说道：你"+reason+"我真的要好好奖励你！\n",me,who);
  
  JOBSYS_D->give_reward_yishengjob1(who);
  who->delete_temp("quest/caiyao");
  who->set("busy_time",time()); 
  
  return 1;
}
