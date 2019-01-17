
inherit NPC;

void create()
{
   set_name("游秋雁",({ "you qiuyan","you","qiuyan"}) );
        set("gender", "女性" );
        set("age", 32);
   set("long", "这是海沙帮的游秋雁，她曾经是海沙帮帮主的姘妇兼手下。\n");
       
   set("combat_exp",100000);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
   set("youqiuyan",1);
   set("shili",([
      "name":"haisha_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void revive()
{
   object ob;
   string msg;
   
   ::revive();
   
   if(!query("flag_ob"))
   return;
   ob=query("flag_ob");
   if(environment(this_object())!=environment(ob))
   return;
   
   msg="\n$N打了个哆嗦，浑身扭曲起来，脸上露出痛苦的表情！\n\n"+
       "$N朝$n告饶道："+RANK_D->query_respect(ob)+"，我同意与你合作，请给我解药吧！\n";
   msg +="\n$n阴险地一笑，给了$N一包解药。\n\n";
   msg +="$N连忙服下解药，脸上痛苦的神色渐渐消失。\n\n";
   message_vision(msg,this_object(),ob);
   command("follow "+ob->query("id"));
   delete("flag_ob");
   return;
}
   
