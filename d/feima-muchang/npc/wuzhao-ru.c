
inherit NPC;

void create()
{
   set_name("吴兆汝",({ "wu zhaoru","wu"}) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "他就是飞马牧场的四大执事之四。\n");
       
   set("combat_exp",400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",130);
   set_skill("dodge",130);
   set_skill("parry",130);
   set_skill("babu-ganchan",130);
   set("dodge",({"babu-ganchan"}));

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

