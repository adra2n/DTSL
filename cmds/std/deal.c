// deal.c

inherit F_CLEAN_UP;

#include <ansi.h>


string swap_msg(string arg)
{
   switch(arg){
   	
   case "悟性": return "int";
   case "根骨": return "con";
   case "膂力": return "str";
   case "臂力": return "str";
   case "身法": return "dex";
   default: return "error";
   }
}

int main(object me, string arg)
{
   
   int i,exp;
   string point_name,self_msg;
  
  if(!arg){  
  	exp = me->query("combat_exp");  	
  	if(!me->query("char_lev/lev")){
  		me->set("char_lev/lev",500000);
  		me->set("char_lev/times",0);
  	}
  	for(;;){
  		if(exp>=me->query("char_lev/lev")+500000*me->query("char_lev/times")){
  			me->set("char_lev/lev",me->query("char_lev/lev")+500000*me->query("char_lev/times"));  			
  			me->add("char_lev/times",1);
  			if(me->query("char_lev/times")<3)
  				me->add("char_lev/points",me->query("char_lev/times"));
  			else
  				me->add("char_lev/points",3);  				
  		}
  		else
  		break;
  	}
  	return notify_fail("你现在可以分配的属性点为"+HIY+"「"+
    	chinese_number(me->query("char_lev/points"))+"」"+NOR+"点。\n");
  }
  
  if(me->query("char_lev/points")<=0)
  	return notify_fail("你已经没有属性点可以分配了。\n");
  
  point_name=swap_msg(arg); 
  
  if(point_name=="error")
  return notify_fail("你只能选择“悟性”、“根骨”、“膂力”、“身法”中一种。\n");
  
  me->add("char_lev/points",-1);
  me->add(point_name,1);
  tell_object(me,"你的"+HIY+arg+NOR+"提高了！\n");
  return 1;
   
}


int help(object me)
{
	write(@HELP
指令格式：deal <属性项目>
 
分配你自己的属性。
如 deal 悟性
每间隔一段战斗经验，你就会获得属性，规律如下：
500K  战斗经验，能获得 1 点属性
1000K 战斗经验，能获得 2 点属性
2000K 战斗经验，能获得 3 点属性
3500K 战斗经验，能获得 3 点属性
5500K 战斗经验，能获得 3 点属性 
以此类推。
HELP
    );
    return 1;
}
