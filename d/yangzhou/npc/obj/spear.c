#include <weapon.h>
inherit SPEAR;
void create()
{
        set_name("铁枪", ({ "spear" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "这是一杆铁枪，看起来好象有点锈迹斑斑。\n");
                set("value", 300);
                set("material", "生铁");
        }
        init_spear(20,90,90);
       set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");
        setup();
}
