inherit ROOM;
#include <ansi.h>
string joke();
int do_search(string arg);
void create()
{
	set("short","悦来客栈");
	set("long", @LONG
这是一间客栈，可是看起来生意冷清，就连老板都不知道跑到哪里
去了。桌子上积了厚厚的一层灰。一阵冷风吹来，你不禁涌起阵阵寒意。
门的旁边还有一张小纸条paper。
LONG);
        set("exits",([
          "south":"/d/dongming/dalu7",
          ]));     
        set("item_desc",([
          "paper":(:joke:),
          ]));
        set("resource/water",1);
	setup();      
}
string joke()
{
  object ob;
  ob=this_player();
  return HIR+ob->name()+"欠本店一百两黄金，数年不还，确实无耻的可以。\n\n"NOR+
                        "                                    悦来客栈掌柜\n";
}
void init()
{
  add_action("do_search","sou");
}
int do_search(string arg)
{
  object ob;
  object killer;
  ob=this_player();
  if(!ob->query_temp("yrs_find/skin"))
  return 0;
  if(time()-query_temp("no_skin")<15*60)
  return notify_fail("你搜了半天，发现什么也搜不到！\n");
  set_temp("no_skin",time());
  killer=new(__DIR__"killer");
  killer->move(environment(ob));
  message_vision(HIR"$N挥舞着菜刀朝$n奔了过来：连老娘的黑店你也敢搜，真是找死！\n"NOR,killer,ob);
  killer->kill_ob(ob);
  return 1;
}
