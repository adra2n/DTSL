
inherit NPC;

void create()
{
   set_name("马",({ "horse"}) );
        set("race", "野兽" );
     set("long", "这是一匹飞马牧场养的马。\n");
     set("verbs",({"hoof"}));
	 set("limbs",({"头","腿","肚子"}));
  setup();

}

