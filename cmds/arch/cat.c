 
// cat.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
   string file,dir2;

    seteuid(geteuid(me));
   if (!arg) return notify_fail("你想要显示那个档案?\n");
   file = resolve_path(me->query("cwd"), arg);
   if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");

    dir2= me->query("cwd");

   if( (dir2=="/cmds/wiz/" || dir2=="/cmds/arch/"
    || dir2=="/cmds/adm/" || dir2=="/adm/daemons/"
    || dir2=="/adm/etc/" || dir2=="/feature/" || dir2=="/clone/npc/"
    || dir2=="/data/login/" || dir2=="/data/npc/")
   &&  wiz_level(me) < 5 )
    return notify_fail("对不起，这个文件你读不出来。\n");

    cat(file);
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : cat <档案>

此指令可让你直接读取某档案之程式。
HELP
    );
    return 1;
}
