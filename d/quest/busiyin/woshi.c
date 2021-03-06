
inherit ROOM;
#include <ansi.h>

int do_move(string arg);

void create()	
{
	set("short", "卧室");
	set("long", @LONG
这里是宝象寺主持的卧室。这里打扫的干干净净，一尘不染。面前
是两个蒲团，旁边放着一个木鱼muyu。床上铺着一张凉席，在床头还放
着几本佛经。
LONG);
    set("exits", ([
	        "out" : "/d/changan/wulousi",
	]));
   set("item_desc",([
      "muyu":"这是一个普通木鱼，不过边缘处有些磨损了。\n",
      ])); 
 	  setup();
	
}

void init()
{
  add_action("do_move","move");
}

void clear(object ob)
{
  ob->delete_temp("move_muyu_times");
  ob->delete_temp("move_muyu_dir1");
  ob->delete_temp("move_muyu_dir2");
  ob->delete_temp("move_muyu_dir3");
  return;
}

int do_move(string arg)
{
  object ob;
  int kar;
  string dir;
  int times;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("你要挪动什么？\n");
  
  if(sscanf(arg,"木鱼 %s",dir)!=1||
  (dir!="right"&&dir!="left"&&dir!="up"))
  return notify_fail("你可以把木鱼挪到 右[right],左[left],上[up].\n");
  kar=ob->query("kar");
  ob->add_temp("move_muyu_times",1);
  times=ob->query_temp("move_muyu_times");
  
  if(!ob->query_temp("move_muyu_dir1"))
    ob->set_temp("move_muyu_dir1",dir);
  else
  if(!ob->query_temp("move_muyu_dir2"))
    ob->set_temp("move_muyu_dir2",dir);
  else
  if(!ob->query_temp("move_muyu_dir3"))
    ob->set_temp("move_muyu_dir3",dir);
    
  if(times<3)
  return notify_fail("你把木鱼往挪了一下\n");
  
  if(kar<=15){
    
    if(ob->query_temp("move_muyu_dir1")!="right"||
       ob->query_temp("move_muyu_dir2")!="right"||
       ob->query_temp("move_muyu_dir3")!="up"){
     clear(ob);
     return notify_fail("你发现没什么变化！\n");}}
  else
  if(kar<=20){
    
    if(ob->query_temp("move_muyu_dir1")!="up"||
       ob->query_temp("move_muyu_dir2")!="right"||
       ob->query_temp("move_muyu_dir3")!="up"){
     clear(ob);
     return notify_fail("你发现没什么变化！\n");}}
  else
  if(kar<=25){
    
    if(ob->query_temp("move_muyu_dir1")!="left"||
       ob->query_temp("move_muyu_dir2")!="up"||
       ob->query_temp("move_muyu_dir3")!="up"){
     clear(ob);
     return notify_fail("你发现没什么变化！\n");}}
  else
  if(kar<=30){
    
    if(ob->query_temp("move_muyu_dir1")!="up"||
       ob->query_temp("move_muyu_dir2")!="left"||
       ob->query_temp("move_muyu_dir3")!="up"){
     clear(ob);
     return notify_fail("你发现没什么变化！\n");}}
     
  tell_object(ob,"只听嘎吱一声，木鱼下边露出一个暗道！！\n");
  set("exits/down",__DIR__"mishi");
  call_out("del_enter",5);
  return 1;
}

void del_enter()
{
  delete("exits/down");
  return;
}
