#include <ansi.h>
#include <org.h>
#include <job_money.h>

inherit JOBNPC;

int is_city_war_guard()
{
   return 1;
   
}

void create()
{
        set_name("士兵", ({"guard"}));
        set("long", "这是一名士兵。\n");
        set("attitude", "peaceful");

        set("max_gin", 800);
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 500);
        set("max_force", 500);
        set("combat_exp", 500000);
        set("age",20);
        
       setup();
}

int set_status(int i,string type,int armor,int damage,string org_name)
{
   
   set("guard_type",type);
   set("number",i);
   set("shili/name",org_name);
   
   set_temp("apply/armor",(random(armor/2)+random(armor/2))/2);
   set_temp("apply/damage",(random(damage/2)+random(damage/2))/2);
   
   if(type=="lev1"){
     set_this_skills("low");
     set_all_skill(this_object(),50+i*2);
   
     set("max_gin",100*i);
     set("eff_gin",100*i);
     set("gin",100*i);
   
     set("max_kee",100*i);
     set("eff_kee",100*i);
     set("kee",100*i);
   
     set("max_sen",100*i);
     set("eff_sen",100*i);
     set("sen",100*i);
   
     //set("max_force",100*i);
     //set("force",100*i);
   
     set("combat_exp",100000+500*i);
    
   }
  else
  if(type=="lev2"){
     set_this_skills("low");
     set_all_skill(this_object(),50+i*2);
   
     set("max_gin",100*i);
     set("eff_gin",100*i);
     set("gin",100*i);
   
     set("max_kee",100*i);
     set("eff_kee",100*i);
     set("kee",100*i);
   
     set("max_sen",100*i);
     set("eff_sen",100*i);
     set("sen",100*i);
   
     set("max_force",300*i);
     set("force",300*i);
   
     set("combat_exp",100000+500*i);
   }
  else
  if(type=="lev3"){
     set_this_skills("middle");
     set_all_skill(this_object(),150+i*3);
   
     set("max_gin",1000+200*i);
     set("eff_gin",1000+200*i);
     set("gin",1000+200*i);
   
     set("max_kee",1000+200*i);
     set("eff_kee",1000+200*i);
     set("kee",1000+200*i);
   
     set("max_sen",1000+200*i);
     set("eff_sen",1000+200*i);
     set("sen",1000+200*i);
   
    // set("max_force",1500+400*i);
     //set("force",1500+400*i);
   
     set("combat_exp",800000+500*i);
        
   }
   else
  if(type=="lev4"){
     set_this_skills("high");
     set_all_skill(this_object(),150+i*4);
     add_temp("apply/damage",query("number")*20);
     add_temp("apply/armor",-query("number")*10);
   
     set("max_gin",500+100*i);
     set("eff_gin",500+100*i);
     set("gin",500+100*i);
   
     set("max_kee",500+100*i);
     set("eff_kee",500+100*i);
     set("kee",500+100*i);
   
     set("max_sen",500+100*i);
     set("eff_sen",500+100*i);
     set("sen",500+100*i);
   
    // set("max_force",1500+400*i);
     //set("force",1500+400*i);
   
     set("combat_exp",800000+500*i);
   
   }
   else
  if(type=="lev5"){
     set_this_skills("high");
     set_all_skill(this_object(),150+i*4);
     add_temp("apply/damage",query("number")*30);
     add_temp("apply/armor",-query("number")*20);
   
     set("max_gin",100+50*i);
     set("eff_gin",100+50*i);
     set("gin",100+50*i);
   
     set("max_kee",100+50*i);
     set("eff_kee",100+50*i);
     set("kee",100+50*i);
   
     set("max_sen",100+50*i);
     set("eff_sen",100+50*i);
     set("sen",100+50*i);
   
    // set("max_force",1500+400*i);
     //set("force",1500+400*i);
   
     set("combat_exp",800000+500*i);
     
   }
        
   return 1;
}

void init()
{
   add_action("do_xingjun","xingjun");
   add_action("do_jixingjun","jixingjun");
   add_action("do_chuzhan","chuzhan");
   add_action("do_rest","rest");
   add_action("do_supply",({"buji","supply"}));
   
}



