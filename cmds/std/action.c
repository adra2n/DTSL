//action.

#include <ansi.h>

string strleft(string msg,int blank)
{
while(strlen(msg)<blank)
	msg = msg+" ";

return msg;	
		
}

string str2left(string msg,int blank)
{
if(strlen(msg)%2!=0)
	msg = msg+" ";
while(strlen(msg)<blank)
	msg = msg+"━";

return msg;	
		
}

int main(object me,string arg)
{
        mapping *action;
        string *performs;
        int i;
        string msg;
	
	if(!arg) return notify_fail("请输入 action 武功名字 的格式.\n");
	if(file_size("/daemon/skill/"+arg+".c")<=0)
		return notify_fail("没有这种武功!\n");
	if(!me->query_skill(arg,1)&&!wizardp(me))
	return notify_fail("你没有学习这个武功！\n");
	msg = "";	
	if(action=SKILL_D(arg)->query_all_action(me))
	{
	  msg = "\n┏━"+str2left(HIG+arg+NOR+" 招数",50)+"━━━━━━━━━━━━━┓\n";
	  for(i=0;i<sizeof(action);i++){
	    msg = msg+strleft("┃第"+chinese_number(i+1)+"招 ",15)+
	    					strleft("「"+action[i]["name"]+"」",25)+
	    				  strleft("威力："+action[i]["apply_factor"],24)+"┃\n";
	    
	  }
	  msg = msg+"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	  
	}
	if(performs=SKILL_D(arg)->query_perform())
	{
	  msg = msg+"┏━"+str2left(HIG+arg+NOR+" 特殊外功",50)+"━━━━━━━━━━━━━┓\n";
	  for(i=0;i<sizeof(performs);i++)	
	   msg = msg+strleft("┃perform			"+
	   									HIY+performs[i]+NOR,60)+"┃\n";
	  msg = msg+"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	if(performs=SKILL_D(arg)->query_exert())
	{
	  msg = msg+"┏━"+str2left(HIG+arg+NOR+" 特殊内功",50)+"━━━━━━━━━━━━━┓\n";
	  for(i=0;i<sizeof(performs);i++)	
	   msg = msg+strleft("┃exert			"+
	   									HIY+performs[i]+NOR,66)+"┃\n";
	  msg = msg+"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	if(performs=SKILL_D(arg)->query_execute())
	{
	  msg = msg+"┏━"+str2left(HIG+arg+NOR+" 其他用法",50)+"━━━━━━━━━━━━━┓\n";
	  for(i=0;i<sizeof(performs);i++)	
	   msg = msg+strleft("┃execute			"+
	   									HIY+performs[i]+NOR,60)+"┃\n";
	  msg = msg+"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	}
	if(msg=="")
	  tell_object(me,"\n这个武功没有详细的说明文件。\n\n");
	else
	  tell_object(me,msg);
	return 1;
}