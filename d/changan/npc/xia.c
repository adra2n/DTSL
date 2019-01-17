
inherit "/std/lmaster.c";

void create()
{
        set_name("夏先生", ({"xia xiansheng", "xia","xiansheng"}));
        set("title", "书院先生");
        set("gender", "男性");
        set("age", 64);
        set("long","这是书院的先生,他的学识可是长安出名的.\n");
        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 500); 
        set("max_kee", 500);
        set("gin", 100);
        set("max_gin", 100);
        set("sen",300);
        set("max_sen",300);
        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("literate",400);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

