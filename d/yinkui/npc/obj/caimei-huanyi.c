
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIG"彩"HIR"魅"HIY"幻"HIM"衣"NOR, ({ "caimei huanyi","cloth","yi","yulong_cloth"}) );
   set_weight(2000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","这是阴癸派的镇派之宝「彩魅幻衣」，据说有特殊作用。\n");
     set("unit", "件");
     set("value", 40);
     set("armor_prop/armor", 15);
     set("armor_prop/yulong_cloth", 1);
   }
   setup();
}
