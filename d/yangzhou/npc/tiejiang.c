
inherit F_VENDOR_SALE;
inherit F_REPAIR;
void create()
{
   reload("yz_zhensao");
   set_name("铁匠",({ "tie jiang","tie","jiang","tiejiang" }) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是扬州的铁匠，他打造的兵器都是很好。\n");
      set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) );   
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "changjian":__DIR__"obj/changjian",
	  "blade":__DIR__"obj/blade",
          "axe":__DIR__"obj/axe",
          "spear":__DIR__"obj/spear",
          "tiejia":"/obj/armor/tiejia",
          "zhihuan":__DIR__"obj/feicui-finger",
          "huwan":__DIR__"obj/gangwan",
          "yinqiang":__DIR__"obj/wanyue-qiang",
          "yaodai":__DIR__"obj/yaodai",
	  ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
	add_action("do_repair",({"repair","xiu"}));
	
}

int accept_object(object who,object ob)
{
	if(!who->query_temp("repair_money"))
		return notify_fail("先让我看看兵器啊，我可不能乱收钱!\n");
	if(ob->query("money_id") && ob->value()>=(int)who->query_temp("repair_money",1))
	{	tell_object(who,"好了，这些钱够了!\n");
	    who->set_temp("can_repair",1);
		return 1;
	}
	else return notify_fail("这点钱不够的!\n");
   
}

int regenerate()
{
        set("called", 0);
        return 1;
}
