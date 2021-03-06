
inherit ITEM;

#include <ansi.h>

void create()
{
   set_name("《换日大法》", ({ "huanri book","book"}));
   set_weight(100);
   set("unit", "本");
   set("long","这是一本讲述换日大法的武林秘籍。\n");
   set("no_give",1);
   
}

void init()
{
  add_action("do_liaoshang","liaoshang");
}

int do_liaoshang(string arg)
{
  object ob,*mem,target;
  string msg;
  string *skills;
  int i;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("你要给谁疗伤？\n");
  
  target=present(arg,environment(ob));
  if(!objectp(target))
  return notify_fail("这里没有这个人。\n");
  
  if(!target->query_temp("dtsl_quest_huanri_action1"))
  return notify_fail("使用此书无法给"+target->name()+"疗伤！\n");
  
  if(!living(target))
  return notify_fail("先把"+target->name()+"弄醒吧！\n");
  
  mem=ob->query_team();
  if(mem)
  mem=mem-({});
  if(sizeof(mem)!=2)
  return notify_fail("必须两个人才能给"+target->name()+"疗伤！\n");
  
  if(!mem[0]->query_skill("changsheng-jue",1)
    &&!mem[1]->query_skill("changsheng-jue",1)
    )
  return notify_fail("必须用长生诀才能给"+target->name()+"疗伤！\n");
  
  if( (mem[0]->query("force_quest/csj1")&&
      mem[1]->query("force_quest/csj1")
      )||
      (mem[0]->query("force_quest/csj2")&&
      mem[1]->query("force_quest/csj2")
      )
    )
   return notify_fail("必须使用长生诀的动静结合才能给"+target->name()+"疗伤！\n");
  
  msg=HIW"$N"+HIW+"和$n"+HIW+"盘膝而做，分别抵住"+target->name()+HIW+"的前心和后背，将长生之气\n"+
      "配合换日大法缓缓给"+target->name()+HIW+"疗伤。\n\n"NOR;
  msg+=HIR"一刻钟后，"+target->name()+HIR"吐了口鲜血！\n"NOR;
  
  message_vision(msg,mem[0],mem[1]);
  
  target->delete_temp("dtsl_quest_huanri_action1");
  if(random(target->query_quest_kar())<27){
  	tell_object(target,"\n你微微运动内息，发觉并没有领悟换日大法。\n\n");
  	target->add("force_quest/hrdf_fail_times",1);
  	if(target->query("force_quest/hrdf_fail_times")>=2){
  		target->set("force_quest/hrdf_fail",1);
  		tell_object(target,"\n你的经脉已经严重受创，看来再也无法领悟换日大法了！\n\n");
  	}
  	destruct(this_object());
  	return 1;
  }
  	
  
  skills=keys(target->query_skills());
  
  if(sizeof(skills)){
  	for(i=0;i<sizeof(skills);i++)
  	 if(SKILL_D(skills[i])->query_type()=="force_skill")
  	   target->delete_skill(skills[i]);
  }
  target->set_skill("huanri-dafa",10);
  target->set("dtsl_quest_huanri_ok",1);
  
  for(i=0;i<2;i++){
   mem[i]->set("max_force",mem[i]->query("max_force")-100);
   if(mem[i]->query("max_force")<0)
      mem[i]->set("max_force",0);
   if(mem[i]->query("force")>mem[i]->query("max_force"))
    mem[i]->set("force",mem[i]->query("max_force"));
  }
  
  destruct(this_object());
  return 1;
}