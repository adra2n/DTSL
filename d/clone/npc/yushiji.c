
inherit NPC;

void create()
{
   set_name("虞世基",({ "yu shiji","yu","shiji" }) );
        set("gender", "男性" );
        set("age", 42);
        set("tetle","内史待郎");
   set("long", "他是隋朝的虞世基,杨广手下的红人。\n");
   set("combat_exp",6000);
   set("str", 28);
   set("per", 23);
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
   carry_object(__DIR__"obj/guanxue")->wear();
}

