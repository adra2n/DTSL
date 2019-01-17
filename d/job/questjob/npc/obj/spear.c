#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
set_name("铁枪", ({ "spear" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "杆");
     set("value", 500);
      set("material", "iron");
     set("long", "这是一杆铁枪。\n");
     set("wield_msg", "$N抽出$n握在手中，扑棱一声，抖了个枪花。\n"NOR);
     set("unequip_msg", "$N放下了手中的$n。\n");
   }
   init_spear(80,180,180);
   setup();
}

