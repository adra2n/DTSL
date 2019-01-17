
inherit F_VENDOR_SALE;
inherit F_REPAIR;

void create()
{
   reload("slwg_tiejiang");
   
   set_name("铁匠",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("gender", "男性" );
   set("age", 40);
   set("long", "这是石龙武馆里的铁匠，专门向学习武艺的弟子出售兵器。\n");
   set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("combat_exp",300000);
   
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("force",80);
   set_skill("duanzao-jishu",200);
   
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "sword":__DIR__"obj/sword",
	  "blade":__DIR__"obj/blade",
	  "spear":__DIR__"obj/spear",
	  "dagger":__DIR__"obj/dagger",
	  "whip":__DIR__"obj/whip",
	  "hammer":__DIR__"obj/hammer",
	  "toukui":__DIR__"obj/toukui",
	  "yaodai":__DIR__"obj/yaodai",
	  "zhanxue":__DIR__"obj/zhanxue",
	  "staff":__DIR__"obj/staff",
	  ]));
 
   setup();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
	add_action("do_repair",({"repair","xiu"}));
	
	
}
