

#include <weapon.h>

inherit FORK;

void create()
{
	set_name("ì", ({ "fork" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 400);
		set("material", "steel");
	}
	init_fork(25,80,80);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�������\n");

// The setup() is required.

	setup();
}