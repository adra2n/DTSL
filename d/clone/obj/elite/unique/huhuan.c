
#include <armor.h>
#include <ansi.h>

inherit HANDS;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIY"呼唤"NOR, ({ "hu huan","hands"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "铁");
     set("unit", "双");
     set("value",400);
     set("long","这是武林的至宝之物，名为「马祖之呼唤」。\n");
     set("armor_prop/armor",40);
     set("armor_prop/mazu",1);
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
    
   owner->add("max_force",500);
  
  if(owner->query_temp("apply/mazu")==5){
    	message_vision(HIG"$N"+HIG+"的身上隐隐发出阵阵波涛的声音，四周卷起一阵的清风。\n"NOR,owner);
    	owner->add_temp("apply/armor",200);
    	owner->add("max_kee",1500);
    	owner->add_temp("apply/dodge",100);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    
    owner->add("max_force",-500);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
  
    if(owner->query_temp("apply/mazu")==4){
    	owner->add_temp("apply/armor",-200);
    	owner->add("max_kee",-1500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add_temp("apply/dodge",-100);}
    
    return 1;
}