
inherit NPC;
#include <job_money.h>
#include <ansi.h>
string give_job();

mapping maps=([
"/d/clone/room/lingwu/jingzhai/wolong2":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong3":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong4":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong5":"长白山上",
  "/d/clone/room/lingwu/jingzhai/wolong6":"长白山上",
  "/d/changbaishan/shulin1":"长白山上",
  "/d/changbaishan/shulin2":"长白山上",
  "/d/changbaishan/shulin3":"长白山上",
  "/d/changbaishan/shulin4":"长白山上",
  "/d/hangzhou/dongan1":"杭州西郊","/d/hangzhou/dongan2":"杭州西郊",
  "/d/hangzhou/dongan3":"杭州西郊","/d/hangzhou/nanan1":"杭州西郊",
  "/d/hangzhou/nanan2":"杭州西郊","/d/hangzhou/xiaolu1":"杭州西郊",
  "/d/wuyishan/shanlu5":"武夷山上","/d/wuyishan/shulin1":"武夷山上",
  "/d/wuyishan/shulin2":"武夷山上","/d/wuyishan/shulin3":"武夷山上",
  "/d/wuyishan/shulin4":"武夷山上","/d/wuyishan/xiaoxi1":"武夷山上",
  "/d/changan/nanjie2":"长安城内","/d/changan/nanjie3":"长安城内",
  "/d/changan/nanjie4":"长安城内","/d/changan/nanjie5":"长安城内",
  "/d/changan/beijie0":"长安城内","/d/changan/beijie1":"长安城内",
  "/d/changan/beijie2":"长安城内","/d/changan/beijie3":"长安城内",
  "/d/huashan/putidong":"华山山内","/d/huashan/houshan":"华山山内",
  "/d/huashan/shanlu1":"华山山内","/d/huashan/shanlu2":"华山山内",
  "/d/huashan/shanlu3":"华山山内","/d/huashan/shanlu4":"华山山内",
 ]);
void create()
{
   set_name("商震",({ "shang zhen","shang","zhen" }) );
        set("gender", "男性" );
        set("age", 50);
   set("long", "他就是飞马牧场的大管家，从侧脸看去，\n"+
               "应是五十上下，鼻子平直，上唇的弧形曲\n"+
               "线和略微上翘的下唇颇具魅力，显示出他\n"+
               "有很强的个性和自信。\n");
       
   set("combat_exp",400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("tao",150);
   set_skill("strike",150);
   set_skill("cuff",150);
   set_skill("babu-ganchan",170);
   set("hand",({"liu","liang","tao"}));
   set("dodge",({"babu-ganchan"}));
   set("inquiry",([
	   "叛徒":(:give_job:),
	   ]));
   setup();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N冷冷地哼了一声.\n",ob2);break;
	case 1: message_vision("$N用冷眼打量着$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
string give_job()
{
   object me;object paper;
   string *map;
   string here;
   int i;
   
   me=this_player();
   if(me->query_temp("shang_kill_pantu"))
	   return "你还是先把叛徒杀死再说吧!\n";

   if(!me->query_temp("zhaoxiang_killer")){
      if(time()-me->query("busy_time")<100)
         return "你还是先歇歇吧！\n";}
   else{
      if(time()-me->query("busy_time")<20)
         return "你还是歇歇吧！\n";}
   if(me->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
   if(!valid_do_job(me,"feimajob"))
	return "你的武功很高了，做这样的小事真是大才小用了！\n";
   me->set_temp("dtsl_job","飞马牧场杀叛徒任务");
   me->delete_temp("zhaoxiang_killer");
   map=keys(maps);
   i=random(sizeof(map));
   here=map[i];
   me->set_temp("shang_kill_pantu/where",map[i]);
   paper=new(__DIR__"paper");
   paper->move(me);
   message_vision("$N给了$n一张"+paper->query("name")+"。\n",
                  this_object(),me);
   return "好吧，麻烦你去"+HIG+maps[here]+NOR+CYN+"把我们飞马牧场的叛徒杀死！\n"+
          "别忘了把他的首级拿回来给我。\n";

}



int accept_object(object me,object ob)
{
	int exp,sil,pot,i,j;
	object npc;
	j=10;
	npc=this_object();
	if(!me->query_temp("shang_kill_pantu"))
		return notify_fail("我可不随便要别人的东西！\n");
	if((string)ob->query("dead_id")!="tao shusheng")
		return notify_fail("你杀错人了吧？\n");
	if(ob->query("killed_by")!=me->query("id"))
	return notify_fail("哼，不是你杀的人，想来冒充吗？！\n");
	me->delete_temp("shang_kill_pantu");
	me->delete_temp("dtsl_job");
        exp=250+random(20);
        if(me->query("combat_exp")<1000000)
        pot=me->query("max_pot")/3;
        else pot=120+random(10);
	me->add("combat_exp",exp);
	pot=50+random(10);
	me->set("busy_time",time());
	me->add("potential",pot);
	if(me->query("potential")>me->query("max_pot")*3/2)
	me->set("potential",me->query("max_pot")*3/2);
    me->add("deposit",100);
    add_shili(me,exp/3,50);
	tell_object(me,HIW"\n你被奖励了"+exp+"点经验值 "+pot+"点潜能"+sil/100+"两白银\n"NOR);
	tell_object(me,HIW"谢谢了,为我们飞马牧场做了这么大的好事!\n"NOR);
	tell_object(me,"你的钱庄存款增加了！\n");
	remove_call_out("cancel_shang_kill_pantu");
	return 1;
}

