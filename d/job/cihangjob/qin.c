
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int do_ok(string arg);
int cancel_job();

mapping here=([
"诵经房":"/d/jingzhai/songjingfang","藏经房":"/d/jingzhai/cangjingfang",
"文智堂":"/d/jingzhai/wenzhitang","无嗔堂":"/d/jingzhai/wuchentang",
"苦心房":"/d/jingzhai/kuxinfang","无贪堂":"/d/jingzhai/wutantang",
"无欲堂":"/d/jingzhai/wuyutang",
]);

void create()
{
   set_name("秦云明",({ "qin yunming","qin" }) );
        set("gender", "女性" );
        set("age", 22);
   set("long", "这是慈航静斋的秦云明。\n");
       
   set("combat_exp",300000);
   set("str", 25);
   set("per", 26);
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("max_force",3000);
   set("force",3000);
   set("attitude", "friendly");
   set_skill("sword",120);
   set_skill("cuff",120);
   set_skill("strike",120);
   set_skill("dodge",120);
   set_skill("finger",120);
   set_skill("literate",120);
   set_skill("force",120);
   set_skill("sekong-jianfa",120);   
   set_skill("xiuluo-zhi",120);
   set_skill("wuwang-jing",120);
   set_skill("qingxin-force",120);
   set_skill("lingyun-shenfa",120);
   
   create_family("慈航静斋",8,"弟子");
   set("target_id","###");
   set("inquiry",([
     "job":(:give_job:),
     "放弃":(:cancel_job:),
     ]));
   setup();
  
}
void init()
{
  add_action("do_ok","task");
}
string give_job()
{
  object ob,book;string *map;int i;
  ob=this_player();
  if(ob->query("family/family_name")!="慈航静斋")
  return "施主还是不要在这里停留的好！\n";
  if(ob->query("combat_exp")>150000)
  return "你该出去闯荡江湖，渡世济善了！\n";
  if(time()-ob->query("busy_time")<40+random(10))
  return "你先歇会吧！\n";
  if(ob->query_temp("cihang-job"))
  return "慈航静斋的弟子做事从来不这么马虎的！\n";
  map=keys(here);
  i=random(sizeof(map));
  ob->set_temp("cihang-job",here[map[i]]);
  book=new(__DIR__"book");
  book->move(ob);
  ob->add_temp_array("job_temp_killer",book);
  return "好吧，你去"+map[i]+"抄经书吧！\n";
}
int do_ok(string arg)
{
  object ob,book;string name;
  
  
  ob=this_player();
  if(!arg||!sscanf(arg,"ok with %s",name))
  return notify_fail("请使用task ok with sth 来结束任务。\n");
  if(!ob->query_temp("cihang-job-ok"))
  return notify_fail("慈航静斋的弟子做事从来不这么马虎的！\n");
if(!objectp(book=present(name,ob)))
return notify_fail("你身上没有这个东西！\n");
  if(!book->query_temp("cihang-job-ok"))
  return notify_fail("秦云明一皱眉：这个东西能交差吗？？\n");
  destruct(book);
  
  ob->delete_temp("cihang-job");
  ob->delete_temp("cihang-job-ok");
  ob->delete_temp("cihang-job-times");
  ob->set("busy_time",time());
  
  JOBSYS_D->give_reward_chchujijob(ob);
  
  return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("cihang-job")){
    command("?");
    return 1;
   }
   
   JOBSYS_D->do_cancel_job("chchujijob",ob,this_object());
   command("sigh");
   return 1;
}