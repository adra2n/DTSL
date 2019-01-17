

#include <weapon.h>

inherit SPEAR;

void create()
{
	set_name("枪", ({ "spear" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("value", 400);
		set("material", "steel");
	}
	init_spear(25,80,80);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一杆$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插回腰后。\n");

// The setup() is required.

	setup();
}
