
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("猪腿", ({"zhu tui","tui"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个野猪腿。\n");
                set("unit", "个");
                set("food_remaining",55);
                set("food_supply", 55);
        }
}

