//撒手法


inherit SKILL;

string query_type()
{
   return "literate";
}

int valid_learn(object me)
{
    if((int)me->query("PKS",1)>=5)
    return notify_fail("你杀的人太多了，无法学习撒手法。\n");
    
    return 1;
}

string *query_execute()
{
   return ({"jingshou"});
}


