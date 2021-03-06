// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要装备什麽武器？\n");
	
	if(me->is_busy())
	 return notify_fail("你正忙着呢！\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");
        if(!ob->is_wield_of(me,ob))
        return ob->is_wield_of(me,ob);
	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;
        
        if(ob->query("wield_str")&&!ob->query("no_need_sx")){
         if(me->query_str()<ob->query("wield_str")-ob->query("reduce_sx"))
         return notify_fail("你的臂力太低了！\n");
        }
        
        if(ob->query("wield_force")
        &&!ob->query("no_need_force")
        &&me->query("force")<ob->query("wield_force")-ob->query("reduce_force")
          )
         return notify_fail("你的内力不够！\n");
        
        if(ob->query("wield_maxforce")
        &&!ob->query("no_need_maxforce")
        &&me->query("max_force")<ob->query("wield_maxforce")-ob->query("reduce_maxforce")
          )
         return notify_fail("以你内力的修为还不够装备此兵器！\n");
        
        if(ob->query("wield_dex")
        &&!ob->query("no_need_sx")
        &&me->query_dex()<ob->query("wield_dex")-ob->query("reduce_sx")
          )
         return notify_fail("你的身法太低了！\n");
       
        if(ob->query("wield_con")
        &&!ob->query("no_need_sx")
        &&me->query_con()<ob->query("wield_con")-ob->query("reduce_sx")
          )
         return notify_fail("你的根骨太低了！\n");
        
        if(ob->query("wield_int")
        &&!ob->query("no_need_sx")
        &&me->query_int()<ob->query("wield_int")-ob->query("reduce_sx")
          )
         return notify_fail("你的悟性太低了！\n");
         
	if( ob->wield() ) {
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$N装备$n作武器。\n";
		message_vision(str, me, ob);
		
		if(me->is_fighting())
			me->start_busy(1+random(1));
		
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wield <装备名称>
 
这个指令让你装备某件物品作武器, 你必需要拥有这样物品.
 
HELP
    );
    return 1;
}
