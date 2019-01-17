//普通的npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("小姐", ({ "lady"}) );
       set("gender", "女性" );
       set("age", 20);
       set("long",
               "她是成都李财主家的大小姐。\n");
       set("combat_exp", 22500);
       set("attitude", "friendly");
       
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "小姐说道：这位" + RANK_D->query_respect(ob)
          + "哎，我可真想去扬州玩玩呀!\n");
			break;
		case 1:
			say( "小姐看了看你。\n");
			break;
	}

}
