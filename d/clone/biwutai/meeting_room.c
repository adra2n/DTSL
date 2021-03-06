
inherit ROOM;
#include <ansi.h>
int do_dengji(string arg);
int do_register(string arg);
int do_list();
string give_msg();
mapping d_member=([
 "feima":"飞马牧场","haisha":"海沙帮","songjia":"宋家堡",
 "duzun":"独尊堡","lifa":"李  阀","dajiang":"大江联",]);
void create()	
{
	set("short", HIG"比武台前厅"NOR);
	set("long", @LONG
这里是比武台的前厅。往西边走就可以比武了。一般说来，
这里是六大势力较量的地方。比赛的规则：五局三胜制，
每次两个势力进行较量。参加比赛的人，请您先在这里
来登记势力或帮派(dengji),每次只能登记两个势力，然后
比武人员来这里注册(zhuce)。每方只能出五个人。然后去
比武就可以了。关于登记的势力和帮会的代号请看牌子(pai).
可以使用list 来查看已经登记的势力或帮会。
(具体请 help biwu).
LONG);
    set("exits", ([
                "east" : "/d/taishan/yuhuangding",
	        "west":__DIR__"biwutai",
 	]));
 	set("no_fight",1);
 	set("no_sleep",1);
 	set("no_get",1);
 	set("no_quit",1);
 	set("item_desc",([
 	    "pai":(:give_msg:),
 	    ]));
 	  setup();
	
}	

void init()
{
   add_action("do_dengji","dengji");
   add_action("do_register","zhuce");
   add_action("do_list","list");
}
int do_dengji(string arg)
{
  object ob;string *party;
  ob=this_player();
   if(!arg)
   return notify_fail("你要登记什么？\n");
   if(!d_member[arg])
   return notify_fail("你想登记什么？请先look pai\n");
   if(arg+"_b"!=ob->query("shili/name"))
   return notify_fail("你没有为其他帮会登记的权利！\n");
   party=environment(ob)->query("dengji");
   if(sizeof(party)==2)
   return notify_fail("对不起，已经登记两个势力了，你还是等等吧！\n");
   if(sizeof(party)>0)
   if(member_array(arg,party)!=-1)
   return notify_fail("你的势力已经登记过了！\n");
   if(sizeof(party)>0)
   environment(ob)->set("dengji",party+({arg}));
   else environment(ob)->set("dengji",({arg}));
   if(sizeof(party)==0)
   message("system",HIG"【比武大会】:"+d_member[arg]+"在比武台随时恭候天下英雄的讨教！\n"NOR,users());
   else
   message("system",HIG"【比武大会】:"+d_member[arg]+"前来应战！\n"NOR,users());
   return 1;
}

int do_register(string arg)
{
   object ob;string *party;string *mem;
   ob=this_player();
   if(!arg) return notify_fail("你要注册什么？\n");
   if(!d_member[arg]) return notify_fail("看仔细一点把！look pai!\n");
   if(ob->query("clean/register_leitai"))
   return notify_fail("你已经注册过了！\n");
   if(arg+"_b"!=ob->query("shili/name"))
   return notify_fail("你没有为其他帮会出力比武的权利！\n");
   party=environment(ob)->query("dengji");
   if(sizeof(party)<=0)
   return notify_fail("现在没有势力登记，你先登记吧！\n");
   if(sizeof(party)>0)
   if(member_array(arg,party)==-1)
   return notify_fail("目前登记的不属于你的势力或势力。\n");
   mem=environment(ob)->query("register/"+arg);
   if(sizeof(mem)==5) return notify_fail("人已经满了，你等下次吧！\n");
   if(sizeof(mem)>0)
   if(member_array(ob->query("id"),mem)!=-1)
   return notify_fail("你已经注册过了！\n");
   ob->set("clean/register_leitai",arg);
   if(sizeof(mem)>0)
   environment(ob)->set("register/"+arg,mem+({ob->query("id")}));
   else environment(ob)->set("register/"+arg,({ob->query("id")}));
   message("system",HIG"【比武大会】:"+ob->name()+"代表"+d_member[arg]+"准备到擂台一显身手！\n"NOR,users());
   return 1;
}

string give_msg()
{
  return "目前可以登记的帮会或势力的代号有：\n"+  
  "势力: 宋家堡:songjia 飞马牧场:feima   \n"+
  "      海沙帮:haisha  独尊堡  :duzun   \n"+
  "      李  阀:lifa    大江联  :dajiang \n";
  
}

int valid_leave(object ob,string dir)
{
   if(dir=="west"&&!ob->query("clean/register_leitai"))
   return notify_fail("只有注册过的队员可以到擂台上去！\n");
   if(dir=="west"&&ob->query("clean/fail"))
   return notify_fail("你已经输了，不能再上去了！\n");
   if(dir=="east"&&ob->query("clean"))
   return notify_fail("等比武结束你再走吧！\n");
   if(this_object()->query("member_count")>=2&&dir=="west")
   return notify_fail("上面已经有两个人了！\n");
   this_object()->add("member_count",1);
   return ::valid_leave(ob,dir);
}

int do_list()
{
  string *party,str;int i;
  party=this_object()->query("dengji");
  if(sizeof(party)==0)
  return notify_fail("目前没有帮会或势力登记。\n");
  str=sprintf("目前登记的帮会:\n");
  for(i=0;i<sizeof(party);i++)
  {
    str+=d_member[party[i]];
    str+="\n";
  }
  write(str+"\n");
  return sizeof(party);
}
