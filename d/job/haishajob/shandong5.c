
#include <ansi.h>
#include <job_money.h>
inherit ROOM;
int do_wa(string arg);
void create ()
{
  set ("short",HIB"山洞"NOR);
  set ("long", @LONG
这里是一个山洞，黑黑的，几乎看不到有什么出路。据说最近这里
来了很多抢宝藏的人。这里已经是山洞的尽头了。
LONG);

  set("exits", ([ 
 "out":__DIR__"shandong4",
        ]));
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_wa","wa");
}

int valid_leave(object ob,string dir)
{
  object killer,killer2;
  object *targets;
  int i;
  if(ob->query("job/duobao_job")&&!ob->query("job/flag3"))
  {
    ob->set("job/flag3",1);
    killer=new(__DIR__"killer"+(1+random(6)));
    killer->move(environment(ob));
    killer->set("combat_exp",ob->query("combat_exp")+300000);
    set_all_skill(killer,ob->query("max_pot")-80);
    killer->set("target_id",ob->query("id"));
    copy_hp_item(ob,killer,"gin");
    copy_hp_item(ob,killer,"kee");
    copy_hp_item(ob,killer,"sen");
    killer->set("max_force",ob->query("max_force"));
    killer->set("force",ob->query("max_force"));
    killer->kill_ob(ob);
    killer2=new(__DIR__"killer"+(1+random(6)));
    killer2->move(environment(ob));
    killer2->set("combat_exp",ob->query("combat_exp"));
    killer2->set("target_id",ob->query("id"));
    set_all_skill(killer2,ob->query("max_pot")-80);
    copy_hp_item(ob,killer2,"gin");
    copy_hp_item(ob,killer2,"kee");
    copy_hp_item(ob,killer2,"sen");
    killer2->set("max_force",ob->query("max_force"));
    killer2->set("force",ob->query("max_force"));
    killer2->kill_ob(ob);
    ob->kill_ob(killer);
    ob->kill_ob(killer2);
    return notify_fail("猛然跳出两个人，冷笑道：既然来了，就别走了！\n");
   }
  if(ob->query("job/duobao_job")){
   targets=all_inventory(environment(ob));
   for(i=0;i<sizeof(targets);i++)
   if(targets[i]->query("target_id")==ob->query("id")&&
      targets[i]!=ob)
   return notify_fail("杀手一把抓住了你！\n");}
  return ::valid_leave(ob,dir);
}

int do_wa(string arg)
{
  object ob,map;
  ob=this_player();
  if(!arg||arg!="藏宝图"||!ob->query("job/duobao_job")
  ||ob->query("job/get_map"))
  return notify_fail("什么?\n");
  ob->set("job/get_map",1);
  map=new(__DIR__"map");
  message_vision("$N蹲下身去，挖了起来！\n",ob);
  message_vision("$N挖到了一份藏宝图！\n",ob);
  map->move(ob);
  return 1;
}