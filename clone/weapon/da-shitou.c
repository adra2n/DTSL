// da-shitou.c
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name(HIY"大石头"NOR,({ "da shitou", "shitou","stone" }) );
         set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 0);
                set("material", "stone");
                set("long", "这是一个大石头。\n");
                set("wield_msg", "$N拿出一个$n，试了试重量后握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(10);
        setup();
}
