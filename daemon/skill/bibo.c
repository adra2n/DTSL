//碧波心法


inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
    if((int)me->query_skill("bibo",1)>400)
        return notify_fail("单纯的学习已经无法让你从本质上提高了，自己去领悟精髓吧。 \n");
    return 1;
}

string *query_execute()
{
   return ({"bibo"});
}
