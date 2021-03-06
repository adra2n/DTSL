//form.
//dtsl
inherit F_CLEAN_UP;
#include <skill.h>

#define FORM "/daemon/skill/form/"

int main(object me, string arg)
{
    object target;
    object *mem;
    
    if(!arg)
    return notify_fail("你要使用什么阵法？\n");
    if(!me->query_temp("team_mark/form"))
    return notify_fail("你没有组成任何阵法。\n");
    if(me->query_temp("team_mark/form")!=arg)
    return notify_fail("你没有组成这个阵法，必须先进行组阵[team form]。\n");
    mem=me->query_team();
    if(sizeof(mem)<=1)
    return notify_fail("使用阵法至少有两个人。\n");
    if(!objectp(target=me->query_temp("last_damage_from")))
    return notify_fail("这里没有你要攻击的目标！\n");
    if(file_size(FORM+arg+".c")<=0)
    return notify_fail("阵法文件出了问题，请尽快报告巫师。\n");
    return call_other(FORM+arg+".c","form",me,target);
    	
}

int help()
{
  write("
可以使用这个命令来催动你所使用的阵法。
如 form yuehen。
前提是你必须用 team form 来组成了阵法，
而且你必须是队伍的首领，如果你对自己
的战斗目标进行了kill，则使用阵法的人
都会对你的战斗目标下kill，否则只是进
行fight 方式。
\n");
return 1;
}