
inherit NPC;

void create()
{
   set_name("野兔",({ "rabbity"}) );
        set("race", "野兽" );
        set("combat_exp",20000);
     set("long", "这是一只野兔。\n");
	 set("verbs",({"bite"}));
     set("limbs",({"头","肚子","脚"}));
  setup();

}

void die()
{
  object ob;
  ob=this_object()->query_temp("last_damage_from");
  if(!ob) return ::die();
  message_vision("突然一个人举着个[动物保护协会]的牌子，喊道：要保护动物！\n"+
                 "砰地一脚把$N踹了跟头！\n",ob);
   return ::die();
}              