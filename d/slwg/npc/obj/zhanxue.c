
#include <armor.h>
//#include <ansi.h>
inherit HEAD;

void create()
{
   set_name("战靴", ({ "zhan xue","xue"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "皮");
     set("long","这是一双战靴。\n");
     set("unit", "双");
     set("value",80);
     set("armor_prop/armor",5);
  }
   setup();
}
