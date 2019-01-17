
#include <ansi.h>
#include <job_money.h>
inherit ITEM;

int do_find();

void create()
{
        set_name("通缉令", ({ "paper" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("value", 300);
                set("material", "wood");
        }

        setup();
}

string long()
{
  return "\n"+
  "※※※※※※※※※※※※※※※※\n"+
  "  这是一张通缉令，上面写着  \n"+
  "　　　　　　　　　　　　　　\n"+
  "　　　　  缉拿反贼          \n"+
  ""+"         "+query("target_name")+"      \n"+
  "          藏身在　　　　　　\n"+
  ""+"         "+query("target_place")+"      \n"+
  "※※※※※※※※※※※※※※※※\n";
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
  if(!ob->query_temp("liyuan_job/step"))
  return notify_fail("你看了看地图，发现反贼好象不是藏在这里。\n");
  here=base_name(environment(ob));
  if(here!=query("target_where"))
  return notify_fail("你照着地图看了看，发现反贼出没的地方好象不是此处。\n");
  killer=new(__DIR__"killer1");
  killer->set("combat_exp",ob->query("combat_exp"));
  set_all_skill(killer,ob->query("max_pot")-80);
  copy_hp_item(ob,killer,"gin");
  copy_hp_item(ob,killer,"kee");
  copy_hp_item(ob,killer,"sen");
  killer->set("max_force",ob->query("max_force"));
  killer->set("force",ob->query("max_force"));
  killer->set("target_id",ob->query("id"));
  killer->set("name",query("target_name"));
  killer->set("long","据说此人经常同李阀做对，长安李阀已经派"+ob->query("name")+"来缉拿他了。\n");
  killer->set_temp("apply/armor",50+random(50));
  killer->move(environment(ob));
  message_vision(HIR"$N突然纵身而出，朝$n冷笑道：既然被你发现，也只好拼命了！！\n"NOR,killer,ob);
  killer->kill_ob(ob);
  message_vision("\n$N心一慌，通缉令掉到了地上！\n",ob);
  destruct(this_object());
  return 1;
}
