#include <ansi.h>
inherit ROOM;

int do_zuan(string arg);
void create ()
{
  set ("short","珍宝斋");
  set ("long", @LONG
这是一间珍宝古玩店。店内琳琅满目的摆放着一个个价值连城的珍
宝古玩。看得人目不暇接，眼花缭乱，老板正在招待进来的顾客。
LONG);

  set("exits", ([ 
 "east":__DIR__"xishixijie1",
      ]));
  set("objects",([
         __DIR__"npc/zhubao-boss":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_zuan","zuan");
}
int do_zuan(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="地道")
  return notify_fail("什么？\n");
  message_vision("$N小心地撬开一个木板，钻了进去！\n",ob);
  ob->move(__DIR__"didao1");
  return 1;
}
