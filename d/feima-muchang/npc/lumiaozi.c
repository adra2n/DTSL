//鲁妙子.
inherit NPC;
string give_jiguan();
string give_junshi();
string give_miji();
string give_mask();

void create()
{
   set_name("鲁妙子",({ "lu miaozi","lu","zi" }) );
        set("gender", "男性" );
		
        set("age", 42);
   set("long", "他就是江湖上的奇人--鲁妙子。他的天文，\n"+
               "地理，文学，军事等方面都有都有很高的造\n"+
               "诣。\n");
       
   set("combat_exp",500000);
   set("str", 20);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",170);
   set_skill("dodge",170);
   set_skill("parry",170);
   set("inquiry",([
	   "机关学":(:give_jiguan:),
	   //"武功":(:give_miji:),
	   "面具":(:give_mask:),
	   ]));
   set("no_clean_up",1);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

string give_jiguan()
{
	object me,ob,book;
	me=this_player();
	ob=this_object();
	if(me->query_int()<40)
		return "你的悟性太低了，我怎么教你啊？\n";
	if(ob->query("no_jiguan"))
		return "你来晚了，《机关学》我已经给了"+ob->query("no_jiguan")+"\n";
	book=new(__DIR__"obj/jiguanxue");
	book->move(me);
	message_vision("$N给了$n一本《机关学》。\n",ob,me);
	ob->set("no_jiguan",me->name());
	return "你要好好学习我的《机关学》啊！\n";
}

string give_junshi()
{
	object me,ob,book;
	me=this_player();
	ob=this_object();
	if(me->query("int")<30)
		return "你的悟性太低了，我怎么教你啊？\n";
	if((int)me->query_skill("literate",1)<=180)
		return "你的文化水平太差了，领悟不了我的书的！\n";
	if(me->query("combat_exp")<300000)
		return "你的武功实在是低微，这本书对你来说没什么用的！\n";
	if(ob->query("no_junshi"))
		return "你来晚了，《军事学》我已经给了"+ob->query("no_junshi")+"\n";
	book=new(__DIR__"obj/junshixue");
	book->move(me);
	message_vision("$N给了$n一本《军事学》。\n",ob,me);
	ob->set("no_junshi",me->name());
	return "你要好好学习我的《军事学》啊！\n";
}

string give_miji()
{
	object me,ob,book;
	me=this_player();
	ob=this_object();
	if(me->query_int()<45)
		return "你的悟性太低了，我怎么教你啊？\n";
	if(me->query("combat_exp")<800000)
		return "你的武功实在是低微，这本书对你来说没什么用的！\n";
	if(ob->query("no_miji"))
		return "你来晚了，《武学心法》我已经给了"+ob->query("no_miji")+"\n";
	book=new(__DIR__"obj/miji");
	book->move(me);
	message_vision("$N给了$n一本《武学心法》。\n",ob,me);
	ob->set("no_miji",me->name());
	return "这本《武学心法》对你的武功会有很大提高的！\n";
}

string give_mask()
{
	object ob,mask;
	object *target;
	int i,flag;
	
    ob=this_player();
    	    
	if(this_object()->query("no_mask"))
		return "我的面具已经给别人了，你来晚了！\n";
	target=children(__DIR__"obj/mask");
	flag=0;
	for(i=0;i<sizeof(target);i++)
		if(environment(target[i])){
			flag=1;
			break;
		}
	
	if(flag>0)
	return "我的面具已经给别人了，你来晚了！\n";
	mask=new(__DIR__"obj/mask");
	mask->move(ob);
	this_object()->set("no_mask",1);
	return "这是我精心制作的人皮面具，你可要好好保管！\n";
}