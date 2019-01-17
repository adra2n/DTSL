
inherit NPC;
string *name1=({"赵","钱","孙","周","吴","郑","王"});
string *name2=({"萍","绣风","丽","秋菊","雪","梅","芬","雅"});
void create()
{
   set_name(name1[random(sizeof(name1))]+name2[random(sizeof(name2))]
   ,({ "killer" }) );
        set("gender", "女性" );
        set("title","阴癸派杀手");
        set("age", 32);
   set("long", "这是阴癸派杀手。\n");
   set("combat_exp", 800000);
   set("str", 30);
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",3000);
   set("force",3000);
   set_skill("force",200);
   set_skill("sword",200);
   set_skill("tianmo-dafa",200);
   set_skill("tianmo-dai",200);
   set_skill("tianmo-jianfa",200);
   set_skill("tianmo-huanzong",200);
   set_skill("unarmed",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set("hand",({"tianmo-dai"}));
   set("dodge",({"tianmo-huanzong"}));
   set("sword",({"tianmo-jianfa"}));
   set("chat_chance_combat",90);
   set("chat_msg_combat",({
   	(:perform_action,"feiyun":),
   	(:perform_action,"feimo":),
   	}));
   set("accept_kill",1);
   setup();
   carry_object(__DIR__"cloth")->wear();
  carry_object(__DIR__"changjian")->wield();
}
int accept_kill(object killer,object me)
{
  if(me->query("target_id")!=killer->query("id"))
  return notify_fail("对方根本不理会你的作战请求！\n");
  return 1;
}
