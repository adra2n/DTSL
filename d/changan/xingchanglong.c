

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兴昌隆");
  set ("long", @LONG
这是兴昌隆长安的总店，店铺规模宏大，端茶到水，理财算账，谈
生意的人把偌大的店堂都快挤满了，而且还不时的有伙计扛着盐包进进
出出。看这架式，难怪能成为关中海盐的主要供应商号之一，引来竞争
对手－广盛行的不满了。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshixijie1",
 //"west":"/d/clone/room/hanghui/room",
       ]));
  set("objects",([
         __DIR__"npc/shangren3":2,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

