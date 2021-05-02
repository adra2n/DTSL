
#include <weapon.h>

inherit HAMMER;

void create()
{
   set_name("铁锤", ({ "hammer" }) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
      set("material", "iron");
     set("long", "这是一柄由东溟派打造的铁锤。\n");
     set("wield_msg", "$N抽出一柄$n握在手中，晃了几晃。\n");
     set("unequip_msg", "$N将手中的$n扛到了肩上。\n");
   }
   init_hammer(70,200,200);
   setup();
}
