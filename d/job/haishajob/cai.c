//job.
// 泰山夺宝任务。
#include <job_money.h>
#include <ansi.h>
inherit NPC;
string give_job();
string clear_job();
void create()
{
   set_name("蔡胜",({ "cai sheng","cai","sheng" }) );
        set("gender", "男性" );
        //set("title",
        set("age", 32);
   set("long", "这是海杀帮的蔡胜。\n");
   set("combat_exp", 500000);
   set("str", 30);
   set("inquiry",([
     "宝藏":(:give_job:),
     "放弃":(:clear_job:),
     ]));
   set("duobao_job",1);
   setup();
  
}

string give_job()
{
  object me,ob;
  me=this_player();
  ob=this_object();
  if(me->query("combat_exp")<800000)
  return "这个任务危险，你还是不要做了！\n";
  if(me->query("job/duobao_job"))
  return "我可不喜欢做事马虎的人！\n";
  if(time()-me->query("busy_time")<90)
  return "现在哪有这么多宝物啊？你还是歇歇吧！\n";
 if(time()-ob->query("gived_job")<60)
  return "已经有人去了，你等会吧！\n";
  if(me->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
   me->set_temp("dtsl_job","抢夺杨公宝藏任务");
  me->set("job/duobao_job",1);
 ob->set("gived_job",time());
  return "听说最近泰山有一个藏宝图出现，已经有很多人去抢了。\n"+
         "你去把它抢回来给我，一定要小心，据说去的都是各派的武林高手！\n";
}

string clear_job()
{
  object me,ob;
  me=this_player();
  ob=this_object();
  if(!me->query("job/duobao_job"))
  return "恩，你这是什么意思？！\n";
  me->delete("job");
  me->delete_temp("dtsl_job");
  ob->delete("gived_job");
  me->set("busy_time",time()+60);
  return "哼，没想到你是这么没用的人，大唐中英雄人物多的是，\n"+
         "你不做，总会有人来做的！\n";
}

