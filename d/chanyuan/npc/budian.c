
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
   set_name("不颠",({ "bu dian","bu","dian"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是净念禅院的高僧。\n");
   set("class","bonze"); 
   set("combat_exp", 200000);
   set("str", 28);
   set("attitude", "peaceful");
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("staff",100);
   set_skill("force",100);
   set_skill("chanzong-fofa",100);
   set_skill("liuyun",100);
   set_skill("blade",100);
   
   create_family("净念禅院",5,"僧人");
   set("target_id","###");
   set("inquiry",([
	   "job":(:give_job:),
	   "放弃":(:cancel_job:),
	   ]));
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();
  
}

void init()
{
	add_action("do_ok","task");
}

string give_job()
{
	object me;
	
	me=this_player();
	
	if((int)me->query("combat_exp",1)>=100000)
		return ""+RANK_D->query_respect(me)+",这样的工作太委屈你了!\n";
        
	if(me->query_temp("budian_job"))
		return ""+RANK_D->query_respect(me)+",还是先做完手头的事吧!\n";
	if(time()-(int)me->query("busy_time",1)<=30+random(10))
		return ""+RANK_D->query_respect(me)+",还是先歇歇吧!\n";
	if(me->query_temp("dtsl_job"))
        return "你正在做其他任务，先忙其他的吧！\n";
	me->set("busy_time",time());
	me->set_temp("dtsl_job","静念禅院初级任务");
	switch(random(3))
	{
	case 0: me->set_temp("budian_job/1",1);return "好吧,麻烦"+RANK_D->query_respect(me)+"去打扫一下经房(sao 经房)吧!\n";
        case 1: me->set_temp("budian_job/2",1);return "好吧,麻烦"+RANK_D->query_respect(me)+"去到菜园种菜(zhong 菜)吧!\n";
	case 2: me->set_temp("budian_job/3",1);return "好吧,麻烦"+RANK_D->query_respect(me)+"去打扫一下练武场(sao 武场)吧!\n";
	}
}

int do_ok(string arg)
{
	object me;
	
	me=this_player();
	
	if(!arg||arg!="ok") return notify_fail("你想说什么?\n");
        if(!me->query_temp("budian_job"))
		return notify_fail(""+RANK_D->query_respect(me)+",这话从何说起?\n");
	if(me->query_temp("budian_job"))
	 if(!me->query_temp("budian_job/ok"))
	return notify_fail("不颠笑道:请"+RANK_D->query_respect(me)+"做事认真一些吧!\n");
	
	me->delete_temp("budian_job");
	me->delete_temp("dtsl_job");
        JOBSYS_D->give_reward_chanyuanjob(me);
	return 1;
}

int cancel_job()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("budian_job")){
   command("?");
   return 1;
  }
  
  JOBSYS_D->do_cancel_job("chujichanyuan_job",ob,this_object());
  
  command("sigh "+ob->query("id"));
  return 1;
}
