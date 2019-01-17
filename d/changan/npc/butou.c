
inherit NPC;
#include <ansi.h>
#include <job_money.h>
string give_job();
int do_ok(string arg);
void create()
{
   set_name("捕头",({ "bu tou","bu","tou" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是长安的捕头，管理长安城的治安。\n");
       
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set_skill("force",70);
   set("max_force",200);
   set("force",200);
   set("inquiry",([
	   "盗贼":(:give_job:),
	   ]));
   setup();
   
}

void init()
{
	add_action("do_ok","guian");
}

string give_job()
{
	object me,ob;object *t;int i;string str;
	me=this_player();ob=this_object();
	//return "对不起，这个任务还在修改中。\n";
	t=me->query_team();
	if(sizeof(t)==0){
		return "这个任务你自己来做太危险了，还是和别人组队一起做吧！\n";}
	if(!me->is_team_leader())
		return "你不是队伍的首领，让你们的首领来吧！\n";
	if(time()-me->query("busy_time")<30+random(10))
		return "最近没什么盗贼，你过一阵子再来吧！\n";
	if(sizeof(t)>2) 
	 return "这么简单的任务还要这么多人？不会吧？\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(environment(me)!=environment(t[i]))
			  return "你的队员还没到齐，等等吧！\n";
	for(i=0;i<sizeof(t);i++)
	 if(t[i])
	  if(t[i]->query("combat_exp")<200000)
	   return t[i]->name()+"的经验太低，这太危险了！\n";
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(me->query("combat_exp")>=t[i]->query("combat_exp")){
			  if(me->query("combat_exp")-t[i]->query("combat_exp")>20000)
				  return "你们的经验相差太大，这很危险！\n";}
		  else{ if(t[i]->query("combat_exp")-me->query("combat_exp")>20000)
			      return "你们的经验相差太大，这很危险！\n";}
	if(me->query_temp("butou_job"))
		return "不是告诉让你们去做了吗？怎么还不去？\n";
	switch(random(5))
	{
	case 0:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/1",1);
	  me->set_temp("butou_job/1",1);
	   str="好吧，麻烦你们去巴陵的小巷中把盗贼杀死后回来复命吧！\n";
	   break;
	case 1:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/2",1);
	  me->set_temp("butou_job/2",1);
	   str="好吧，麻烦你们去成都南门外的长江北岸把盗贼杀死后回来复命吧！\n";
	   break;
	case 2:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/3",1);
	  me->set_temp("butou_job/3",1);
	   str="好吧，麻烦你们去东南方的港口把盗贼杀死后回来复命吧！\n";
	   break;
	case 3:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/4",1);
	  me->set_temp("butou_job/4",1);
	   str="好吧，麻烦你们去杭州的凉亭把盗贼杀死后回来复命吧！\n";
	   break;
	case 4:
		for(i=0;i<sizeof(t);i++)
      if(objectp(t[i]))
		  t[i]->set_temp("butou_job/5",1);
	  me->set_temp("butou_job/5",1);
	   str="好吧，麻烦你们去襄阳南门外的长江北岸把盗贼杀死后回来复命吧！\n";
	   break;
	}
	return str;
}

int do_ok(string arg)
{
	object me,ob,*t;int i;object money;
	int exp,pot,sil,famous;
	me=this_player();
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("你要向谁归案？\n");
	if(!me->query_temp("butou_job"))
		return notify_fail(""+RANK_D->query_respect(me)+",这话从何说起？\n");
	if(!me->query_temp("butou_job_ok"))
        return notify_fail(""+RANK_D->query_respect(me)+",你们当我是小孩子来骗吗？！\n");
	t=me->query_team();
	if(sizeof(t)==0)
		return notify_fail("你没和其他人组队，我就不信你会独自完成这么艰巨的任务！\n");
    for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(environment(me)!=environment(t[i]))
			  return notify_fail("你的队员还没到齐，等等吧！\n");
	for(i=0;i<sizeof(t);i++)
	  if(objectp(t[i]))
		  if(!t[i]->query_temp("butou_job"))
			  return notify_fail("你们的队伍中混进了其他人，不把他赶走，我如何奖励你们？\n");
    for(i=0;i<sizeof(t);i++)
		if(objectp(t[i])){
		  exp=260+random(40);
          pot=t[i]->query("max_pot")/3;
             sil=BUTOU_JOB+t[i]->query("max_pot")-100;
	      t[i]->add("deposit",sil);
		  t[i]->add("combat_exp",exp);
		  t[i]->add("potential",pot);
		  add_shili(t[i],exp/2,sil/2);
		  t[i]->delete_temp("butou_job");
		  t[i]->delete_temp("butou_job_ok");
		  t[i]->delete_temp("butou_job_flag");
		  t[i]->set("busy_time",time());
		  tell_object(t[i],"捕头笑道：好吧，真是麻烦"+RANK_D->query_respect(t[i])+"了！\n");
		  tell_object(t[i],"在这次行动中，你获得了"+""HIW""+chinese_number(exp)+""NOR""+"点实战经验。\n");
          tell_object(t[i],"                      "+""HIW""+chinese_number(pot)+""NOR""+"点潜能。\n");
		  tell_object(t[i],"捕头给了你"+MONEY_D->money_str(sil)+"作为奖励。\n");
		  tell_object(t[i],"你钱庄的存款增加了！\n");}
	return 1;
}
