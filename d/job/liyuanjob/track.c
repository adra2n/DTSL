
#include <ansi.h>

inherit ITEM;
#define TIME_TICK1 (time()*60)
#define MAX_LIGHT_TIME 1200
int do_drive(string arg);
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
        set_name("粮草车", ({ "che" }) );
        set_weight(1000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("long", "这是一辆运送粮草的大车。");
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
  return notify_fail("这不是你护送的粮草车！\n");
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
  message_vision("一个朦胧的身影推着$n朝"+default_dirs[arg]+"走去。\n",
                 this_object());
   else
  message_vision("$N推着$n朝"+default_dirs[arg]+"走去。\n",
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
  tell_object(room,"一个朦胧的人影推着"+query("name")+"走了过来。\n");
  else
  tell_object(room,ob->name()+"推着"+query("name")+"走了过来。\n");
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