
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("铜萧", ({ "tong xiao","tong","xiao" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 400);
		set("material", "iron");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
	}
	init_sword(30,80,80);
	setup();
}
