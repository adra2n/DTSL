#include <ansi.h>
#include <command.h>
#include <login.h>
#include <job_money.h>

inherit NPC;

#define JIANYU "/d/death/jianyu.c"

object make_body(object ob);
int check_legal_id(string id);
int check_legal_name(string name);
string *banned_name=({});
void lose(object ob);
int do_zhuanshi();
string *death_msg = ({
        HIB "$N说道：喂！新来的，你叫什么名字？\n\n" NOR,
        HIB "$N叹道：最近兵荒马乱，来这里报到的人是越来越多了。\n\n" NOR,
        HIB "$N「哼」的一声，从袖中掏出一本像帐册的东西翻看着。\n\n" NOR,
        HIB "$N合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
        HIB "$N叹道：罢了罢了，你走吧。\n\n"
                "一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});

void create()
{
        string *first_name = ({ "秦广","初江","宋帝","仵官","阎罗","平等","泰山","都市","卞城","转轮" }); 

        set_name(first_name[random(sizeof(first_name))]+"王", ({ "ming wang", "ming", "wang" }) );
        set("title",  BLU"十殿冥王之"NOR );
        set("long", "你看不清他的面目，只觉得他身上不带任何喜怒哀乐。\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({ 
"一阵阴风吹来，你不禁浑身抖了抖。\n",
"忽然，一阵厉鬼的惨叫从远出传来，听得你毛骨悚然，不住颤抖。\n",
        }) );
       /* set("inquiry",([
        "转世投胎":"请使用 zhuanshi 命令\n",
        ]));
        */
        set("age", 3000);
        set("combat_exp", 200000);
        set("max_gin", 1000);
        set("max_kee", 1000);
        setup();
}

void init()
{
        object ob;
        //add_action("do_zhuanshi","zhuanshi");
        
        ob=previous_object();
        if(!ob) return;
        call_out("death_stage",5,ob);
}

void death_stage(object ob,int stage)
{
	int i;string msg;
        object *inv;
	if(!objectp(ob)){ return;}
	if(!ob->is_ghost()){
		message_vision("$N奇道：怎么来了个阳人？！定是黑白无常弄错了！\n",this_object());
		message_vision("突然黑白无常冒了出来，夹起$N一晃不见了！\n",ob);
		ob->reincarnate();
		ob->move(REVIVE_ROOM);
		tell_object(ob,HIW"你感觉一阵眩晕，已经回到了阳间！\n"NOR);
		message("vision","你忽然发现人影不知从什么地方冒了出来。\n", environment(ob), ob);
		
		return;}
	msg = death_msg[stage];
    msg = replace_string(msg, "$N", this_object()->name());
        tell_object(ob, msg);
 	if(++stage<sizeof(death_msg)){
		
		call_out("death_stage",5,ob,stage);
		return;}
	else ob->reincarnate();
	inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
              if(!inv[i]->query("save_box"))
                DROP_CMD->do_drop(ob, inv[i]);
	if(!ob->query("invalid_death")&&ob->query("age")>12)
        lose(ob);
	else ob->delete("invalid_death");
	if(ob->query("zuolao"))
	ob->move(JIANYU);
	else
	if(ob->query("combat_exp")>=20000)
	ob->move(REVIVE_ROOM);
	else
	ob->move("/d/slwg/zoulang1");
    message("vision","你忽然发现前面多了一个人影，不过那人影又好像已经在那里很久了，只是你一直没发觉。\n", environment(ob), ob);
	
	return;
}
void lose(object ob)
{
	int lost_combat;int exp;
	exp=ob->query("combat_exp");
	lost_combat=((ob->query("pker_lose")+2)/2)*exp/(100);
	ob->add("combat_exp",-lost_combat);	
	ob->add("deadtimes",1);
	ob->skill_death_penalty();
	ob->set("bellicosity",0);
	ob->delete("pker_lose");
	JOBSYS_D->clear_job_npc(ob);

}

int do_zhuanshi()
{
  object me;object ob;
  me=this_player();
  "/adm/daemons/logindd.c"->do_zhuanshi(me);
  return 1;
}
