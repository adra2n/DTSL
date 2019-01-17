
inherit NPC;

#define JOBCTRL "/d/job/killhaidao/jobctrl.c"

string give_job();

void create()
{
  set_name("韩朝安", ({"han chaoan", "han"}));
  set("gender", "男性");
  set("long","这是盖苏文的手下韩朝安。\n");
  set("age", 36);
  set("str",30);
  set("per",24);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",4000);
  set("combat_exp",500000);
  set_skill("unarmed", 182);
  set_skill("strike",182);
  set_skill("leg",182);
  set_skill("literate", 182);
  set_skill("sword", 182);
  set_skill("force", 182);
  set_skill("dodge", 182);
  set_skill("parry", 182);
  
  set_skill("jiuxuan-dafa",182);
  set_skill("fengxue-leg",182);
  set_skill("jiuzhuan-jianjue",182);
  set_skill("xingyun-dodge",182);
 
  set("target_id","###");
  
  set("inquiry",([
    "打劫":(:give_job:),
    ]));
  setup();
  
}

string give_job()
{
   object ob;
   object *member;
   object target;
   int i;
   int flag;
   
   ob=this_player();
   member=ob->query_team();
   if(sizeof(member)<=2)
   return "这么危险的任务人少做难度太大了，还是再找几个人去吧！\n";
   if(query("have_job"))
   return "已经有人去打劫了，你还是等会再来吧！\n";
   for(i=0;i<sizeof(member);i++)
     if(member[i]&&environment(member[i])!=environment(ob))
      break;
   if(i<sizeof(member))
   return "你队伍中的队员不都在这里，等等再说吧！\n";
   for(i=0;i<sizeof(member);i++)
	  if(objectp(member[i]))
		  if(member[i]->query("combat_exp")<1000000)
         return member[i]->name()+"的经验太低了，太危险了！\n";
   set("have_job",1);
   flag=random(3);
   if(flag==0)
   tell_room(environment(ob),"\n\n远处一艘运粮船缓缓地开了过来。\n\n");
   else if(flag==1)
   tell_room(environment(ob),"\n\n远处一艘商船缓缓地开了过来。\n\n");
   else
   tell_room(environment(ob),"\n\n远处一艘战船缓缓地开了过来。\n\n");
   tell_room(environment(ob),"\n韩朝安低声道：就是这艘船了！！\n\n");
   
   target=ob;
   for(i=0;i<sizeof(member);i++)
      if(member[i]&&member[i]->query("combat_exp")>target->query("combat_exp"))
       target=member[i];
   if(flag==0)
   JOBCTRL->start_job(target,sizeof(member)+15);
   else
   if(flag==1)
   JOBCTRL->start_job(target,sizeof(member)+25);
   else
   JOBCTRL->start_job(target,sizeof(member)+35);
   
   for(i=0;i<sizeof(member);i++)
    if(member[i]){
     message_vision("$N纵身一跃，跳向了甲板！！\n",member[i]);
     member[i]->move(__DIR__"out/out_6_0");}
  return "要一切小心！\n";
}