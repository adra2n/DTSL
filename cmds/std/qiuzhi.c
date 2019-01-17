
#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me,string arg)
{
    
	object master;
	if(!arg) return notify_fail("你要向谁求职？\n");
	if(!objectp(master=present(arg,environment(me))))
		return notify_fail("这里没有这个人!\n");
	if(me->query("vocation"))
	return notify_fail("如果想从事另一门职业，还是suicide -f 吧！\n");
	if(!master->query("vocation"))
		return notify_fail("这个人不能让你掌握一门职业技术！\n");
	if(me->query("vocation")==master->query("vocation"))
		return notify_fail("你已经从事这门职业了！\n");
	me->set("vocation",master->query("vocation"));
	me->set("vocation_score",0);
	me->set("vocation_exp",me->query("vocation_exp")/3);
	if(master->query("killer"))
		me->set("killer",1);
	message_vision("$N决定向$n学习，成为一名"+master->query("vocation")+"！\n",me,master);
    return 1;
}
