
#include <ansi.h>

inherit ROOM;
string do_joke();
int do_skill(string arg);
void create ()
{
  set ("short","磨刀堂");
  set ("long", @LONG
这里是宋家堡的磨刀堂。这里立着一块大石，名曰[磨刀石](shi)。
上面刻着的名字都是[天刀]宋缺要杀之人。
LONG);

  set("exits", ([ 

   "northwest":__DIR__"caodi",
   "south":"/d/job/sjbjob/zhifatang",
   "east":"/d/clone/room/orgsaferoom/songjia/xuandaotang",
       ]));
  set("item_desc",([
	  "shi":(:do_joke:),
    ]));

  set("valid_startroom", 1);
 
  setup();
 
}

void init()
{
	add_action("do_skill","pi");
	
}

int do_skill(string arg)
{
	object weapon,me;
	me=this_player();
	if(!arg||arg!="石头")
		return notify_fail("你要劈什么？\n");
    weapon=me->query_temp("weapon");
	if(!objectp(weapon))
		return notify_fail("没有武器拿什么劈？\n");
	if(weapon->query("skill_type")!="blade")
		return notify_fail("你还是用刀劈吧！\n");
	if(me->query("gin")<=25)
		return notify_fail("你太累了，还是歇歇吧！\n");
	if(weapon->query("flag")==1)
		return notify_fail("你拿着断掉的兵刃有什么用啊！\n");
	if(me->is_busy()) return notify_fail("你正忙着呢！\n");
	if(me->query_skill("blade",1)>=101)
		return notify_fail("你的基本刀法已经很高了，这里已经无法练习了！\n");
	message_vision("$N拿起"+weapon->name()+"朝着磨刀石劈去，溅起点点火星！\n",me);
	me->receive_damage("gin",25);
	//weapon->add("strong",-5+random(5));
	me->improve_skill("blade",me->query_int()/2+20+random(5));
	/*
	if(weapon->query("strong")<=0){
	message_vision("只听“当”的一声，$N手中的"+weapon->name()+"断成了两截！\n",me);
	weapon->set("strong",0);
	weapon->set("flag",1);
	weapon->set("org_name",weapon->name());
	weapon->set("name","断掉的"+weapon->name());
  }
 */
	return 1;
}

string do_joke()
{
	return "只见磨刀石上刻着：\n"HIR"    "+this_player()->name()+"\n"NOR;
}
