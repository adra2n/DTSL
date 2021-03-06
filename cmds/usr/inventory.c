// inventory.c
// Created by Gmm@Jianghu 1999-8-21
// Copyright by Jianghu Wizard Group(1998-1999)
//modify by yanyan@dt

#ifndef BASE_WEIGHT
#define BASE_WEIGHT 40000
#endif

#include <ansi.h>
inherit F_CLEAN_UP;
string inventory_name(object ob);
string inventory_type(object ob);
string inventory_value(object ob);
string inventory_weight(object ob);
string left(string str,int long);
string center(string str,int long);
string tribar_graphfw(int val, int eff, int max, string color);
string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□";
string over_string = "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";

int main(object me, string arg)
{
	int i;
	object *inv, ob;
	string line;
	string *inv_name,*inv_type,*inv_value,*inv_weight;
	seteuid(getuid(me));
	if(!arg) ob = me;
	else if(wizardp(me))
	{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("找不到指定玩家或NPC。\n");
	}
	else return notify_fail("只有巫师能察看别人的物品。\n");
	inv = all_inventory(ob);
	
	if(!ob->query_weight()) //update player weight.
          ob->set_weight(BASE_WEIGHT + (ob->query("str")-10) *2000);
	
	if(!sizeof(inv))
	{
             line="\n";
              line+="┏━【物品栏】━━━━━━━━━━━━┳━━━━━┳━━━━━┳━━━━━┓""\n";
		line+="┃";
		line+=center(HIY"名　　　　　称"NOR,52)+"┃"+center(HIG"类　型"NOR,26)+"┃"+center(HIC"价　值"NOR,26)+"┃"+center(HIM"重　量"NOR,26)+"┃""\n";
		line+="┣━━━━━━━━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┫""\n";
		line+="┃"HIW"【空载】"+ blank_string +HIW"┃"NOR"\n";
		line+="┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛""\n";
		write(line);
		return 1;
	}
	line ="┏━【物品栏】━━━━━━━━━━━━┳━━━━━┳━━━━━┳━━━━━┓""\n";
	line+="┃";
	line+=center(HIY"名　　　　　称"NOR,52)+"┃"+center(HIG"类　型"NOR,26)+"┃"+center(HIC"价　值"NOR,26)+"┃"+center(HIM"重　量"NOR,26)+"┃""\n";
	line+="┣━━━━━━━━━━━━━━━━━━╋━━━━━╋━━━━━╋━━━━━┫""\n";
	inv_name = map_array(inv,"inventory_name",this_object());
	inv_type = map_array(inv,"inventory_type",this_object());
	inv_value = map_array(inv,"inventory_value",this_object());
	inv_weight = map_array(inv,"inventory_weight",this_object());
	for(i=0;i<sizeof(inv);i++)
	{
		line+=NOR"┃"NOR+left(inv_name[i],36)+NOR"┃"NOR;
		line+=center(inv_type[i],17)+NOR"┃"NOR;
		line+=center(inv_value[i],17)+NOR"┃"NOR;
		line+=center(inv_weight[i],17)+NOR"┃"NOR"\n";
	}
	line+="┣━━━━━━━━━━━━━━━━━━┻━━━━━┻━━━━━┻━━━━━┫""\n";
	line+="┃";
	if (ob->over_encumbranced()) line+=HIR"【过载】"+ over_string;
	else line+="【负重】"+left(tribar_graphfw(ob->query_encumbrance(), ob->query_max_encumbrance(), ob->query_max_encumbrance(), HIW),64);
        line+="┃"NOR"\n";
	line+="┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛""\n";
	write(line);
	return 1;
}

string inventory_weight(object ob)
{
	int weight=ob->weight();

	if(weight<1) return HIC"没有重量";
	if(weight<5) return HIC"不足一钱";
	if(weight>50000) return HIR"重逾百斤";

	if(weight/5<10) return HIG"重约"+chinese_number(weight/5)+"钱";
	if(weight/50<10) return HIG"重约"+chinese_number(weight/50)+"两";
	if(weight/500<=10) return HIM"重约"+chinese_number(weight/500)+"斤";
	if(weight/500<=20) return HIM"约"+chinese_number(weight/500)+"斤";
	if(weight/500==30 || weight/500==40 || weight/500==50 || weight/500==60
	|| weight/500==70 || weight/500==80 || weight/500==90 || weight/500==100)
		return HIM"约"+chinese_number(weight/500)+"斤";
	return HIM+chinese_number(weight/5000)+"十几斤";
}

string inventory_value(object ob)
{
	int value=ob->query("value");

	if (ob->query("money_id")) return HIY"——";
	if (value<1) return HIC"一文不值";
	if (value>=10000000) return HIR"无价之宝";
	if (value>=1000000) return HIR"价值连城";
	if (value>=100000) return HIM"稀世珍品";
	if (value>=10000) return HIY+chinese_number(value/10000)+"两黄金";
	if (value>=100) return HIW+chinese_number(value/100)+"两白银";
	return HIC+chinese_number(value)+"文铜板";
}

string inventory_name(object ob)
{
	string short=ob->short();
	
	return (ob->query("equipped")) ? HIC+"□"+NOR+short : short;
}

string inventory_type(object ob)
{
	switch(ob->query("skill_type"))
	{
		case "sword":return HIR"武器(剑类)";
		break;
		case "hammer":return HIR"武器(锤类)";
		break;
		case "axe":return HIR"武器(斧类)";
		break;
		case "blade":return HIR"武器(刀类)";
		break;
		case "dagger":return HIR"武器(匕首)";
		break;
		case "fork":return HIR"武器(叉类)";
		break;
		case "staff":return HIR"武器(杖类)";
		break;
		case "whip":return HIR"武器(鞭类)";
		break;
		case "throwing":return HIR"武器(镖类)";
		break;
		case "ring":return HIR"武器(环类)";
		break;
		case "spear":return HIR"武器(矛类)";
		break;
                case "sweeper":return HIR"武器(拂尘)";
                break;
	}
	switch(ob->query("armor_type"))
	{
		case "cloth":return HIM"衣服";
		break;
		case "armor":return HIG"防具(甲胄)";
		break;
		case "head":return HIG"防具(头盔)";
		break;
		case "neck":return HIG"防具(护颈)";
		break;
		case "waist":return HIG"防具(护腰)";
		break;
		case "wrists":return HIG"防具(护腕)";
		break;
		case "shield":return HIG"防具(盾牌)";
		break;
		case "finger":return HIG"防具(板指)";
		break;
		case "hands":return HIG"防具(护掌)";
		break;
		case "boots":return HIG"防具(靴子)";
		break;
		case "bandage":return HIM"绷带";
		break;
	}
	if (ob->query("food_supply")) return HIC"食用品";
	else if (ob->query("liquid")) return HIC"饮用品";
	else if (ob->query("money_id")) return HIW"货币";
	else if (ob->query("cargo_id")) return HIW"货物";
	else if (ob->query("skill")) return HIW"可学习";
	else if (ob->is_corpse()) return HIY"尸体";
	else if (userp(ob)) return HIY"人类";
	else return HIY"未知";
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



string tribar_graphfw(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*32/max)*2-1] + ((eff > val) ? blank_string[(val*32/max)*2..(eff*32/max)*2-1] : "") +NOR;
}

int help (object me)
{
        write(@HELP
指令格式: inventory

列出你目前身上所携带的所有物品以及物品类型、价值和重量等等。
注：此指令可以用 i 代替。

HELP
);
        return 1;
}
