
inherit NPC;

void create()
{
   set_name("野鸡",({ "ye ji","ji"}) );
        set("race", "野兽" );
        set("combat_exp",30000);
     set("long", "这是一只野鸡，身上的羽毛很好看。\n");
	 set("verbs",({"bite","claw"}));
     set("limbs",({"头","腹部","腰部"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/yumao");
   ob->move(environment(this_object()));
   message_vision("$N仰头叫了一声，腾地一下倒在了地上。\n",this_object());
   destruct(this_object());
   return;
}

