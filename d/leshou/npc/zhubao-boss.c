
inherit F_VENDOR_SALE;
void create()
{
    reload("leshou_zhubao-boss");
   set_name("李老板",({ "li laoban","li","lao","ban" }) );
   set("gender", "男性" );
   set("age", 40);
   set("long", "他是珠宝店的老板，看起来才大气粗。\n");
   set("combat_exp", 500000);   
   set("attitude", "friendly");
   set("vendor_goods",([
	   "feicui-xianglian":__DIR__"obj/feicui-neck",
	   "huangjin-xianglian":__DIR__"obj/huangjin-neck",
	   "manao-xianglian":__DIR__"obj/manao-neck",
	   "baiyu-jiezhi":__DIR__"obj/baiyu-finger",
	   "hupo-jiezhi":__DIR__"obj/hupo-finger",
	   
   ]));
   setup();
 //  carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
}

int regenerate()
{
        set("called", 0);
        return 1;
}
