#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIY"沉沙剑"NOR, ({ "sword","jian" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500);
set("no_save",1);
		set("super",3);
		set("material", "iron");
		set("wield_msg", "$N抽出$n,挽了个剑花，握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	init_sword(125,180,180);
	setup();
}
