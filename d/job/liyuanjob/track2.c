
#include <ansi.h>

inherit ITEM;
#define TIME_TICK1 (time()*60)
#define MAX_LIGHT_TIME 1200
int do_drive(string arg);
int do_task(string arg);
mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"东",
	"west":			"西",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
        "enter":                "里",
	"up":			"上",
	"down":			"下",
	"out":			"外",
]);
void create()
{
        set_name("马车", ({ "ma che","che" }) );
        set_weight(1000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("long", "这是一辆结实的大马车。");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_get",1);
                set("material", "wood");
        }

        setup();
}

void init()
{
   add_action("do_drive","drive");
   add_action("do_task","task");
   if(!query("last_time"))
    set("last_time",time());
}

int do_drive(string arg)
{
  object ob;
  object env;
  object room;
  string dir;
  object *inv;
  
  ob=this_player();
  if(query("owner")!=ob&&!wizardp(ob))
  return notify_fail("这不是你护送的马车！\n");
  if(!arg)
  return notify_fail("你要把车往哪个方向推？\n");
  if(time()-query("busy_time")<3+random(1))
  return notify_fail("你先歇歇吧！\n");
  if(ob->query("sen")<20)
  return notify_fail("你太疲劳了，歇歇再走吧！\n");
  if(ob->is_fighting())
  return notify_fail("你还是先打完仗吧！\n");
  if(ob->is_busy())
  return notify_fail("你正忙着呢！\n");
  dir=environment(ob)->query("exits/"+arg);
  if(!stringp(dir))
  return notify_fail("这里没有这个方向。\n");
  inv=all_inventory(ob);
  if(sizeof(inv)>=40)
  return notify_fail("你身上的东西太多了，根本走不动路。\n");
  
  env=environment(ob);
  if(default_dirs[arg])
   if ((	(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅时") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0) ) 
		&& env->query("outdoors")
		&& ob->query_temp("light")<time()-MAX_LIGHT_TIME
		&& (!wizardp(ob) || !ob->query("env/wiz_look")))    
  message_vision("一个朦胧的身影赶着$n朝"+default_dirs[arg]+"走去。\n",
                 this_object());
   else
  message_vision("$N赶着$n朝"+default_dirs[arg]+"走去。\n",
                 ob,this_object());
  room=load_object(dir);
  if(!objectp(room))
  return notify_fail("你感到事情有些不对了，应该报告BUG了。\n");
  if ((	(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅时") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0) ) 
		&& env->query("outdoors")
		&& ob->query_temp("light")<time()-MAX_LIGHT_TIME
		&& (!wizardp(ob) || !ob->query("env/wiz_look")))    
  tell_object(room,"一个朦胧的人影赶着"+query("name")+"走了过来。\n");
  else
  tell_object(room,ob->name()+"赶着"+query("name")+"走了过来。\n");
  this_object()->move(room);
  set("busy_time",time());
  ob->add("sen",-10+random(10));
  ob->move(room);
  message_vision("$N警觉地朝四下打量了一下，看看有没有可疑的现象。\n",ob);
  return 1;
}

int clean_up()
{
  if(time()-query("last_time")<3600*3)
   return 0;
  return 1;
}

int do_task(string arg)
{
  object ob;
  
  ob=this_player();
  if(!arg||arg!="ok")
  return notify_fail("请使用 task ok 来复命。\n");
  if(query("owner")!=ob&&!wizardp(ob))
  return notify_fail("这不是你护送的马车！\n");
  if(base_name(environment(ob))!="/d/job/tujuejob/neiting")
  return notify_fail("还没到地方呢！\n");
  ob->add_temp("liyuan_job/step",1);
  tell_room(environment(ob),"里面立刻出来几个官兵，护送着"+query("name")+"进去了！\n");
  CHANNEL_D->do_channel(this_object(),"rumor",
  ob->name()+"成功将军机大臣护送到了扬州！\n");
  destruct(this_object());
  return 1;
}
  