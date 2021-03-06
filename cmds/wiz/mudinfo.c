// /mudinfo.c
#include <mudlib.h>
#include <command.h>
#include <dbase.h>
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_CMD;
 
#define SCALE	(1.0/10.0)
#define STATUS	"正式开放中"

string memory_expression(int m);

void create() 
{ 
			seteuid(getuid(this_object())); 
}  

int main() {
   	float value;
  	
	write(YEL"★"+GRN+" Mud 的识别名称：  " + MUDLIB_NAME + ".\n");
	write(YEL"★"+GRN+" Mud 的网路名字：  " + INTERMUD_NAME + ".\n");
	write(YEL"★"+GRN+" 服务器作业平台：  " + "Linux(Redhat 5.2)\n");
	write(YEL"★"+GRN+" 界面系统的版本：  " + __VERSION__ + " driver \n");  
	write(YEL"★"+GRN+" 系统函数库版本：  " +"Datang ShuangLong Mudlib"+ " " + MUDLIB_VERSION_NUMBER + ".\n"); 
  write(YEL"★"+GRN+" CPU 的负担状况：  " + query_load_average() + ".\n");
  printf(YEL"★"+GRN+" 共使用的记忆体：  %s bytes.\n", memory_expression(memory_info()) ); 
	write(YEL"★"+GRN+" 线上使用者总数：  " + sizeof( users() ) + "个人在线上.最大人数300\n");
	write(YEL"★"+GRN+" 载入的物件总数：  " + sizeof( objects() ) + " 个物件.\n");
	write(YEL"★"+GRN+" 连续执行的时间：  " + CHINESE_D->chinese_period(uptime()) + "\n");
	write(YEL"★"+GRN+" Mud 现在的状态：  " + STATUS + ".\n"+NOR);
	return 1; 
}

string memory_expression(int m)
{
	float mem;

	mem = m;
	if( mem<1024 ) return m + "";
	if( mem<1024*1024 )
		return sprintf("%.2f K", (float)mem / 1024);
	return sprintf("%.3f M", (float)mem / (1024*1024));
}

int help() {

   write(@HELP
指令格式：mudinfo

这个指令将会显示有关这个 Mud 的一些系统资讯。 

HELP
	);
	 return 1; 
}
 
