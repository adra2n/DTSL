
inherit NPC;

void create()
{
   set_name("云玉真",({ "yun yuzhen","yun"}) );
        set("gender", "女性" );
        set("age",22);
        set("per",25);
        set("nickname","红粉帮主");
        set("long","这就是巨鲲帮的新任帮主云玉真自上任\n"+
                   "帮主云广陵被人刺杀后，按任的女儿云\n"+
                   "玉真更把巨鲲帮打理得有声有色。武艺\n"+
                   "精湛，尤胜乃父，被誉为东南武林的第\n"+
                   "一英雌。\n");
               
        set("combat_exp",400000);
        set_skill("parry",150);
        set_skill("dodge",150);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("leveltwo-sword",150);
        set_skill("niaozong-shu",150);
        set("shili/name","junkun_b");
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
        	(:apply_action,"leveltwo-sword",4,"damage":),
             }));
             
        set("inquiry",([
          "巨鲲帮":"我也想广大本帮，可是现在人手不多，很难和海杀帮等竞争的。\n",
          "徐子陵":"很久没有看到他了，还真有点想他。\n",
          "寇仲":"他最不老实了！！... ... 可是我已经很久没见他了。\n",
          ]));
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/tongxiao")->wield();
  
}

