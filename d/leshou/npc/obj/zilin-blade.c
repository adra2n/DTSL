

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
   set_name(HIY"���۵�"NOR, ({ "zilin dao","dao","blade" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 1500);
     set("material", "iron");
     set("long", "��ѵ�����������������Ͽ����۶��֡�\n");
     set("wield_msg", "$N���һ�����λε�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
   }
   init_blade(25,80,80);
   setup();
}