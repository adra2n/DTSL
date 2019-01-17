
inherit ITEM;

#include <ansi.h>

#define MAX_LOAD 5

int query_autoload()
{
	
	return 1;
}


int do_put(string arg);
int do_get(string arg);

void create()
{
   set_name("行囊", ({ "xing nang","nang"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "布");
     set("unit", "个");
     set("value",400);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("no_steal",1);
     set("no_sell",1);
     set("save_box",1);
     set("long","这是用来盛放东西的行囊，你可以放进去(fang)东西和取出(quchu)东西。\n");
    
   }
   setup();
}


void init()
{
   
   add_action("do_put","fang");
   add_action("do_get","quchu");
     
   
}


string long()
{
    object ob;
    mapping *things;
    string msg;
    int i;
    
    ob=this_player();
    things=ob->query("load_box_things");
    
    if(sizeof(things)<=0)
     return query("long")+"\n目前行囊里没有什么东西。\n";
    msg="";
   for(i=0;i<sizeof(things);i++)
     msg +=HIY"「"+(i+1)+"」"+NOR+" "+things[i]["name"]+"\n";
   
   return query("long")+"\n目前行囊中有：\n"+msg;
}

int do_put(string arg)
{
   object ob,target;
   mapping new_ob;
   mapping *old_ob;
   
   mixed *klist;
   mapping list;
   int i;
   
   ob=this_player();
   
   if(!arg)
    return notify_fail("你要把什么东西放到行囊里？\n");
   if(!objectp(target=present(arg,ob)))
   return notify_fail("你身上没有这个东西。\n");
   
   if(target->query("rumor")||target->query("no_save")||
      target->query("super"))
   return notify_fail("这样的东西不能放到里面。\n");
   
   if(target==this_object())
    return notify_fail("你省省吧！\n");
   
   if(target->query("save_box"))
	return notify_fail("这样的东西不能放到里面。\n");				   	
   
   if(target->is_corpse())
     return notify_fail("这么小的行囊可放不进去尸体。\n");
     
   if(target->is_character())
     return notify_fail("这么小的行囊可放不进去活人。\n");
   
   if(target->query("food_supply"))
     return notify_fail("食物还是放到外面吧。\n");
   
   if(target->query("skill"))
     return notify_fail("书籍是用来读的，还是不要放到里面去了。\n");
   if(target->query("money_id"))
     return notify_fail("钱放在外面就可以了，还怕别人偷吗。\n");
   
   if(sizeof(ob->query("load_box_things"))>=MAX_LOAD)
   return notify_fail("行囊已经满了，放不进去东西了！\n");
   if(target->query("equipped"))
     target->unequip();
   
   list=(mapping)target->query_entire_dbase();
   klist=keys(list);
   
   new_ob=allocate_mapping(sizeof(klist)+3);
   for(i=0;i<sizeof(klist);i++)
    new_ob[klist[i]]=list[klist[i]];
   
   new_ob["name"]=target->name();
   new_ob["place"]=base_name(target);
   new_ob["id"]=target->get_this_id();
   
   old_ob=ob->query("load_box_things");
   if(old_ob) old_ob=old_ob+({new_ob});
    else old_ob=({new_ob});
   ob->set("load_box_things",old_ob);
   ob->save();
   tell_object(ob,"你把"+target->name()+"放到了行囊里。\n");
   
   destruct(target);
   return 1;
}

int do_get(string arg)
{
   object ob;
   int num;
   mapping *things;
   mapping base;
   string *base_item;
   object new_ob;
   int i;
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"%d",num)!=1) 
   return notify_fail("你要取出第几件物品？\n");
   if(num<=0) return notify_fail("自己和自己捣乱？？\n");
   things=ob->query("load_box_things");
   if(sizeof(things)<num)
   return notify_fail("你没有那件物品。\n");
   
   new_ob=new(things[num-1]["place"]);
   if(!new_ob)
   return notify_fail("这件物品消失了，请尽快和巫师说明！\n");
   base_item=keys(things[num-1]);
   for(i=0;i<sizeof(base_item);i++)
     if(base_item[i]!="place")
     new_ob->set(base_item[i],things[num-1][base_item[i]]);
   new_ob->set_name(things[num-1]["name"],things[num-1]["id"]);
   if(new_ob->move(ob))
    tell_object(ob,"你从行囊中取出了一"+new_ob->query("unit")+new_ob->name()+"。\n");
   else return notify_fail("你不能从行囊中拿出那个物品，请报告巫师。\n");
   if(num==1)
     things=things[num..<1];
   else things=things[0..num-2]+things[num..<1];
   ob->set("load_box_things",things);
   ob->save();
   return 1;
}