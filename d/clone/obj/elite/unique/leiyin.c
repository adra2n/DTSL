
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIB"雷音"NOR, ({ "lei yin","blade" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
             
		set("value",300);
		//set("super",7);
		set("long","这是佛门中至宝兵器，名为「达摩之雷音」。\n");
                set("material", "iron");
                set("wield_msg",HIC"$N"+HIC+"拿出一把$n"+HIC+"，然後握在手中，只见一道寒光直冲云霄。\n"NOR);
                set("unwield_msg", "$N放下手中的$n。\n");
                set("weapon_prop/mantuoluo",1);
        }
        
        init_blade(200,200,200);
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
    
    owner->add("max_force",100);
    
    if(owner->query_temp("apply/mantuoluo")==5){
    	message_vision(HIY"$N"+HIY+"的身上隐隐发出一阵金色的光芒，照得四周非常明亮。\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_force",1000);}
    
    return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_force",-100);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
  
    if(owner->query_temp("apply/mantuoluo")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_force",-1000);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}
