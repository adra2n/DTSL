
inherit NPC;
#include <ansi.h>

void create()
{
   set_name("��ͷ",({ "jiao tou","jiao","tou"}) );
        set("gender", "����" );
        set("age", 32);
        
        set("str",30);
        set("dex",30);
        
        set("slwg_jiaotou",1);
        set("long","����ʯ����ݵĽ�ͷ��\n");
        
        set("str",12);
        set("int",12);
        set("con",12);
        set("dex",12);
        
        set_skill("parry",20);
        set_skill("dodge",45);
        set_skill("force",45);
        set_skill("cuff",50);
        
        //set_skill("male-cuff",30);
        //set_skill("babu-ganchan",80);
        
        set("max_force",200);
        set("force",200);
        
        //set_temp("apply/damage",10+random(10));
        
        set("combat_exp",10000);
        set("reward_p",10);
        set("reward_exp",35);
        set("reward_pot",18);
    setup();
   
}
/*
void init()
{
   object ob;
   
   ob=this_player();
   if(!ob) return;
   remove_call_out("welcome");
   call_out("welcome",1,ob);
}

void welcome(object ob)
{
   if(!ob) return;
   
   if(environment(ob)!=environment())
   return;
   
   
     command("hi "+ob->query("id"));
     tell_object(ob,query("name")+"����Ц������������ "+HBMAG+HIW+"qiecuo jiao"+NOR+" �ɡ�\n");
  return;
}*/

int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}

void give_reward(object victim)
{
  /*
  int exp,pot,sil;
   
  
   exp=50+random(10);
   pot=20+random(5);
   sil=200+random(100);
   
   victim->add("combat_exp",exp);
   victim->add("potential",pot);
   if(victim->query("potential")>victim->query("max_pot"))
    victim->set("potential",victim->query("max_pot"));
   victim->add("deposit",sil);
  tell_object(victim,"��õ���"+HIW+chinese_number(exp)+NOR+"�㾭�飬"+
  HIY+chinese_number(pot)+NOR+"��Ǳ�ܡ�\n"+
  MONEY_D->money_str(sil)+"��\n");
  */
  victim->set("busy_time",time());
  
  set("eff_kee",query("max_kee"));
  set("kee",query("max_kee"));
  
  set("eff_sen",query("max_sen"));
  set("sen",query("max_sen"));
  
  set("force",query("max_force"));
  
  return;
}
void unconcious()
{
	set("eff_kee",query("max_kee"));
  set("kee",query("max_kee"));
  
  set("eff_sen",query("max_sen"));
  set("sen",query("max_sen"));
  
  set("force",query("max_force"));
  
  command("addoil");
  command("say �ⳡ�������������ˣ�");
}	  

int end_fight(object killer,object victim)
{
   
    tell_object(victim,query("name")+"һЦ�������������С��\n");
   
   give_reward(victim);
  
  return 1;
}

int surrender(object killer,object victim)
{

   tell_object(killer,query("name")+"һЦ�������������С��\n");
   
   give_reward(killer);
   return 1;
}

int is_end_fight(object ob)
{
  
  return 1;
     
}