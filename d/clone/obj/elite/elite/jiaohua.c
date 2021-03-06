
#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG"教化"NOR, ({ "jiao hua","staff" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
	        set("value", 400);
	        set("long","这是佛门的至宝兵器，名为「释迦牟尼之教化」。\n");
                set("material", "wood");
               // set("super",9);
                set("weapon_prop/staff",30);
                set("weapon_prop/dodge",80);
                set("weapon_prop/moni",1);
        }
        init_staff(300,300,300);

        set("wield_msg", HIY"$N"+HIY+"把$n"+HIY+"握在手中，四周闪了一道金黄色的光芒。\n"NOR);
        set("unwield_msg", "$N松开了手中的$n。\n");


        setup();
}

int wield()
{
    object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::wield()) return ::wield();
    
    if(owner->query("combat_exp")<3000000)
    return notify_fail("你目前无法装备这件物品。\n");
    
    owner->add("max_kee",1000);
    
    if(owner->query_temp("apply/moni")==5){
    	message_vision(HIY"$N"+HIY+"的身上隐隐发出圣光一般的颜色，久久也不消散。\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_kee",1000);
    	owner->add("max_force",200);}
    
    return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_kee",-1000);
    if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
    if(owner->query_temp("apply/moni")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_kee",-1000);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    	owner->add("max_force",-200);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}
