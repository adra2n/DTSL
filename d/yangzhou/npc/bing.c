
inherit "/std/guard.c";

void create()
{
   set_name("官兵",({ "bing" }) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是守卫扬州城的官兵，在这里检查来往的行人。\n");
       
   set("combat_exp",800000);
   set("str", 26);
   set("per", 22);
   set("guard","yangzhou");
   set("attitude", "peaceful");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
   
}

