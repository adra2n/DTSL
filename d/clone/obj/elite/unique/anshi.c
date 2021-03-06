
#include <armor.h>
#include <ansi.h>

inherit HANDS;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIG"暗示"NOR, ({ "an shi","hands"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "布");
     set("unit", "双");
     set("value",400);
     set("long","这是佛门中的至宝，名为「达摩之暗示」。\n");
     set("armor_prop/dodge",10);
     set("armor_prop/armor",80);
     set("armor_prop/mantuoluo",1);
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   if(owner->query("combat_exp")<1000000)
    return notify_fail("你目前无法装备这件物品。\n");
   
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
    
    if(owner->query_temp("apply/mantuoluo")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_force",-1000);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}