// Room: /d/death/gateway.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"阎罗大殿"NOR);
	set("long", @LONG
你现在来到一座阴森的大殿前，新来的鬼魂们都必须在此接受阎王
的审判，为自己身前的所作所为赎罪。浓浓的雾环绕在你的四周，好像
永远都不会散去似的。殿上点有几盏鬼灯，隐约能照见十殿冥王的身影。
LONG);
	set("exits", ([ 
		"out" : "/d/death/gate",
	]));
	set("no_fight", 1);
set("no_quit",1);
	set("objects", ([
		__DIR__"npc/yanluo": 1,
           
	]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;
	if( dir == "out") 
	     return notify_fail(HIW"阎王朝你喝道：你没有回头路了！\n"NOR);
	else return 1;
}
