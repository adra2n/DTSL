
inherit ITEM;
#include <ansi.h>
#include <job_money.h>
int do_mi(string arg);
void create()
{
   set_name(YEL"迷香"NOR,({ "mixiang" }));    
   set("long", "这是一个人贩子常用的迷香,可以用它迷倒[mi]对方。\n");       
  set("unit","个");
  set("no_get",1);
  set("no_give",1);
  set("no_drop",1);
   setup();
  
}
void init()
{
  add_action("do_mi","mi");
}

string *msg=({
"$N朝着$n冷笑道：你今天撞到我手里，算你倒霉！！",
"$N大叫一声：连我的情人你也碰，真是活够了！！",
"$N吐了口吐沫，朝$n喊道：大爷我和你拼了！！",
"$N一撸胳膊，好你个混蛋，好事不做，专做这下三滥的勾当，去死吧！！\n"
});

int do_mi(string arg)
{
  object ob,target,*guard;
  int i;
  
  ob=this_player();
  if(!arg)
  return notify_fail("你要迷倒谁？\n");
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("这里没有这个人！\n");
  if(target->query("target")!=ob)
  return notify_fail("这不是你要迷倒的目标！\n");
  
  if(ob->is_busy())
  return notify_fail("你正忙着呢！\n");
  
  if(!living(target))
  return notify_fail("对方不处在清醒状态，不需要用迷香。\n");
  
  guard=all_inventory(environment(ob));
  
  for(i=0;i<sizeof(guard);i++){
  
    if(guard[i]->query_leader()==target)
     return notify_fail(guard[i]->name()+"横了你一眼，你停住了手脚！\n");
  }
  
  message_vision(YEL"$N拿起迷香，朝$n吹了过去！\n"NOR,ob,target);
  message_vision(RED"$N身子颤了几颤，摇晃了一下！\n"NOR,target);
  target->unconcious();

  return 1;
}
