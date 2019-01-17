
inherit NPC;

void create()
{
   set_name("香客",({ "xiang ke","xiang","ke"}) );
   set("gender", "男性" );
   set("age", 30);
		
   set("long", "这是一位到扬州上香的香客。\n");
       
   set("combat_exp", 100000);
   set("str", 26);
   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  
   set("chat_chance",10);
   set("chat_msg",({
	   (:do_command,"flook1":),
	   (:do_command,"story":),
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

