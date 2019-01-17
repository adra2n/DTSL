
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(HIG"皮帽"NOR, ({ "cap"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一件从突厥出产的皮帽。\n");
     set("material", "羊皮");
     set("unit", "顶");
     set("value",80);
     set("armor_prop/armor",20);
   }
   setup();
}
