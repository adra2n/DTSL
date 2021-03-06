//job.
// 东溟收账任务。
//150k-200k 没有杀手
//200k 以后有杀手。
#include <job_money.h>
#include <ansi.h>
inherit NPC;


mapping target=([
"/d/yangzhou/npc/tiejiang":"扬州铁匠","/d/hangzhou/npc/tiejiang":"杭州铁匠",
"/d/baling/npc/tiejiang":"巴陵铁匠","/d/jiujiang/npc/tiejiang":"九江铁匠",
"/d/chengdu/npc/tiejiang":"成都铁匠",
"/d/hefei/npc/tiejiang":"合肥铁匠","/d/xiangyang/npc/tiejiang":"襄阳铁匠",
]);

string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
   set_name("账房先生",({ "xian sheng","xian","sheng" }) );
        set("gender", "男性" );
        set("age", 42);
set("target_id","####");
   set("long", "他是东溟的账房先生。\n");
   set("combat_exp", 600000);
   set("str", 30);
   set_temp("apply/armor",30);
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("max_force",2000);
   set("force",2000);
   set("inquiry",([
     "收账":(:give_job:),
     "放弃":(:cancel_job:),
     ]));
   setup();
  
}

void init()
{
  add_action("do_ok","jiaochai");
}

int cancel_job()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("dm_shouzhang")){
  command("kok "+ob->query("id"));
  return 1;
  }
  if(present("zhang ben",ob))
  destruct(present("zhang ben",ob));
  
  JOBSYS_D->do_cancel_job("dmshouzhang",ob,this_object());
  
  return 1;
}

string give_job()
{
  object me;
  object ob;
  string *t;
  string t_name;
  int i;
  
  me=this_player();
  
  if(me->query("combat_exp")<100000)
  return "你的功夫太低了，很难做这个任务的。\n";
  if(me->query_temp("dm_shouzhang"))
  return "你还是赶紧去吧，否则上面怪罪下来我也担当不起的。\n";
  if(time()-me->query("busy_time")<40+random(10))
  return "你还是先歇歇吧！\n";
  if(me->query_temp("dtsl_job")&&
    me->query_temp("dtsl_job")!="东溟派收账任务")
  return "你正在做其他任务，还是先忙完其他的吧！\n";
  
  me->set_temp("dm_shouzhang",1);
  me->set_temp("dtsl_job","东溟派收账任务");
  
  t=keys(target);
  i=random(sizeof(t));
  t_name=t[i];
  me->set_temp("dm_shouzhang_target",t[i]);
  ob=new(__DIR__"book");
  ob->set("dm_shouzhang_target",t[i]);
  ob->move(me);
  return "好吧,"+target[t[i]]+"和我们有生意往来，你去那里收账吧！\n";

}



int do_ok(string arg)
{
  object ob;
  object target;
  string name;
  
  
  ob=this_player();
  if(!ob->query_temp("dm_shouzhang"))
  return 0;
  if(!arg||sscanf(arg,"with %s",name)!=1)
  return notify_fail("请使用 jiaochai with xxx 来交差。\n");
  if(!objectp(target=present(name,ob)))
  return notify_fail("你身上没有这个东西。\n");
  if(!target->query("dm_shouzhang_ok"))
  return notify_fail("你好好看看，这账本的数目也不对啊？！\n");
  
  ob->delete_temp("dm_shouzhang");
  ob->delete_temp("dm_shouzhang_target");
  ob->delete_temp("dtsl_job");
  ob->set("busy_time",time());
  
  destruct(target);
  tell_object(ob,""+query("name")+"把账本收了起来。\n");
  
  JOBSYS_D->give_reward_dmshouzhang(ob);
  return 1;
}
