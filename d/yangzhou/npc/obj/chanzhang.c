
#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(HIY"禅杖"NOR, ({ "staff" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把普通的禅杖。\n");
		set("value",500);
		set("material", "steel");
	}
	init_staff(60,170,170);

	set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n放到了地上。\n");

	setup();
}
