inherit NPC;

void create()
{
  set_name("少女",({ "beauty girl","girl"}) );
        set("gender", "女性" );
        set("age", 18);
   set("long", "一个清丽的江南子女，漂亮非常。\n");

   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
}

void init()
{
        object ob,ob2;
        ob=this_player();
        ob2=this_object();
        ::init();
        if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
        call_out("wink",1,ob,ob2);
}

void wink(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting())
    return;
   command("wink"+ob->query("id"));
        remove_call_out("wink");
        return;
}
