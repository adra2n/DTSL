inherit ITEM;
#include <job_money.h>
#include <ansi.h>
int do_find();
void create()
{
	set_name("地图",({"map"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一张高丽城市的平面分布图.\n");
		set("unit", "张");
		set("no_drop",1);
		set("no_give",1);
		set("no_steal",1);
	 }
}
void init()
{
  add_action("do_find","soucha");
}
int do_find()
{
  object ob;string here;
  object killer;
  ob=this_player();
  if(!ob->query_temp("gaoli_kill_job"))
  return notify_fail("你看了看地图，没发现什么新奇的东西。\n");
  here=base_name(environment(ob));
  if(here!=query("here"))
  return notify_fail("你照着地图看了看，发现盗贼出没的地方好象不是此处。\n");
  if(ob->query_temp("have_killer"))
  return notify_fail("加油，加油!!!\n");
  killer=new(__DIR__"killer");
 killer->set("combat_exp",ob->query("combat_exp"));
 if("/cmds/usr/hp.c"->get_pot(killer));
 set_all_skill(killer,killer->query("max_pot")-130);
 copy_hp_item(ob,killer,"gin");
 copy_hp_item(ob,killer,"kee");
 copy_hp_item(ob,killer,"sen");
 killer->set("max_force",ob->query("max_force"));
 killer->set("force",ob->query("max_force"));
 if(ob->query("combat_exp")>=500000)
 killer->improve_level();
  killer->delete("family");
  killer->delete("nickname");
  killer->delete("shili");
  killer->set_name("盗贼",({"killer"}));
  killer->set("target_id",ob->query("id"));
  killer->set_temp("apply/armor",50+random(50));
  killer->move(environment(ob));
  ob->start_busy(1);
  ob->set_temp("have_killer",1);
  message_vision(HIR"$N突然纵身而出，朝$n冷笑道：既然被你发现，也只好拼命了！！\n"NOR,killer,ob);
  killer->kill_ob(ob);
  message_vision("\n$N心一慌，地图掉到了地上！\n",ob);
  destruct(this_object());
  return 1;
}
