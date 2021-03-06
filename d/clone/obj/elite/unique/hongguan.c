
#include <armor.h>
#include <ansi.h>

inherit HEAD;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIR"红冠"NOR, ({ "hong guan","head"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "铁");
     set("unit", "顶");
     set("value",400);
     set("long","这是武林中的至宝，名为「飞凤之红冠」。\n");
     set("armor_prop/armor", 60);
      set("armor_prop/feifeng", 1);
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
   owner->add("max_kee",200);
   
   if(owner->query_temp("apply/feifeng")==5){
    	message_vision(HIY"$N"+HIY+"的身上现出阵阵彩色的幻象，久久不见消失。\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_kee",1000);
    	owner->add("max_force",200);
    	owner->add_temp("apply/dagger",50);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_kee",-200);
    if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
    if(owner->query_temp("apply/feifeng")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_kee",-1000);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add("max_force",-200);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
      
      owner->add_temp("apply/dagger",-50);}
    
    return 1;
}