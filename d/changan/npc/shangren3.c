
inherit NPC;

void create()
{
   set_name("盐商",({ "yan shang","yan","shang"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是一位盐商。\n");
       
   set("combat_exp", 300000);
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
   object ob;
   
   ob=this_player();
   
   if(!ob||is_fighting()) return;
   
   remove_call_out("welcome");
   call_out("welcome",1,ob);
   
}

void welcome(object ob)
{
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
   
   switch(random(2)){
    case 0:
     command("say 最近强盗太多，生意不好做了啊！");
     break;
    case 1:
     command("say 还好长安治安不错，不然可让我们怎么活。");
   }
   
}

