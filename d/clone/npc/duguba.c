
inherit NPC;

void create()
{
   set_name("独孤霸",({ "dugu ba","dugu","ba" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "他是独孤阀的高手独孤霸，在洛阳也是横行一方。\n");
   set("shili","dugu");
   set("combat_exp",600000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",180);
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("sword",180);
   set_skill("cuff",180);
   set_skill("dugu-jianfa",180);
   set_skill("youming-zhang",180);
   set("max_gin",1500);
   set("max_sen",1500);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

