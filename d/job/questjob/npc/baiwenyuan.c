
inherit NPC;

void create()
{
   set_name("白文原",({ "bai wenyuan","bai"}) );
        set("gender", "男性" );
        set("age", 22);
		
   set("long", "这是净剑宗新冒起来的高手，也是朱媚的现任\n"+
               "面首，在四川颇有名气。\n");
       
   set("combat_exp", 30000);
   set("str", 30);
   set("per", 26);
   
   set_skill("force",140);
   set_skill("parry",140);
   set_skill("dodge",140);
   set_skill("sword",140);
   
   set_skill("babu-ganchan",140);
   set_skill("leveltwo-sword",140);
   
   setup();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

