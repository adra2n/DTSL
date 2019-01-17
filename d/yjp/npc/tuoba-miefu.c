// 大唐双龙传


inherit NPC;

int do_action1();

void create()
{
  set_name("拓跋灭夫", ({"tuoba miefu", "tuoba", "miefu"}));
  set("gender", "男性");
  set("long","这是高丽的拓拔灭夫，专门为高丽招纳新人。\n");
  set("age", 36);
  set("max_kee",400);
  set("max_gin",400);
  set("max_sen",400);
  set("max_force",400);
  set("force",400);
  set("combat_exp",4000);
 
  set_skill("force", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  
  set("target_id","###");
  
  set("inquiry",([
    "入籍":(:do_action1:),
    ]));
  setup();
  
}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("family")
    &&ob->query("family/family_name")!="弈剑派"){
    command("say 你已经是其他门派的弟子了，无法再入我高丽籍了！");
    return 1;
  }
  if(ob->query("family")
    &&ob->query("family/family_name")=="弈剑派"){
    command("say 你已经是我高丽的弟子了，快去学习武艺吧！");
    return 1;
  }
  ob->set_temp("bai_yjp_action1",1);
  command("say 高丽只欢迎武艺高强的人来，若你能打败我，我就向上级推荐你。");
  return 1;
}

int surrender(object killer,object victim)
{
   if(!killer->query_temp("bai_yjp_action1"))
   return 1;
   killer->set_temp("bai_yjp_action2",1);
   killer->delete_temp("bai_yjp_action1");
   command("say "+RANK_D->query_respect(killer)+"果然很厉害！你去找我的上司马吉去看看吧！");
   return 1;
}