int do_xingjun(string arg)
{
   object ob;
   string name,dir;
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"%s %s",dir,name)!=2)
   return notify_fail("请使用 xingjun 方向 士兵ID。\n");
   
   if(!id(name))
    return 0;
   
   if(ob->query_temp("city_war_guard")!=this_object())
   return notify_fail("这不是你带的兵！\n");
   
   
   
   if(ob->is_busy()||ob->is_fighting())
   return notify_fail("你正忙着呢！\n");
   
   if(is_busy())
   return notify_fail("对方正忙着呢！\n");
   
   if(!environment(ob)->query("exits/"+dir))
   return notify_fail("这里没有这个方向。\n");
   
   this_object()->do_command("go "+dir);
   add("tired",random(2)+1);
   if(query("tired")>=20){
     tell_object(ob,HIY"\n"+query("name")+"已经相当疲劳，继续行军会发生生命危险，请使用rest命令来休息吧！\n"NOR);
     receive_damage("kee",300*query("number"));
   }
   start_busy(3);
   
   return 1;
   
}

int do_jixingjun(string arg)
{
   object ob;
   string name,dir;
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"%s %s",dir,name)!=2)
   return notify_fail("请使用 jixingjun 方向 士兵ID。\n");
   
   if(!id(name))
    return 0;
   
   if(ob->query_temp("city_war_guard")!=this_object())
   return notify_fail("这不是你带的兵！\n");
   
   if(ob->is_busy()||ob->is_fighting())
   return notify_fail("你正忙着呢！\n");
   
   if(is_busy())
   return notify_fail("对方正忙着呢！\n");
   
   if(!environment(ob)->query("exits/"+dir))
   return notify_fail("这里没有这个方向。\n");
   
   this_object()->do_command("go "+dir);
   add("tired",random(2)+6);
   if(query("tired")>=20){
     tell_object(ob,HIY"\n"+query("name")+"已经相当疲劳，继续行军会发生生命危险，请使用rest命令来休息吧！\n"NOR);
     receive_damage("kee",300*query("number"));
   }
   start_busy(1);
   
   return 1;
   
}

int do_rest(string arg)
{
   object ob;
   
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("请使用 rest 士兵ID。\n");
   
   if(!id(arg))
    return 0;
   
   if(ob->query_temp("city_war_guard")!=this_object())
   return notify_fail("这不是你带的兵！\n");
   
   if(ob->is_busy()||ob->is_fighting())
   return notify_fail("你正忙着呢！\n");
   
   if(is_busy())
   return notify_fail("对方正忙着呢！\n");
   
   message_vision("$N停了下来，开始休息。\n",this_object());
   delete("tired");
   add_temp("apply/damage",query("reduce_d_a"));
   add_temp("apply/armor",query("reduce_d_a"));
   add_temp("apply/dodge",query("reduce_d_a"));
   delete("reduce_d_a");
   start_busy(20);
   
   return 1;
   
}

void check_owner(object ob)
{
    
     
    
    if(!ob){
      message_vision("$N四散走开了。\n",this_object());
      destruct(this_object());
      return;
    }
    if((ob&&ob->is_ghost())||query("reduce_d_a")>=500){
      message_vision("$N四散走开了。\n",this_object());
      destruct(this_object());
      return;
    }
    set("long","这是一名士兵。\n"+HIG+"隶属于"+ob->name()+"\n"NOR);
    
    if(is_fighting()){
      if(query("guard_type")=="lev4")
        add("tired",query("number")/3);
      if(query("guard_type")=="lev3")
        add("tired",query("number"));
      if(query("guard_type")=="lev5")
        add("tired",query("number")/3);
    }
    
    add("cost_time",1);
    
    if(random(query("tired")+query("zhongcheng_du"))>query("zhongcheng_du")){
      tell_object(ob,HIG"\n士兵疲劳过度，战斗力逐渐降低了！\n"NOR);
      add("reduce_d_a",query("tired"));
      add_temp("apply/damage",-query("reduce_d_a"));
      add_temp("apply/armor",-query("reduce_d_a"));
      add_temp("apply/dodge",-query("reduce_d_a"));
   }
   
   if(query("cost_time")>=120){
     message_vision("$N四散走开了。\n",this_object());
     if(ob)
      ob->delete_temp("dtsl_job");
     destruct(this_object());
     return;
   }
    
    call_out("check_owner",5,ob);
    
}

