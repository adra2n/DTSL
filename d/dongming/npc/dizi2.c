
inherit NPC;
#include <ansi.h>

int do_action1();

void create()
{
   set_name("男弟子",({ "nan dizi","nan","dizi" }) );
        set("gender", "男性" );
	  set("age", 20);
   set("long", "这是东溟派的学艺弟子。\n");
       
   set("combat_exp",100000);
   set("str", 23);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",80);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("force",80);
   set_skill("sword",80);
   set_skill("strike",80);
   set_skill("dongming-xinfa",80);
  
   set_skill("shuiyun-xiufa",80);

   set_skill("nishang-piaoming",80);
   
   set("max_gin",500);
   set("max_sen",500);
   set("max_kee",500);
   set("force",500);
   set("max_force",500);
   set("target_id","###");
   set("inquiry",([
      "求救":(:do_action1:),
      ]));
   create_family("东溟派",7,"弟子");
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("bai_dongming/action1")){
     command("?");
     return 1;
   }
   command("say 你放心，我们东溟派不会让恶人欺负你的！");
   ob->set_temp("guard_npc",this_object());
   return 1;
}