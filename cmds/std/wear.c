// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要穿戴什麽？\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;
        
        if(ob->query("wear_str")&&!ob->query("no_need_sx")){
         if(me->query_str()<ob->query("wear_str")-ob->query("reduce_sx"))
         return notify_fail("你的臂力太低了！\n");
        }
        
        if(ob->query("wear_force")
        &&!ob->query("no_need_force")
        &&me->query("force")<ob->query("wear_force")-ob->query("reduce_force")
          )
         return notify_fail("你的内力不够！\n");
        
        if(ob->query("wear_maxforce")
        &&!ob->query("no_need_maxforce")
        &&me->query("max_force")<ob->query("wear_maxforce")-ob->query("reduce_maxforce")
          )
         return notify_fail("以你内力的修为还不够装备此兵器！\n");
        
        if(ob->query("wear_dex")
        &&!ob->query("no_need_sx")
        &&me->query_dex()<ob->query("wear_dex")-ob->query("reduce_sx")
          )
         return notify_fail("你的身法太低了！\n");
       
        if(ob->query("wear_con")
        &&!ob->query("no_need_sx")
        &&me->query_con()<ob->query("wear_con")-ob->query("reduce_sx")
          )
         return notify_fail("你的根骨太低了！\n");
        
        if(ob->query("wear_int")
        &&!ob->query("no_need_sx")
        &&me->query_int()<ob->query("wear_int")-ob->query("reduce_sx")
          )
         return notify_fail("你的悟性太低了！\n");
        
	if( ob->query("female_only")
	&&	(string)me->query("gender") != "女性" )
		return notify_fail("这是女人的东西，你一个大男人也想用，羞也不羞？\n");
        if( ob->query("male_only")
	&&	(string)me->query("gender") != "男性" )
		return notify_fail("这是男人的东西，你一个女人家也想用，羞也不羞？\n");
	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N穿上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N戴上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "waist":
					str = YEL "$N将一" + ob->query("unit") + "$n" +  "绑在腰间。\n" NOR;
					break;
				default:
					str = YEL "$N装备$n。\n" NOR;
			}
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wear <装备名称>
 
这个指令让你装备某件防具。
 
HELP
    );
    return 1;
}
