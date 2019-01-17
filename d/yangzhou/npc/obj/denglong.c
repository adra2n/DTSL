#define TIME_TICK1 ((time()-900000000)*60)
inherit ITEM;
#include <ansi.h>
int do_fire();
int do_see();
void create()
{
  set_name("红灯笼", ({ "deng long", "deng","long" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "这是一个小红灯笼，你可以点燃(fire)它,然后就可以看(see)周围了。\n");
set("value",50);
	set("no_drop",1);
    set("unit", "只");
  }
  setup();
}

void init()
{
	add_action("do_fire","fire");
	add_action("do_see","see");
}

int do_fire()
{
	object ob;
	ob=this_player();
/*	if ((	(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") <= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") <= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅时") <= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") <= 0) ))
		return notify_fail("大白天的，点什么蜡烛啊？\n");*/
if(!present("deng long",ob))
return notify_fail("什么？\n");
	if(this_object()->query("lose"))
		return notify_fail("灯笼中已经没有蜡烛了。\n");
	if(this_object()->query("fired"))
		return notify_fail("灯笼已经点着了。\n");
	message_vision("$N小心地点燃了一只小红灯笼。\n",ob);
	this_object()->set("name",HIR"红灯笼"NOR);
	ob->set_temp("apply/short",({HIR""+ob->name()+"提着个小红灯笼站在那里。"NOR}));
	this_object()->set("fired",1);
call_out("lose",6,ob,this_object(),20);
	return 1;
}

void lose(object pal,object ob,int times)
{
	if(!ob){remove_call_out("lose");return;}
	tell_object(environment(ob),"红灯笼中的蜡烛慢慢地变小了。\n");
	if(--times<=0)
	{
      tell_object(environment(ob),"红灯笼中的蜡烛终于燃尽了。\n");
	  ob->set("name",HIB"灯笼"NOR);
	  ob->set("lose",1);
	  pal->delete_temp("apply/short");
	  remove_call_out("lose");
	  destruct(this_object());
	  return;
	}
	remove_call_out("lose");
	call_out("lose",6,pal,ob,times);
	return;
}

int do_see()
{
	object me,*ob,here;int i;mapping exits;string *d;
	me=this_player();
if(!present("deng long",me))
return notify_fail("什么?\n");
	here=environment(me);
	ob=all_inventory(here);
	exits=here->query("exits");
	if(this_object()->query("lose"))
		return notify_fail("你沮丧地发现灯笼已经没蜡烛了。\n");
	if(!this_object()->query("fired"))
		return notify_fail("你要先把灯笼点着。\n");
	tell_object(me,"你拿灯笼朝四处照去，发现你的周围有\n");
	if(sizeof(ob)<=1) tell_object(me,"什么人也没有。\n");
	else{
	for(i=0;i<sizeof(ob);i++)
	{   if(me!=ob[i]){
        tell_object(me,ob[i]->short()+"\n");
		tell_object(ob[i],me->name()+"拿着灯笼朝你照了几下。\n");}
	}
	}
	if( !mapp(exits) || !sizeof(exits) ){
		tell_object(me,"你发现四周根本就没有什么路。\n");}
	else{
        d=keys(exits);tell_object(me,"你发现四周的出口有:\n");
	    for(i=0;i<sizeof(d);i++)
		{
		
tell_object(me,HIY+d[i]+NOR+"   ");
		}
tell_object(me,"\n");
	}
	return 1;

}
