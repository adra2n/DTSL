
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("马",({ "horse"}) );
        set("race", "野兽" );
     set("long", "这是一匹马，看起来非常好。\n");
     set("verbs",({"hoof"}));
	 set("limbs",({"头","腿","肚子"}));
     set("chat_chance",50);
     set("chat_msg",({
     "马低头吃了几口草。\n",
     "马仰起头来，高声嘶叫了几声。\n",
     }));
  setup();

}
