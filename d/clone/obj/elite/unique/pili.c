#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIC"霹雳"NOR, ({ "pi li","spear" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
             
		set("value",300);
		//set("super",7);
		set("long","这是武林中至宝兵器，名为「大漠之霹雳」。\n");
                set("material", "iron");
                set("wield_msg",HIC"$N"+HIC+"拿出一把$n"+HIC+"，然後握在手中，只见四周闪了几道寒光。\n"NOR);
                set("unwield_msg", "$N放下手中的$n。\n");
                set("weapon_prop/damo",1);
        }
        
        init_spear(200,200,200);
        setup();
}

int wield()
{
    object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::wield()) return ::wield();
    
    if(owner->query("combat_exp")<1000000)
    return notify_fail("你目前无法装备这件物品。\n");
    
    owner->add("max_kee",500);
    
    if(owner->query_temp("apply/damo")==5){
    	message_vision(HIY"$N"+HIY+"的身上隐隐发出阵阵狂风的声音，四周卷起一阵的风沙。\n"NOR,owner);
    	owner->add_temp("apply/damage",50);
    	owner->add("max_kee",500);
    	owner->add_temp("apply/parry",60);}
    
    return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    
    if(owner->query_temp("apply/damo")==4){
    	owner->add_temp("apply/damage",-50);
    	owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add_temp("apply/parry",-60);}
    
    return 1;
}
