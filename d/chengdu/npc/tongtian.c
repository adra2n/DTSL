
inherit NPC;

#include <ansi.h>

void create()
{
       set_name("夏妙莹", ({ "xia miaoying","xia"}) );
       set("gender", "女性" );
	   set("nickname","通天姥姥");
       set("age", 42);
       set("long",
               "这就是人称[通天姥姥]的夏妙莹，她最擅\n长招魂通灵等异术。\n");
       set("combat_exp", 400000);
       set("attitude", "peaceful");
	   set("str",27);
	   set("per",23);
	   set("max_gin",500);
	   set("max_kee",500);
	   set("max_sen",800);
	   set("max_force",800);
	   set("force",800);
	   set_skill("force",120);
	   set_skill("unarmed",120);
	   set_skill("parry",120);
	   set_skill("dodge",120);
       set_skill("whip",120);
	   set("inquiry",([
					"转换职业":"我能转换的职业为\n"+
					         "兵器类铁匠、护具类铁匠、毒药系铁匠、明药师、暗药师、杀手。\n"+
					         "你可以使用命令 zhuanzhi 来转换职业。\n",
	   ]));   
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 

}


void init()
{
	add_action("do_change_vocation","zhuanzhi");
	
}

int do_change_vocation(string arg)
{
	object ob;
	
	ob=this_player();
	
	if(is_busy()){
		command("say 等一下，正忙着呢！");
		return 1;
	}
	
	if(!ob->query("vocation")){
		command("say 你没选择职业，现在不用转换职业。");
		return 1;
	}
	if(!arg)
		return notify_fail("你要转换为什么职业？\n");
	if(ob->query("change_vocation")){
		command("say 你已经转换一次职业了，不能转换了！");
		return 1;
	}
	
	switch(arg){
		case "兵器类铁匠":  
			if(ob->query("vocation_fenzhi")=="weapon")
				return notify_fail("你本来就是兵器类铁匠。\n");
			if(ob->query("vocation")=="药师"){
				if(ob->query_skill("poison",1))
					ob->delete_skill("poison");
				else
					ob->delete_skill("bencao-shuli");
			}
			if(ob->query("vocation")=="杀手"){
				ob->delete_skill("yingzi-jianfa");
			}
			ob->set("vocation","铁匠");
			ob->set("vocation_fenzhi","weapon");
			break;
		
		case "护具类铁匠":  
			if(ob->query("vocation_fenzhi")=="armor")
				return notify_fail("你本来就是护具类铁匠。\n");
			if(ob->query("vocation")=="药师"){
				if(ob->query_skill("poison",1))
					ob->delete_skill("poison");
				else
					ob->delete_skill("bencao-shuli");
			}
			if(ob->query("vocation")=="杀手"){
				ob->delete_skill("yingzi-jianfa");
			}
			ob->set("vocation","铁匠");
			ob->set("vocation_fenzhi","armor");
			break;	
		
		case "毒药系铁匠":  
			if(ob->query("vocation_fenzhi")=="poison")
				return notify_fail("你本来就是毒药系铁匠。\n");
			if(ob->query("vocation")=="药师"){
				if(ob->query_skill("poison",1))
					ob->delete_skill("poison");
				else
					ob->delete_skill("bencao-shuli");
			}
			if(ob->query("vocation")=="杀手"){
				ob->delete_skill("yingzi-jianfa");
			}
			ob->set("vocation","铁匠");
			ob->set("vocation_fenzhi","poison");
			break;	
		
		case "明药师":
			if(ob->query("vocation")=="药师")
				if(ob->query_skill("bencao-shuli",1))
					return notify_fail("你本来就是明药师。\n");
			
			if(ob->query("vocation")=="药师")
				ob->delete_skill("poison");
			if(ob->query("vocation")=="杀手"){
				ob->delete_skill("yingzi-jianfa");
			}
			if(ob->query("vocation")=="铁匠"){
				ob->delete_skill("duanzao-jishu");
				ob->delete("vocation_fenzhi");
			}
			ob->set("vocation","药师");
			break;
		
		case "暗药师":
			if(ob->query("vocation")=="药师")
				if(ob->query_skill("poison",1))
					return notify_fail("你本来就是暗药师。\n");
			
			if(ob->query("vocation")=="药师")
				ob->delete_skill("bencao-shuli");
			if(ob->query("vocation")=="杀手"){
				ob->delete_skill("yingzi-jianfa");
			}
			if(ob->query("vocation")=="铁匠"){
				ob->delete_skill("duanzao-jishu");
				ob->delete("vocation_fenzhi");
			}
			ob->set("vocation","药师");
			break;
		
		case "杀手":
			if(ob->query("vocation")=="杀手")
				return notify_fail("你本来就是杀手。\n");
			if(ob->query("vocation")=="铁匠"){
				ob->delete_skill("duanzao-jishu");
				ob->delete("vocation_fenzhi");
			}
			if(ob->query("vocation")=="药师"){
				if(ob->query_skill("poison",1))
					ob->delete_skill("poison");
				else
					ob->delete_skill("bencao-shuli");
			}
			ob->set("vocation","杀手");
		  break;
		default:
			return notify_fail("你只能转换的职业为"+
				"兵器类铁匠、护具类铁匠、毒药系铁匠、明药师、暗药师、杀手。\n");
	}
	
	ob->set("change_vocation",time());
	ob->add("combat_exp",-ob->query("combat_exp")/100);
	
	command("say 天灵灵，地灵灵，各路神仙听我显灵... ...");
	command("say 职业转换成功！");
	
	start_busy(2);
	
	return 1;
	
}