
inherit NPC;
#include <ansi.h>

int do_quest();

void create()
{
   set_name("神算子",({ "shensuan zi","shensuan","zi"}) );
   set("gender", "男性" );
   set("age",65);
   set("nickname","小太白");
   set("long","他是一个算命先生，据说他算的命很准。\n"+
              "手里拿着一个布幡，上面写着十两黄金一次。\n");
   set("max_kee",300);
   set("max_gin",300);
   set("max_sen",300);
   set("combat_exp",200000);
   set("inquiry",([
     "算命":(:do_quest:),
     ]));
   set("chat_chance",20);
   set("chat_msg",({
    "神算子高声喊道：算命，算命，不准不要钱了～　～　～!\n",
    "神算子高声道：每次算命十两黄金，老少无欺喽～　～　～!\n",
    }));
   setup();
    
}
void die()
{
  message_vision(HIR"$N纵声一叹：没想到我一个算命先生都没有生存之地！\n"NOR,this_object());
  return ::die();
}

int do_quest()
{
  object ob,who;
  int kar;
  who=this_player();
  ob=this_object();
  if(!who->query_temp("can_suanming")){
   command("say 不给钱我怎么给你算命啊？\n");
   return 1;
  }
  who->delete_temp("can_suanming");
  kar=who->query("kar");
  if(kar<=15){
  	message_vision("$N朝地吐了口痰。\n",this_object());
  	command("say 倒霉，倒霉，今天怎么碰上了你，太晦气了！\n");
  }
  else
  if(kar<=20){
  	message_vision("$N长叹了一声：命运多坎坷，你万事小心吧！\n",this_object());
        message_vision("$N看了$n一眼，无奈地摇了摇头。\n",this_object(),who);
        command("say 你还是走吧。\n");
  }
  else
  if(kar<=25){
          message_vision("$N放开了$n的手：命是好命，只是无大富大贵之相。\n",this_object(),who);      
          message_vision("$N长叹道：真龙天子在哪里呀！\n",this_object());
          command("say 你以后小心行事吧！\n");
  }
  else
  if(kar<=27){
  	  message_vision("$N长叹道：好命，好命，一等一的好命！\n",this_object());
  	  message_vision("$N偷偷看了$n一眼，马上又转移了视线。\n",this_object(),who); 
  	  command("say 你可要好好把握自己啊\n");
  }
  else{
         message_vision("$N仰天长叹道：苍天有眼，苍天有眼，我朝有幸啊！真是死而无憾了！\n",this_object());
         command("say 你一定要多多努力，成就一翻事业！");
  }
  return 1;
  
}

int accept_object(object who,object ob)
{
  if(!ob->query("money_id"))
  return notify_fail("我算命除了钱，什么也不要！\n");
  if(ob->value()<100000)
  return notify_fail("你也太小瞧我了吧？才给我这么点钱！\n");
  
  tell_object(who,"好吧，想算命就尽管问我吧！\n");
  who->set_temp("can_suanming",1);
  return 1;
  
}