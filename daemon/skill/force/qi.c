
int exert(object me, object target)
{
		int n,q;
	if (target != me) 
		return notify_fail("你只能用内功恢复自己的气血。\n");
	if(me->is_busy()) return notify_fail("你正忙着呢!\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够。\n");

        if(me->query("kee")>=me->query("eff_kee"))
		return notify_fail("你现在气血充沛。\n");
	q=(int)me->query("eff_kee",1)-(int)me->query("kee",1);
	n=50*q/me->query_skill("force",1);
	if (n < 20)
		n = 20;
	if ((int)me->query("force") < n) {
		q = q * (int)me->query("force") / n;
		n = (int)me->query("force");
	}
	me->add("force", -n);
	me->receive_heal("kee", q);
	
        message_vision("$N深深吸了几口气，气色看起来好多了。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	return 1;
}
