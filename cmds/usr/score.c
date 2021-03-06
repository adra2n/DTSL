// score.c
// modify by yanyan. 2001.  hide the combat_exp.
#include <ansi.h>
#include <combat.h>
#include <org.h>
inherit F_CLEAN_UP;
string age_str(int time);
string center(string str,int long);
string left(string str,int long);
string nickname(string arg,int long);
string tribar_graphfw(int val, int eff, int max, string color);
string *gift_ranking = ({"下下之选","下等", "中下", "中等", "中上", "上等","上上之选"});
string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□";
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string combat_desc(int combat);
string get_shili(object ob);
string query_guanzhi(object ob);
int get_pot(object ob);
void create() { seteuid(ROOT_UID); }
string money_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;
        
        if (amount / 10000) {
                output = amount / 10000 + "两黄金";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + amount / 100 + "两白银";
                amount %= 100;
                
        }
        if (amount)
             return output + amount + "文铜板";
          
        return output;
}

string get_damage(object me,mapping action,string skill_name)
{
	
  return COMBAT_D->get_damage(me,0,me->query_temp("weapon"),action,0,skill_name);
	
}
string get_attack(object me,mapping action)
{
	
return COMBAT_D->get_attack(me,0,action,0);	
}

string get_parry(object me)
{
return COMBAT_D->get_parry(me);	
}

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type, parry_type;
	object weapon;
	int attack_points, dodge_points, parry_points;
	mapping action;
	string skill_name;
	
	seteuid(getuid(me));
	if(!arg) ob = me;
	else if (wizardp(me))
	{
	   	ob = present(arg, environment(me));
        	if (!ob) ob = find_player(arg);
	        if (!ob) ob = find_living(arg);
        	if (!ob) return notify_fail("你要察看谁的状态？\n");
	}
	else return notify_fail("只有巫师能察看别人的状态。\n");
	
	if(!ob->query("actionp")){
	  skill_name=ob->reset_action(ob->query_temp("weapon"));
	  action=ob->query("actions");
	}
	else{
	  action=ob->query("actionp");
	  skill_name=action["skill_name"];
	}
	
	my = ob->query_entire_dbase();
	line="┏━"HIG"【人物档案】"NOR"━━━━━━━━━━━┳━━━"HIG"【天赋】"NOR;
    line+="━━━━━━━━━━━━┓  \n";
	line+="┃ 头  衔 :";
	line+=nickname( RANK_D->query_rank(ob),27)+"┃";
	if( wizardp(me)) 
        line += sprintf(
	        "膂力:[%3s] 根骨:[%3s] 容貌:[%2s]""┃""\n",
        	display_attr(my["str"], ob->query_str()),
	        display_attr(my["con"], ob->query_con()),
		display_attr(my["per"], ob->query_per()),
	);
   else line += sprintf(
	        "膂力:[%3s]         根骨:[%3s]     "+"┃"+"\n",
        	display_attr(my["str"], ob->query_str()),
	        display_attr(my["con"], ob->query_con()),
		display_attr(my["per"], ob->query_per()),
	);
	if(!ob->query("title"))
	line+="┃ 称  谓 :"+nickname("「无」",27)+"┃";
	else	
        line+="┃ 称  谓 :"+nickname(ob->query("title"),27)+"┃";
	if( wizardp(me) ) 
        line += sprintf(
	        "悟性:[%3s] 身法:[%3s] 福缘:[%2s]""┃""\n",
       		display_attr(my["int"], ob->query_int()),
		display_attr(my["dex"], ob->query_dex()),
		display_attr(my["kar"], ob->query_kar()),
	);
        else
	line += sprintf(
	        "悟性:[%3s]         身法:[%3s]     "+"┃"+"\n",
       		display_attr(my["int"], ob->query_int()),
		display_attr(my["dex"], ob->query_dex()),
		
	);
	line +="┃ 姓  名 :"+nickname(ob->name()+"("+ob->query("id")+")",27)+"┗━━━━━━━━━━━━━━━━━━━┫""\n";
	line+="┃ 别  称 :";
	if(!ob->query("nickname")) line+=center("「无」",28);
	else
	line+=nickname("「"+ob->query("nickname")+"」",28);
	line+="〖伤 害〗"+center(""+get_damage(ob,action,skill_name),4)+
	      "〖敏 捷〗"+center(""+get_attack(ob,action),4)+
	      "〖招 架〗"+center(""+get_parry(ob),4)+"┃""\n";
	line+="┃ 性  别 : "+center(ob->query("gender"),27);
	line+=" 职  业 :";
	if(!ob->query("vocation")) line+=center("无职业",30)+"┃""\n";
	else
	line+=center(CHINESE_D->chinese(ob->query("vocation")),30)+"┃""\n";
	line+="┃ 年  龄 :"+center(chinese_number(ob->query("age"))+"岁",28);
	line+="婚姻状况:";
	if(!ob->query("couple")) line+=center("未婚",30)+"┃""\n";
	else
        line+=nickname(sprintf("你的爱人是%s",ob->query("couple/couple_name")),30)+"┃""\n";
	line+="┃ 生  辰 :"+center(CHINESE_D->chinese_date(((int)ob->query("birthday") -14*365*24*60) * 60),28);
	line+=" 势  力 :";
        if(!ob->query("shili/name")) {line+=center("你现在没加入势力",30)+"┃""\n";}
	else
	line+=center(get_shili(ob),30)+"┃""\n";
	line+="┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛""\n";
	line+="┏━"HIG"【人物状态】"NOR"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓""\n";  
	if(wizardp(me))
        line+="┃ 实战经验 : "+center(sprintf(HIM "%s" +NOR, CHINESE_D->string_number(ob->query("combat_exp"))),41);
	else
	line+="┃ 实战经验 : "+center(sprintf(HIM "%d" +NOR, ob->query("combat_exp")),41);
	line +=" 江湖声望 : "+center(sprintf(HIG "%d" NOR,ob->query("famous")),43)+"┃""\n";
	line+="┃ 你共杀人 :"+center(sprintf("%5d次,包括PK:%3d次",my["MKS"] + my["PKS"], my["PKS"]),26);
	line +=" 职业声望 :  "+center(sprintf(HIG "%d" NOR, (int)ob->query("vocation_score")),42)+"┃""\n";
	line+="┃ 你共死亡 :  "+center(sprintf(HIR "%d次"NOR ,ob->query("deadtimes")),40);
	line+=" 游戏时间 :"+center(age_str(ob->query("mud_age")),28)+"┃""\n";
	line+="┃ 杀    气 :  "+center(sprintf( RED "%d" NOR, ob->query("bellicosity") ),38);
	line +=" 存    款 :  "+center(sprintf(HIG "%s" NOR, money_str((int)ob->query("deposit"))),42)+"┃""\n";
	if( mapp(my["family"]))
	{
		if( my["family"]["master_name"] ){line+="┃你的师傅是:";
		line+=center(my["family"]["family_name"]+" "+my["family"]["master_name"],26);
	         }
                else
                line+="┃你的师傅是:"+RED+center("目前还没有"NOR,35);
	}
        else line+="┃你的师傅是:"+RED+center("目前还没有"NOR,35);
	line += " 潜    能 :  "+center(sprintf(HIY "%d(%d%%)" NOR,"/cmds/usr/hp.c"->get_pot(ob),ob->query("potential")*100/ob->query("max_pot")),42)+"┃""\n";
	if(!ob->query("last_damage_msg"))
	line+="┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"NOR"\n";
	else{
	line += "┃ 上次被害 :  "+left("     "+ob->query("last_damage_msg"),63)+"┃""\n";
	line+="┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"NOR"\n";}
	write(line);
	return 1;
}


