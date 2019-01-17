
#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
   set_name(WHT"白云飘"NOR, ({ "baiyun piao","piao","baiyun","whip" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "条");
     set("rumor",1);
     set("material", "金蝉丝");
     set("long", "这是一条飘带，是由金蝉丝制成，坚韧无比。\n");
     set("wield_msg", "$N轻轻地将$n握在手上，晃了几晃。\n");
     set("unequip_msg", "$N轻柔地将$n缠在了胳膊上。\n");
   }
   init_whip(98,200,200);
   setup();
}
