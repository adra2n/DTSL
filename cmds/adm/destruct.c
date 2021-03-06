// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *inv;
	int i;
	
	if(!arg)
	return notify_fail("use destruct xxx\n");
	inv=children(arg);
	for(i=0;i<sizeof(inv);i++)
	  destruct(inv[i]);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : dest [-r] <物件之名称或档名>

利用此一指令可将一个物件(object)或物件定义(class)从记忆体中清除，若清除物
件定义(即：指定档名的情况下)则下一次参考到这个物件的时候会重新将它编译。

具有 (admin) 身分的巫师可以用 -r 选项以 ROOT_UID 身分来清除被保护的物件如
使用者。

参考资料： destruct()
HELP
    );
    return 1;
}
