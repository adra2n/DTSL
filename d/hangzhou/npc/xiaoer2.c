
inherit F_VENDOR_SALE;
void create()
{
   reload("hz_xiaoer2");
   set_name("店小二",({ "xiao er","xiao","er" }) );
    set("shop_id",({ "xiao er","xiao","er" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是[西湖楼]酒店的店小二。\n");
       
   set("combat_exp", 50000);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "cuyu":__DIR__"obj/hangzhou-cuyu",
	   "kaoya":__DIR__"obj/kaoya",
	   "niurou":__DIR__"obj/niurou",
	   "jiudai":__DIR__"obj/jiudai",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
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
