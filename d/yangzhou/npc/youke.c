
inherit NPC;

void create()
{
   set_name("游客",({ "you ke","you","ke"}) );
   set("gender", "男性" );
   set("age", 30);
		
   set("long", "这是一位到扬州游玩的游客。\n");
       
   set("combat_exp", 100000);
   set("str", 26);
   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  
   set("chat_chance",10);
   set("chat_msg",({
	  "游客说道：据说扬州十分繁华，今天要去看看。\n",
          "游客左右看看：这里的风景还真不错！\n",
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

