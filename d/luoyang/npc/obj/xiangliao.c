
inherit ITEM;

void create()
{
   set_name("香料", ({ "xiang liao","liao","elite_thing_xiangxiao"}) );
   //{elite_thing_xiangxiao}用于判断的标志性名字
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是用极品丹桂花做成的香料。\n");
     set("unit", "包");
     set("super", 1);
     set("value",100000);
     set("no_sell",1);
     set("order",2);
     set("quest_order",1);
     set("nogive_player",1);
  }
   setup();
}
