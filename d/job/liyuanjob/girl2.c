
inherit NPC;
#include <ansi.h>
void create()
{
   set_name(HIG"绿衣舞女"NOR,({ "girl" }) );
        set("gender", "女性" );
        set("age",18);
   set("long", "这是李阀府中的一名舞女。\n");
       
   set("combat_exp",100);
   set("str",10);
   set("per",23);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/lv_cloth")->wear();
  
}

