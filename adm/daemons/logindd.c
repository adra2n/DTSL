//logindd.c for dt.
//written by yanyan.

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;
#include <badid.h>

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
   "真冰河", "仲少", "寇仲", "徐子陵", "它妈的","江泽民","邓小平","一世情缘",
});



object make_body(object ob);
int check_legal_id(string id);
int check_legal_name(string name);

void create() 
{
   seteuid(getuid());
   set("channel_id", "转世精灵");
   set("id", "logind");
}
int do_zhuanshi(object me)
{
  object ob;
  if(me->query("age")<me->query("con")+60&&!wizardp(me))
  return notify_fail("你阳寿未尽，还是好好活着吧！\n");
  tell_object(me,"\n好吧，请输入你转世后的新ID:\n\n");
  ob=new("/obj/login");
  input_to("get_id",1,me,ob);
  return 1;
}
void get_id(string id,object me,object ob)
{
  if(file_size("/data/login/"+id[0..0]+"/"+id+".o")>0){
    	tell_object(me,"这个名字已经有了，换一个吧:\n");
    	input_to("get_id",1,me,ob);
    	return;}
    if(!check_legal_id(id)){
    	input_to("get_id",1,ob,me,ob);
    	return;}
    ob->set("id",id);
    tell_object(me,"\n请输入你转世后的中文名字：\n\n");
    input_to("get_name",1,me,ob);
}

void get_name(string name,object me,object ob)
{
  if(!check_legal_name(name)){
    input_to("get_name",1,me,ob);
    return;}
  ob->set("name",name);
  tell_object(me,"请选择你的性别。\nGender:男性(Male) 女性(Female)>");
  input_to("get_gender",1,me,ob);
}
void get_gender(string arg,object me,object ob)
{
  if(arg==""){
  tell_object(me,"你只能选择男性或女性。\nGender:男性(Male) 女性(Female)>");
  input_to("get_gender",1,me,ob);return;}
  if(arg[0]=='f'||arg[0]=='F'){
  	ob->set("gender","女性");}
  else if(arg[0]=='M'||arg[0]=='m')
        ob->set("gender","男性");
  else { 
  	tell_object(me,"你只能选择男性或女性。\nGender:男性(Male) 女性(Female)>");
  input_to("get_gender",1,me,ob);return;}
 tell_object(me,"请设定密码。\nPassword:>");
 input_to("get_passwd",1,me,ob);
}
void get_passwd(string pass,object me,object ob)
{
  if(sizeof(pass)<5){
  tell_object(me,"密码长度至少五位。\nPassword:>");
  input_to("get_passwd",1,me,ob);return;}
  ob->set("password", crypt(pass,0) );
  tell_object(me,"请再输入一次密码。\nPassword Again:>");
  input_to("confirm_pass",1,me,ob);
}

void confirm_pass(string pass,object me,object ob)
{
  string oldpass;object user;string id,oldid;
  oldpass=ob->query("password");
  if( crypt(pass, oldpass)!=oldpass ){
  tell_object(me,"两次输入的密码不对，请重新输入。\nPassword:>");
  input_to("get_passwd",1,me,ob);return;}
  ob->set("body", USER_OB);
  if(!objectp(user=make_body(ob))){
  tell_object(this_player(),"无法继续下去，请报告巫师！\n");
  return;}
  user->set("str",me->query("str")+1);
  user->set("int",me->query("int")+1);
  user->set("con",me->query("con")+1);
  user->set("cor",me->query("cor")+1);
  user->set("kar",me->query("kar")+1);
  user->set("per",me->query("per")+1);
  user->set_skill("literate",me->query_skill("literate",1)+5);
  user->set("birthday", time() );
  user->set("food", 1000);
  user->set("water", 1000);
  user->set("channels", ({ "chat","rumor","dt","banghui","party","sale"}));
  user->set_temp("link_ob", ob);
  user->set_encoding(me->query_encoding());
  user->set("password",ob->query("password"));
  user->set("body",ob->query("body"));
  user->set("gender",ob->query("gender"));
  user->set("title","普通百姓");
  user->set("startroom","/d/newbie/door");
  user->set_temp("link_ob", ob);
  ob->set_temp("body_ob", user);
  user->setup();
  user->save();
  ob->save();
  oldid=me->query("id");
  rm(DATA_DIR + "login/"+oldid[0..0]+"/"+oldid+__SAVE_EXTENSION__);
  rm(DATA_DIR + "user/"+oldid[0..0]+"/"+oldid+__SAVE_EXTENSION__);
  tell_object(me,"你的原来资料已经删除！请重新用转世id连线！\n");
  destruct(ob);
  destruct(user);
  destruct(me);
  return;
}

object make_body(object ob)
{
   string err;
   object user;
   int n;

        if(!ob->query("body")) {
     return 0;
        }
   user = new(ob->query("body"));
   if(!user) {
     write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
     write(err+"\n");
     return 0;
   }
   seteuid(ob->query("id"));
   export_uid(user);
   export_uid(ob);
   seteuid(getuid());
   user->set("id", ob->query("id"));
   user->set_name( ob->query("name"), ({ ob->query("id")}) );
   return user;
}

int check_legal_id(string id)
{
   int i;
   string *legalid;

   i = strlen(id);
   
   if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
     write("对不起，你的英文名字必须是 3 到 8 个英文字母。\n");
     return 0;
   }
   while(i--)
     if( id[i]<'a' || id[i]>'z' ) {
        write("对不起，你的英文名字只能用英文字母。\n");
        return 0;
     }


 if(member_array(id,badid)!=-1){
	write("对不起，请不要使用这种英文名字。\n");
        return 0;}
   return 1;
}

int check_legal_name(string name)
{
   int i;

   i = strlen(name);
   
   if( (strlen(name) < 2) || (strlen(name) > 8 ) ) {
     write("对不起，你的中文名字必须是 1 到 4 个中文字。\n");
     return 0;
   }
   while(i--) {
     if( name[i]<=' ' ) {
        write("对不起，你的中文名字不能用控制字元。\n");
        return 0;
     }
     if( i%2==0 && !is_chinese(name[i..<0]) ) {
        write("对不起，请您用「中文」取名字。\n");
        return 0;
     }
   }
   if( member_array(name, banned_name)!=-1 ) {
     write("对不起，这种名字会造成其他人的困扰。\n");
     return 0;
   }

   return 1;
}