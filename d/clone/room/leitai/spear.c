
#include <weapon.h>

inherit SPEAR;

void create()
{
   set_name("长枪", ({ "spear" }) );
   set_weight(700);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("leitai_weapon",1);
     set("value", 500);
     set("material", "iron");
     set("long", "这是一柄长枪。\n");
     set("wield_msg", "$N拿出$n,扑棱一声，抖了个枪花。\n");
     set("unequip_msg", "$N收起$n站好。\n");
   }
   init_spear(30,300,300);
   setup();
}
