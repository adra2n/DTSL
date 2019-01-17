
inherit NPC;

void create()
{
   set_name("尚秀芳",({ "shang xiufang","shang","xiu","fang" }) );
        set("gender", "女性" );
        set("age", 18);
   set("long", "她就是洛阳的第一名妓尚秀芳。\n"+
               "除了她那修长匀称的身段，仪态\n"+
               "万千的举止神情外，更动人的是\n"+
               "她那对能勾魂摄魄的翦水双瞳，\n"+
               "其含情脉脉配合着唇角略带羞涩\n"+
               "的盈盈浅笑，确是没有男人能抵\n"+
               "挡得住的。\n");
       
   set("combat_exp", 100);
   set("famous",1000000);
   set("str", 14);
   set("per", 28);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   add_money("coin", 50);
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
   
	if(!ob||environment(ob)!=environment(this_object()))
	return;
	
	if(wizardp(ob))
	{message_vision("$N连忙上前：原来是巫师大人，有什么妾身可以帮忙的吗？\n",ob2);
	return;}
	//this is a joke.
	
	if(ob->query("gender")=="男性")
   {
	   if((int)ob->query("famous",1)>5000)
	   {
		   if((int)ob->query("per")==30)
			   message_vision("$N脉脉含情地说道：这位"+RANK_D->query_respect(ob)+"，妾身久仰很久了！\n",ob2);
		   else if((int)ob->query("per",1)==29)
			    message_vision("$N微微一笑：这位"+RANK_D->query_respect(ob)+"，妾身久仰很久了！\n",ob2);
		   else if((int)ob->query("per",1)==28)
			   message_vision("$N淡淡一笑：这未"+RANK_D->query_respect(ob)+"，妾身久仰很久了！\n",ob2);
	   }
	   else message_vision("$N朝$n淡淡一笑。\n",ob2,ob);
   }
   else
   {
	   if((int)ob->query("famous",1)>5000)
	   {
		   if((int)ob->query("per")==30)
			   message_vision("$N恭恭敬敬地说道：这位"+RANK_D->query_respect(ob)+"，妾身久仰很久了！\n",ob2);
		   else if((int)ob->query("per",1)==29)
			    message_vision("$N微微一笑：这位"+RANK_D->query_respect(ob)+"，妾身久仰很久了！\n",ob2);
		   else if((int)ob->query("per",1)==28)
			   message_vision("$N淡淡一笑：这位"+RANK_D->query_respect(ob)+"，妾身久仰很久了！\n",ob2);
	   }
	   else message_vision("$N朝$n淡淡一笑。\n",ob2,ob);
   }
   return;
}
 
