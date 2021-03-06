//暗杀。for killer vocation.
#include <ansi.h>
#include <org.h>

#define TIME_TICK1 ((time())*60)
#define MAX_LIGHT_TIME 1200
mapping default_where = ([
        "n":    "north",
        "s":    "south",
        "e":    "east",
        "w":    "west",
        "nu":   "northup",
        "su":   "southup",
        "eu":   "eastup",
        "wu":   "westup",
        "nd":   "northdown",
        "sd":   "southdown",
        "ed":   "eastdown",
        "wd":   "westdown",
        "ne":   "northeast",
        "nw":   "northwest",
        "se":   "southeast",
        "sw":   "southwest",
        "u":    "up",
        "d":    "down",
]);

mapping default_dirs = ([
        "north":                "北面",
        "south":                "南面",
        "east":                 "东面",
        "west":                 "西面",
        "northup":              "北边",
        "southup":              "南边",
        "eastup":               "东边",
        "westup":               "西边",
        "northdown":            "北边",
        "southdown":            "南边",
        "eastdown":             "东边",
        "westdown":             "西边",
        "northeast":            "东北",
        "northwest":            "西北",
        "southeast":            "东南",
        "southwest":            "西南",
        "up":                   "上面",
        "down":                 "下面",
        "enter":                "里面",
        "out":                  "外面",
]);

int main(object me, string arg)
{
	string who, where, dir, undir, where_temp, *name;
	object env, old_env;
	mapping exits;
	object target;
	string gen;

	if( !arg || sscanf(arg, "%s at %s", who, where_temp)!=2 ) 
		return notify_fail("指令格式：ansha <人物> at <方向>\n");

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");
	if(me->query("pker"))
	return notify_fail("通缉犯还是老实地呆会吧！\n");
	
	if(objectp(me->query_temp("city_war_guard")))
        return notify_fail("你正带兵打仗呢！\n");
	
	old_env = env;

	if( !undefinedp(default_where[where_temp]) )
		where = default_where[where_temp];
	else
		where = where_temp;

	if( !mapp(exits = env->query("exits")) || undefinedp(exits[where]) )
		return notify_fail("没有这个方向。\n");

	if( !objectp(env = find_object(exits[where])) ) {
		call_other(exits[where], "???");
		env = find_object(exits[where]);
	}

	if (env == old_env) return notify_fail("在一个地方无法暗杀。\n");
    if( !old_env->valid_leave(me, where) ) {
        write(query_notify_fail());
        return 1;
        }
        if(me->query("vocation")!="杀手")
        return notify_fail("只有杀手可以使用这个命令！\n");
	if( env->query("no_fight") )
		return notify_fail("那里禁止战斗。\n");

	if( !objectp(target = present(who, env)) )
		return notify_fail("这个方向没有此人。\n");
        
        if(objectp(target->query_temp("city_war_guard")))
        return notify_fail("对方正带兵打仗呢！\n");
	
	if ( userp(me) && userp(target) && target->query("age") < 13 )
		return notify_fail("有点职业道德吧！小孩子也不放过吗?\n");
	if ( userp(me) && userp(target) && target->query("combat_exp") < 15000 )
		return notify_fail("这样经验的玩家也值得你去暗杀吗？\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是生物。\n");
	
	if( target->is_city_war_guard() )
		return notify_fail("你不能攻击对方！\n");
	
	if(stringp(target->query("target_id"))&&target->query("target_id")!=me->query("id"))
	return notify_fail(target->name()+"根本不理会你的战斗请求。\n");
	
	if(arrayp(target->query("target_id"))&&
	   member_array(me->query("id"),target->query("target_id"))==-1)
	   return notify_fail(target->name()+"根本不理会你的战斗请求。\n");
	
	if(userp(me)&&userp(target)&&
	  me->query("shili/name")&&target->query("shili/name")){
	  if(me->query("shili/name")==target->query("shili/name"))
	   return notify_fail("同一帮会弟子不要互杀了！\n");
	  if(ORG_D->if_friend_org(me,target))
	   return notify_fail("结盟帮会弟子间不能互杀！\n");
	}

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能暗算。\n");

	if( me->is_fighting() )
		return notify_fail("你正忙着战斗呢，还有心思暗杀别人？\n");

	if( !living(target) )
		return notify_fail(target->name() + "都已经这样了，你还用得着暗算吗？\n"); 

	if( (int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力，暗算不了别人。\n");
        if(me->query("bellicosity")<200)
        return notify_fail("你的杀气不够，无法进行暗杀！\n");
        if (!((	(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅时") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0) ) 
		&&me->query_temp("light")<time()-MAX_LIGHT_TIME))
	return notify_fail("你还是等天完全黑下来再行动吧！\n");
	if(!environment(me)->query("outdoors"))
	return notify_fail("在室内还是不要有这种举动的好。\n");
	dir = env->query("short");
	if( !undefinedp(default_dirs[where]) )
		dir = default_dirs[where] + dir;

	undir = old_env->query("short");

	if(me->query("gender") == "女性")
		gen = "倩影";
	else
		gen = "人影";

	write(CYN "你摒息静气，纵身而起，向" + dir + "的" + target->name() + "扑去！\n" NOR);
	tell_room(old_env, CYN "\n一条" + gen + "忽然向" + dir + "扑去！\n" NOR, ({me}));
	message_vision(CYN "\n一条" + gen + "忽然从" + undir + "向$N扑来！\n\n" NOR, target);

	name = me->query_temp("apply/name");
	me->set_temp("apply/name", ({gen}));

	me->move(environment(target));
        me->kill_ob(target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		message_vision(CYN"$N一时没有防范，被$n攻了个措手不及！\n"NOR, target, me);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,2);
	} else {
		message_vision(CYN"$N经验丰富，不及细看，立刻向$n反击！\n"NOR, target, me);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"),0, 1);
	}

	if( random(me->query("combat_exp")) < (int)target->query("combat_exp")/3 ) {
		me->set_temp("apply/name", name);

		tell_object(target, CYN"你一定神，原来是" + me->name() + "在暗杀你！\n"NOR);
		write(CYN "不好，你被" + target->name() + "发觉了！\n"NOR);
		message_vision(CYN"$N喝道：$n！你敢暗杀我，我跟你没完！\n"NOR, target, me);
		if (!userp(target)) target->kill_ob(me);
		else target->fight_ob(me);
		me->start_busy(1);
	} else {
		tell_room(env, CYN "\n" + gen + "转瞬不见！\n\n"NOR, ({me}));
		write(CYN"\n你立刻退回原处！\n\n"NOR);

		me->move(old_env);
		tell_room(old_env, CYN "\n转眼间" + gen + "又回到原处！\n\n"NOR, ({me}));

		me->set_temp("apply/name", name);

		tell_object(target, CYN"你一定神，可是什么都没看见。\n"NOR);		
	}

	me->start_busy(1);
	me->receive_damage("sen", 50);

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : ansha <人物> at <方向>

这个指令让你暗杀位于<方向>的<人物>。
为杀手专用指令。
条件：杀气>=200.

HELP
);
	return 1;
}
