
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("牛皮水袋", ({"shuidai","dai"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "一个用来装水的水袋。\n");
     set("unit", "个");
     set("value", 20);
     set("max_liquid", 20);
   }

  
   set("liquid", ([
     "type": "water",
     "name": "清水",
     "remaining": 20,
     "drunk_supply": 6,
   ]));
}

