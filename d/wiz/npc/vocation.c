// vocation.c
// Create by Gmm@Jianghu 1999-8-22

#include <ansi.h>
inherit NPC;
int set_vocation(string yn,string number);

void create()
{
	set_name("小方方", ({ "fang fang","fang" }));
	set("title", HIW"职业介绍人"NOR);
	set("gender", "男性");
	set("age", 18);
	set("long","小方方专门为江湖里无职业的玩家分配职业。\n");
	set("combat_exp", 100000000);
	set("attitude", "friendly");
	set("per",30);
	setup();
}

void init()
{	
	add_action("do_pick", "pick");
}

int accept_fight(object me)
{
	command("? " + this_player()->query("id"));
	command("say 这里很忙，想要打仗请到江湖中去，谢谢！");
	return 0;
}

int do_pick(string number)
{
	if (this_player()->query("vocation") && !wizardp(this_player())) return notify_fail("您已经有职业了！\n");
	if (!number) return notify_fail("请您输入所要的职业编号。\n");
	switch(number)
	{
		case "1":
			cat("/doc/vocation/swordman");
			break;
		case "2":
			cat("/doc/vocation/robber");
			break;
		case "3":
			cat("/doc/vocation/fighter");
			break;
		case "4":
			cat("/doc/vocation/official");
			break;
		case "5":
			cat("/doc/vocation/shaman");
			break;
		case "6":
			cat("/doc/vocation/theif");
			break;
		case "7":
			cat("/doc/vocation/beggar");
			break;
		case "8":
			cat("/doc/vocation/doctor");
			break;
		case "9":
			cat("/doc/vocation/weaponman");
			break;
		case "10":
			cat("/doc/vocation/businessman");
			break;
		case "11":
			cat("/doc/vocation/nosex");
			break;
		case "12":
			cat("/doc/vocation/bonze");
			break;
		default:
			return notify_fail("您只能在１～１２中选择！\n");
			break;
	}
	write(HIR"请注意：职业一旦确定，将影响您在江湖的一生，而且无法更改。\n\n"NOR);
	write(HIW"您确定要选择这种职业么？(y/n)"NOR);
	input_to ("set_vocation",number);
	return 1;
}

int set_vocation(string yn,string number)
{
	object me;
	me = this_player();
	if (yn!="y")
	{
		write(HIW"那么请您重新选择职业。\n"NOR);
		return 1;
	}
	else switch(number)
	{
		case "1":
			me->set("vocation","swordman");
			if (me->query("gender")=="男性") me->set("title","江湖游侠");
			else me->set("title","江湖女侠");
		break;
		case "2":
			me->set("vocation","robber");
			if (me->query("gender")=="男性") me->set("title","匪徒");
			else me->set("title","女匪");
		break;
		case "3":
			me->set("vocation","fighter");
			me->set("title","武斗家");
		break;
		case "4":
			me->set("vocation","official");
			if (me->query("gender")=="男性") me->set("title","小卒");
			else me->set("title","女兵");
		break;
		case "5":
			me->set("vocation","shaman");
			if (me->query("gender")=="男性") me->set("title","算命先生");
			else me->set("title","女术士");
		break;
		case "6":
			me->set("vocation","theif");
			if (me->query("gender")=="男性") me->set("title","小偷");
			else me->set("title","女贼");
		break;
		case "7":
			me->set("vocation","beggar");
			if (me->query("gender")=="男性") me->set("title","要饭的");
			else me->set("title","女乞丐");
		break;
		case "8":
			me->set("vocation","doctor");
			me->set("title","赤脚医生");
		break;
		case "9":
			me->set("vocation","weaponman");
			me->set("title","打铁匠");
		break;
		case "10":
			me->set("vocation","businessman");
			me->set("title","江湖小贩");
		break;
		case "11":
			me->set("vocation","nosex");
			if (me->query("gender")=="男性") me->set("title","小太监");
			else return notify_fail("女性不能当太监！\n");
		break;
		case "12":
			me->set("vocation","bonze");
			if (me->query("gender")=="男性") me->set("title","小和尚");
			else me->set("title","小尼姑");
		break;
	}
	write(HIW"您选择的职业是："HIY + to_chinese(me->query("vocation")) + HIW"，祝您玩的愉快！\n"NOR);
	return 1;
}