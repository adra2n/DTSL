
#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
   set_name(HIG"����"NOR, ({ "hujing"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",200);
     set("armor_prop/armor",8);
     //set("armor_prop/dodge",1);
   }
   setup();
}
