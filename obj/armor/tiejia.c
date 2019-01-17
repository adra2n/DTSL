
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIG"铁甲"NOR, ({ "armor"}) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一件铁甲，看起来很笨重。\n");
     set("material", "生铁");
     set("unit", "件");
     set("value", 600);
     set("armor_prop/armor",80);
     set("armor_prop/dodge",-2);
   }
   setup();
}
