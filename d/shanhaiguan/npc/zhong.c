
inherit NPC;

void create()
{
   set_name("帮众",({ "bangzhong","zhong" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是塞漠帮的帮众，在这里检查来往的行人。\n");
       
   set("combat_exp",200000);
   set("attitude", "peaceful");
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
   //carry_object("/d/obj/gangjian")->wield();
  
}

