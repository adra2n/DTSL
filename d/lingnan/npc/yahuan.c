
inherit NPC;

void create()
{
   set_name("丫鬟",({ "ya huan","ya","huan" }) );
        set("gender", "女性" );
        set("age", 20);
   set("long", "这是在宋家堡做活的丫鬟。\n");
       
   set("combat_exp", 30000);
   set("str", 20);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("parry",20);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set("chat_chance",60);
   set("chat_msg",({
	   (:random_move:),
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

