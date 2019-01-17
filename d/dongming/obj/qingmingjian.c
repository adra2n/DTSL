
#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
	set_name(HIG"清溟剑"NOR, ({ "qingming jian","sword","jian" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄东溟派世代相传的宝剑。\n");
		set("super",5);
		set("rumor",1);
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(60,150,150);
	setup();
}
