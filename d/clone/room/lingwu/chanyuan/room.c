inherit ROOM;
#include <ansi.h>
int do_open();
int do_push(string arg);
void create ()
{
  set ("short","禅房");
  set ("long", @LONG
这里是一个禅房。正中供着一尊佛像，面前是一张桌子，上
面已经积攒了很多灰尘。左边的墙壁上好象刻着些字，不过已经
模糊不清了，上面好象有一个小孔，似乎可以放「insert」进去
什么东西。
LONG);

  set("exits", ([ 
 "out":__DIR__"shanlu2",
        ]));
 set("valid_startroom", 1);
  setup();
}
void init()
{
  add_action("do_open","unlock");
  add_action("do_push","insert");
}
void noway(object ob)
{
  message_vision(YEL"只听“喀嚓”一声，钥匙断为两截！\n"NOR,ob);
  set("lock",1);
   return;
}

int do_open()
{
  object ob,key;
  int str,jiali;
  ob=this_player();
  if(!ob->query_temp("can_move_in"))
  return notify_fail("你推了几下，发现门根本推不开。\n");
  str=ob->query("str");
  jiali=ob->query("jiali");
  if(str<=15){
    if(jiali*10/ob->query_skill("force",1)!=10){
      noway(ob);return 1;}}
  else
  if(str<=20){
    if(jiali*10/ob->query_skill("force",1)!=7){
      noway(ob);return 1;}}
  else
  if(str<=25){
    if(jiali*10/ob->query_skill("force",1)!=4){
      noway(ob);return 1;}}
  else
  if(str<=30){
    if(jiali*10/ob->query_skill("force",1)!=1){
      noway(ob);return 1;}}
  message_vision("$N把钥匙旋转了几下，只听喀嚓一声，旁边露出了一个小暗门。\n",ob);
  ob->set("super_force_cy_no_open",1);
  set("exits/enter",__DIR__"chanyuan");
  ob->delete_temp("can_move_in");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
int do_push(string arg)
{
  object ob,key;
  ob=this_player();
  if(!arg)
  return notify_fail("你要插进去什么东西？\n");
  if(!objectp(key=present(arg,ob)))
  return notify_fail("你身上没有这个东西。\n");
  if(!key->query("unique"))
  return notify_fail("你发现钥匙根本插不进去。\n");
  
  if(ob->query("family_lingwu")=="chanyuan"&&
     ob->query("super_force_cy_no_open")){
   destruct(key);
   message_vision("$N用钥匙打开了门，然后走了进去。\n",ob);
   ob->move(__DIR__"chanyuan");
   return 1;
  }
     
  if(query("lock"))
  return notify_fail("你发现里面有个折断的钥匙，手中的钥匙根本插不进去。\n");  
  ob->set_temp("can_move_in",1);
  message_vision("$N把钥匙插进了钥匙孔。\n",ob);
  destruct(key);
  return 1;
}

void reset()
{
  delete("lock");
  return ::reset();
}