void die()
{
  object ob;
  
  ob=query("owner_ob");
  if(ob)
   ob->delete_temp("dtsl_job");
  
  return ::die();
  
}

int do_chuzhan(string arg)
{
  object ob,guard,target;
  int i;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("请使用 chuzhan 目标士兵ID。\n");
  
  if(!objectp(guard=ob->query_temp("city_war_guard")))
  return notify_fail("你没有带兵。\n");
  
  if(environment(guard)!=environment(ob))
  return notify_fail("你和士兵不在一起！\n");
  
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("这里没有这个目标！\n");
  
  if(!target->is_city_war_guard())
  return notify_fail("你只能让自己的士兵攻击对方的士兵！\n");
   
  if(guard->query("shili/name")==target->query("shili/name"))
  return notify_fail("你不能阵前起义！\n");
  
  if(ORG_D->is_friend_org(guard,target))
  return notify_fail("你不能攻击盟友的士兵！\n");
  
  message_vision("\n只听军鼓敲响，$N指挥$n开始战斗！\n",ob,guard);
  guard->kill_ob(target);
  
  if(guard->query("guard_type")=="lev5"){
      COMBAT_D->do_attack(guard,target,guard->query_temp("weapon"),0,1);
      if(target)
       COMBAT_D->do_attack(guard,target,guard->query_temp("weapon"),0,1);
      if(target)
       COMBAT_D->do_attack(guard,target,guard->query_temp("weapon"),0,1);
      
      start_busy(5);
  }
   
   return 1;
   
}     

varargs int receive_damage(string type, int damage, object who)
{
    if(who&&userp(who))
      damage=damage/10;
   
    return ::receive_damage(type,damage,who);
    
}

varargs int receive_wound(string type, int damage, object who)
{
    if(who&&userp(who))
      damage=damage/10;
 
    return ::receive_wound(type,damage,who);
    
}

int accept_fight(object ob)
{
  if(!ob->is_city_war_guard())
   return 0;
  
  return 1;
  
}

void kill_ob(object ob)
{
   if(!ob->is_city_war_guard()){
     ob->remove_killer(this_object());
     remove_killer(ob);
     return ;
   }
   
   ::kill_ob(ob);
   
}   

int do_supply(string arg)
{
  object ob,guard,target;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("请使用 supply/buji 目标id。\n");
  
  if(!objectp(guard=ob->query_temp("city_war_guard")))
  return notify_fail("你没有带兵。\n");
  
  if(environment(guard)!=environment(ob))
  return notify_fail("你和士兵不在一起！\n");
  
  if(guard->query("guard_type")!="lev2")
  return notify_fail("此类士兵不能给别人补给。\n");
  
  if(guard->is_busy())
  return notify_fail("你的士兵正忙着呢！\n");
  
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("这里没有这个目标！\n");
  
  if(!target->is_city_war_guard())
  return notify_fail("被补给的目标只能是士兵。\n");
   
  if(guard->query("shili/name")!=target->query("shili/name")&&
     !ORG_D->is_friend_org(guard,target))
  return notify_fail("你不能给敌人补给！\n");
  
  message_vision("$N卸下粮食和水，给了$n，$n顿时士气大振，疲劳顿消！\n",
   guard,target);
  
  target->delete("tired");
  target->add_temp("apply/damage",query("reduce_d_a"));
  target->add_temp("apply/armor",query("reduce_d_a"));
  target->add_temp("apply/dodge",query("reduce_d_a"));
  target->delete("reduce_d_a");
  
  target->start_busy(2);
  guard->start_busy(2);
  
  return 1;
  
}
  