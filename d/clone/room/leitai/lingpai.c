//令牌。
/*每月的帮会比武的胜利者所
  获得的令牌。
*/
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;
string OWNER;
string query_save_file()
{
	string id;

	if( !stringp(id = this_object()->query("save_id")) ) return 0;
	return DATA_DIR + "npc/boss/" + id;
}
int do_set_owner(string arg);
void create()
{
	set_name(HIR"令牌" NOR, ({ "ling pai", "ling","pai" }));
       	set("long", "这是一块令牌，上面写着「天下第一帮」。\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("value", 50000);
		set("no_sell",1);		
		set("material", "千年玄铁");
		set("save_id","lingpai_save_file");
		
	}
	setup();
	
}	
int query_autoload()
{
	restore();
	return 1;
}

void init()
{
  object ob;
  add_action("do_set_owner","setowner");
  ob=environment(this_object());
  if(!interactive(ob)||ob->is_corpse()){
  delete("no_give");
  delete("no_drop");}
  if(!wizardp(ob)){
  set("no_give",1);
  set("no_drop",1);}
  else{
  delete("no_give");
  delete("no_drop");}
  restore();
}

int is_get_of(object me,object ob)
{
  if(me->query("shili/leader")==OWNER||wizardp(me))
  return 1;
  return notify_fail("只有"+query("only")+"的首领才可以拣起"+query("name")+"\n");
}
string get_name(string arg)
{
  switch(arg){
   
   case "天策府":return "lifa_b";
   case "海沙帮":return "haisha_b";
   case "大江联":return "dajiang_b";
   case "独尊堡":return "duzun_b";
   case "宋家堡":return "songjia_b";
   case "飞马牧场":return "feima_b";
   default:return "error";}
}

int help()
{
  write("
  请使用 setowner 帮会名称 格式。
  帮会名称可以是:
  天策府
  海沙帮
  大江联
  独尊堡
  宋家堡
  飞马牧场
  \n");
  return 1;
}

int do_set_owner(string arg)
{
  object ob;
  ob=this_player();
  if(!wizardp(ob)) return 0;
  if(!arg) return (int)help();
  if(get_name(arg)=="error") return (int)help();
  OWNER=get_name(arg);
  set("long",query("long")+"\n"+NATURE_D->game_time()+" 比武成为天下第一帮会是"+HIW+arg+NOR+"\n");
  set("only",arg);
  tell_object(ob,"本月拥有此令牌的帮会为"+arg+"\n");
  save();
  return 1;
}

int clean_up()
{
  return 0;
}
