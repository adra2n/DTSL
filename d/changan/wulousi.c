

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","无漏寺");
  set ("long", @LONG
无漏寺规模不大，但精巧别致，大殿、藏经殿、讲经堂依次排列。
东西侧有菩提殿、厢房、跨院，院内花木扶疏，闲静雅致。
LONG);

  set("exits", ([ 
"south":__DIR__"xishibeikou2",
 "enter":"/d/quest/busiyin/woshi",
       ]));
  set("objects",([
          "d/job/jj/heshang3":1,
	  "/d/quest/busiyin/zhuchi":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_lingwu","lingwu");

}

int do_lingwu(string arg)
{
   
   object ob,target;
   string name;
   int improve,cost_pot,cost_bel;
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"with %s",name)!=1)
   return notify_fail("你需要一个僧人才能领悟不死印。\n");
   if(!objectp(target=present(name,environment(ob))))
   return notify_fail("这里没有这个人。\n");
   if(!userp(target))
   return notify_fail(target->name()+"帮不了你。\n");
   if(target->query("class")!="bonze")
   return notify_fail(target->name()+"不是僧人。\n");
   if(ob->query_skill("busi-yin",1)>target->query_skill("bikouchan",1))
   return notify_fail(target->name()+"闭口禅修为太低了，无法帮你领会不死印。\n");
   if(target->is_fighting())
   return notify_fail("对方正在战斗中。\n");
   if(target->is_busy())
   return notify_fail("对方正忙着呢！\n");
   if(ob->is_busy())
   return notify_fail("你正忙着呢！\n");
   
   if(ob->query_skill("busi-yin",1)<120
     ||ob->query_skill("huachan",1))
    return notify_fail("你什么也领悟不出来。\n");
  
   if(ob->query("bellicosity")<=0)
   return notify_fail("你的杀气太低了，无法领悟不死印！\n");
   if(ob->query("potential")<=0)
   return notify_fail("你的潜能不够！\n");
   
  improve=ob->query("potential")/2;
   if(ob->query("bellicosity")<improve){
     cost_pot=ob->query("bellicosity");
     cost_bel=ob->query("bellicosity");
   }
   else{
     cost_pot=ob->query("potential");
     cost_bel=improve;
   }
     improve=cost_pot*10;
     
     ob->improve_skill("busi-yin",improve);
     ob->add("potential",-cost_pot);
     ob->add("bellicosity",-cost_bel);
     
     message_vision("\n$N将自身的杀气逐渐化解，对不死印的领悟又有了新的提高。\n",ob);
     ob->start_busy(2);
     target->start_busy(1);
     return 1;
}
