
inherit ITEM;

void create()
{
        set_name("灵芝", ({ "ling zhi","ling","zhi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
				set("long","这是一棵灵芝，可以用来炼药。\n");
                set("value", 3);
				set("wei_med",1);
				set("heal",([
					"heals":100,
					]));
                
        }

      
        setup();
}
