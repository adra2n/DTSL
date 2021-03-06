
#include <ansi.h>
inherit ROOM;

int do_chou(string arg);
int do_pai(string arg);
void create ()
{
  set ("short","山峰");
  set ("long", @LONG
这里是大巴山的一个山峰。下面是深不见底的万丈深渊。一阵风吹
过，你顿时清醒了许多。旁边还有很多大石头，不知道能不能把它推下
山去，不过据说武林高手，用手掌就可以把它拍下山去。
LONG);

  set("exits", ([ 

   "southwest":__DIR__"shanya",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_chou","chou");
   add_action("do_pai","pai");
}

int do_chou(string arg)
{
   object me,weapon;
   me=this_player();
   if(!arg||arg!="石头")
   return notify_fail("你要抽什么？\n");
   if(!objectp(weapon=me->query_temp("weapon")))
   return notify_fail("你要拿什么来抽石头？\n");
   if(weapon->query("skill_type")!="whip")
   return notify_fail("你最好还拿鞭子来抽石头吧！\n");
   if(me->query("sen")<30)
   return notify_fail("你精神太差了！\n");
   if(me->query_skill("whip",1)>=101)
   return notify_fail("你的基本鞭法很高了，这块石头已经不起你一抽了！\n");
   if(me->is_busy())
   return notify_fail("你正忙着呢！\n");
   message_vision(YEL"$N运了口气，使劲朝石头抽了过去！\n"NOR,me);
   me->improve_skill("whip",me->query_int()/2+20+random(5));
   me->add("sen",-30);
   if(me->query_skill("whip",1)<50)
   message_vision("$N停了下来，喘了几口气。\n",me);
   else if(me->query_skill("whip",1)<100)
   message_vision("$N只听啪的一声，石头上留下了一条鞭痕。\n",me);
   else if(me->query_skill("whip",1)<150)
   message_vision("$N只听啪的一声，掉下了一小块碎石。\n",me);
   else if(me->query_skill("whip",1)<200)
   message_vision("只听啪的一声，石头上出现一条裂痕。\n",me);
   return 1;
}

int do_pai(string arg)
{
   object me,weapon;
   me=this_player();
   if(!arg||arg!="石头")
   return notify_fail("你要拍什么？\n");
   if(objectp(weapon=me->query_temp("weapon")))
   return notify_fail("你还带着武器呢，多费劲啊！\n");
   if(me->query("sen")<30)
   return notify_fail("你精神太差了！\n");
   if(me->query_skill("strike",1)>=101)
   return notify_fail("你的基本掌法很高了，还是给石头一条活路吧！\n");
   if(me->is_busy())
   return notify_fail("你正忙着呢！\n");
   message_vision(HIW"$N运气于掌，猛地朝石头拍了过去！\n"NOR,me);
   me->improve_skill("strike",me->query_int()/2+20+random(5));
   me->add("sen",-30);
   if(me->query_skill("strike",1)<50)
   message_vision("$N觉得手掌有些疼痛。\n",me);
   else if(me->query_skill("strike",1)<100)
   message_vision("$N收回手掌，石头晃了一晃。\n",me);
   else if(me->query_skill("strike",1)<150)
   message_vision("$N收回手掌，只见石头上已经印上了一个浅浅的掌印。\n",me);
   else if(me->query_skill("strike",1)<200)
   message_vision("$N手掌一拍到石头，只见碎石纷飞，落了一地。\n",me);
   return 1;
}
