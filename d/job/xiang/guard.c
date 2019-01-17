
inherit JOBNPC;

#include <job_money.h>

void create()
{
   set_name("保镖",({ "guard" }) );
   set("gender", "男性" );
   
    
   set("long", "这是一名保镖。\n");       
   
   set("dex",20+random(10));
   set("str",20+random(10));
  
   set_temp("apply/dodge",50+random(50));
   set_temp("apply/armor",50+random(50));
  
   setup();
  
}



//此物件维持  秒
int clear()
{
  if(time()-query("last")<8000)
  return 0;
  if(!query("no_msg")){
  message_vision("$N匆匆地走了。\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
   
   if(clear())
   return 1;
   
   return ::chat();
}

int set_status(object ob)
{
  
  JOBNPC_D->set_xiangjob_killer(this_object(),ob);
  return 1;
}