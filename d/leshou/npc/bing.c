
inherit "/std/guard.c";

void create()
{
   set_name("官兵",({ "bing" }) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是一个守卫乐寿的官兵。\n");
       
   set("combat_exp",800000);  
   set("attitude", "peaceful");
   set("chat_chance",50);
   set("guard","pengliang");
   set("chat_msg",({
   	(:random_move:),
      "军官喝道：都他奶奶的给老子闪开！！\n",
   }));
   
   set_this_skills("high");
   set_all_skill(this_object(),160);
   
   setup();
  
  
}

