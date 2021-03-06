#include <power.h>
#include <org.h>

string orgmsg(object me)
{
	string msg;
	
	if(!me->query("shili"))
		return me->name()+"还没有加入任何帮会。\n";
	
		msg = "\n┏━"+str2left("你在 "+HIG+ORG_D->get_shili(me)+NOR+" 的资料",70)+"┓\n";
  	msg += "┃                                                        ┃\n";
  	if(me->query("shili/wide"))
  		msg +="┃"+HIC+"【所属的范围】"+strleft(HIW+me->query("shili/wide")+NOR+	
  			"        "+HIY+"【权力】"+HIR+get_power(me->query("shili/power"))+NOR,81)+"┃\n";
  	else
  		msg +="┃"+HIC+"【所属的范围】"+strleft(HIW+"无"+NOR+
  			"        "+HIY+"【权力】"+HIR+get_power(me->query("shili/power"))+NOR,81)+"┃\n";  
  	msg += "┃"+HIG+"【官职】"+strleft(HIM+ORG_D->query_guanzhi(me)+NOR,64)+"┃\n";
  	msg += "┃                                                        ┃\n";
  	msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	
	return msg;
	
}

int main(object me,string arg)
{
  string wide,name,powerd;
  object ob;int power;  
  
  if(!arg){
  	
  	tell_object(me,orgmsg(me));
  	return 1;
  }
  
  if(sscanf(arg,"%s %s %d",name,wide,power)!=3)
   return notify_fail("请使用power [某人] [某人权利范围] [等级]。\n"+
   			"如：power xx yz 3\n"+
   			"城市代号请使用 help power 查看。\n");
  if(power<=0||power>=8)
  return notify_fail("等级权限只能是0~7\n");
  if(!objectp(ob=present(name,environment(me))))
  return notify_fail("这里没有这个人。\n");
  
  if(me==ob)
  	return notify_fail("你挠挠头：哎呀，我糊涂了，怎么能给自己任命职务呢？\n");
  	
  if(!me->query("shili/leader"))
   return notify_fail("你感到万分沮丧：原来只有首领才可以这么做！\n");
 if(me->query("shili/name")!=ob->query("shili/name"))
 	return notify_fail("你仔细一看，原来"+ob->name()+"不是和你一个势力的人！\n");
 
 if(!userp(ob))
 	return notify_fail(ob->name()+"立刻受宠若惊：您太看得起我了，这我可不敢当！\n");	
 	
 wide=check_wide(wide);
 powerd=get_power(power);
  if(power==1)
  {
    ob->set("shili/leader",ob->query("shili/name"));
    me->delete("shili/leader");
    CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s将"+get_leader(ob)+HIM+"传位给%s了。",me->name(), ob->name()));
    ORG_D->set_leader_log(ob,me);
    me->save();
    ob->save();
    return 1;
  }
 if(wide=="无此")
 return notify_fail("请使用help power 来查询现有城市。\n");
 ob->set("shili/wide",wide);
 ob->set("shili/power",power);
 CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s授予%s主管"+HIW+wide+NOR+HIM",具有"+HIR+powerd+NOR+HIM+"的权力。",me->name(), ob->name()));
 me->save();
 ob->save();
 return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : power [某人] [某人权利范围] [等级]
如：power xx yz 3

目前可以任命的城市代号

changan:长安    luoyang:洛阳       xiangyang:襄阳      chengdu:成都
baling:巴陵     hefei:合肥         jiujiang:九江       yangzhou:扬州
hangzhou:杭州   xingyang:荥阳      liyang:黎阳         xucheng:许城
pengliang:彭梁  leshou:乐寿        yuyang:鱼阳         shanhaiguan:山海关
taiyuan:太原    mayi:马邑          dingxiang:定襄      saiwai:塞外
suiye:碎叶      tuyuhun:土谷浑     gaoli:高丽

级别：
	次级
	中上级
	中级
	中下级
	下级
	下下级
	最低级

HELP
    );
    return 1;
}