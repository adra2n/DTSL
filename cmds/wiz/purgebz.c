// purgebz.c
//by fengfei

#include <ansi.h>
#include <command.h>
#include <org.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
object ob;
string id;

if( !arg || sscanf(arg, "%s", id)!=1 ) return notify_fail("你要清理那个帮主？\n");
        ob = LOGIN_D->find_body(id);
        if (ob) return notify_fail("此人在线，请先kickout！\n");
  ORG_D->ShiZhong_BangZhu(me,id);
return 1;
}

int help(object me)
{
write(@HELP
指令格式 : purgebz <某人>

强制某个帮主退位，原始NPC帮主继任。
HELP);
    return 1;
}

