//by yanyan.
inherit F_CLEAN_UP;

int main(object me, string arg)
{
   int pts;string *force;

   if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
     return notify_fail("指令格式：enforce <使出几成内力伤敌>|none\n");
   force=me->query("force_skill");
   if(sizeof(force)==0)
	   return notify_fail("你必须先学一种内功!\n");
   if( arg=="none")
     me->delete("jiali");
   else {
     if( pts < 0 || pts > 10)
        return notify_fail("你只能用 none 表示不运内力，或数字0~10表示使用几成的内力。\n");
     me->set("jiali", pts*me->query_skill("force",1)/10);
   }

   write("你决定在战斗中使用"+pts+"成内力伤人.\n");
   return 1;
}

int help (object me)
{
        write(@HELP
指令格式: enforce|jiali <使出几点内力伤敌>|none
 
这个指令让你指定每次击中敌人时，要发出几成内力伤敌。

enforce none 则表示你不使用内力。 
HELP
        );
        return 1;
}
