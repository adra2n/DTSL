
inherit NPC;

void create()
{
   set_name("公子",({ "gongzi","gong","zi" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这里一个风流倜傥的公子，平时在洛阳闲逛。\n");
       
   set("combat_exp", 500);
   set("str", 20);
   set("per", 22);
   set("attitude", "peaceful");
   set("inquiry",([
	   "洛阳":"洛阳？哦，这里是王世充的地盘啊!\n",
	   "和氏璧":"和氏璧？据说在城南郊区的寺庙里.\n",
	   ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N看了你一眼，又向别处望去。\n",ob2);break;
	case 1: message_vision("$N对$n笑道：来洛阳有什么不懂的就问我好了!\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
