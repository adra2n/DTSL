
inherit ROOM;
#include <ansi.h>
int do_yell();
void create()
{
	set("short",HIC"独尊堡"NOR);
	set("long", @LONG
这里是独尊堡的大门口。独尊堡是成都最的势力解晖的住处。平时
没有人敢在这里停留。独尊堡是成都最具势力的一个地方，所以平时也
有很多武林豪杰来投奔这里。你可以高声呼喝(yell)堡内的护卫来进入
独尊堡。
LONG);
	set("outdoors", "成都");

	set("exits", ([
        "northeast" : __DIR__"hubianlu",
	
	]));
	set("objects",([
		__DIR__"npc/dizi2":1,
		]));

	setup(); 
	
"/obj/board/duzun_b"->foo();
}

void init()
{
	add_action("do_yell","yell");
}

int do_yell()
{
    int beipan;object me;object where;
    
	me=this_player();
	where=environment(me);
	beipan=(int)me->query("beipan",1);
	if(beipan>=3)
		return notify_fail("独尊堡的守卫大声喊道:像你这种多个势力的叛徒,休想进我们独尊堡!\n");
    if(where->query("can_go")||query("exits/enter"))
		return notify_fail("吊桥已经放下来了!\n");
	call_out("do_bridge",5,where);
	message_vision("守卫冲着$N大声道:"+RANK_D->query_respect(me)+",等一下,我这就放下吊桥!\n",me);
	tell_object(where,"只听隆隆声音,吊桥正缓慢的放下来了.\n");
	return 1;
}

void do_bridge(object where)
{   
    object neibao;
	neibao=load_object(__DIR__"neibao");

	tell_object(where,"只听哐当一声,吊桥已经放下来了!\n");
	tell_object(neibao,"只听哐当一声,吊桥已经放下来了!\n");
	neibao->set("exits/out",__DIR__"duzunbao");
	where->set("can_go",1);
	where->set("exits/enter",__DIR__"neibao");
	remove_call_out("do_bridge");
	call_out("do_close",5,where,neibao);
	return;
}

void do_close(object where,object neibao)
{
	tell_object(where,"只听隆隆声音,吊桥被拉上去了.\n");
	tell_object(neibao,"只听隆隆声音,吊桥被拉上去了.\n");
	where->delete("exits/enter");
	where->delete("can_go");
	neibao->delete("exits/out");
	remove_call_out("do_close");
	return;
}