string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%d/%d" NOR, value,gift );
	else if( value < gift ) return sprintf( CYN "%d/%d" NOR, value,gift );
	else return sprintf("%d/%d", value,gift);
}

string center(string str,int long)
{
	int space,len,i;
	string s,s2;
	s="";s2="";
	len=strlen(str);
	space=(long-len)/2;
	for(i=0;i<space;i++) s+=" ";
	for(i=0;i<long-len-space;i++) s2+=" ";
	return sprintf("%s%s%s",s,str,s2);
}

string no_color(string arg)
{
  arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
  return arg;
}

string left(string str,int long)
{
	int space,len,i;
	string s,oldstr;
	s="";oldstr=str;
	str=no_color(str);
	len=strlen(str);
	space=(long-len);
	for(i=0;i<space;i++) s+=" ";
	return sprintf("%s%s",oldstr,s);
}

string status_color(int current, int max)
{
    int percent;
    if( max ) percent = current * 100 / max;
    else percent = 100;
    if( percent > 100 ) return HIC;
    if( percent >= 90 ) return HIG;
    if( percent >= 60 ) return HIY;
    if( percent >= 30 ) return YEL;
    if( percent >= 10 ) return HIR;
    return RED;
}

string tribar_graphfw(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*35/max)*2-1] + ((eff > val) ? blank_string[(val*35/max)*2..(eff*35/max)*2-1] : "") +NOR;
}

string nickname(string arg,int long)
{
	int space,len,i;
	string s,s2,oldnick;
	s="";s2="";oldnick=arg;
	arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	len=strlen(arg);
	space=(long-len)/2;
	for(i=0;i<space;i++) s+=" ";
	for(i=0;i<long-len-space;i++) s2+=" ";
	return sprintf("%s%s%s",s,oldnick,s2);
}

string age_str(int time)
{
	int month, day, hour, minu;
	time /= 60;
	minu = time % 60;
	time /= 60;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	month = time / 30;
	return (month?month + " 月":"") + (day?day + "天":"") + hour + "小时"+ minu + "分";
}
  
  

string get_shili(object ob)
{
   return ORG_D->get_shili(ob);
}
string query_guanzhi(object ob)
{
    return ORG_D->query_guanzhi(ob);
}

int help(object me)
{
    write(@HELP
指令格式 : score
           score <对象名称>                   (巫师专用)

HELP
    );
    return 1;
}
