// 大唐双龙传
//bing.c 小兵
 
inherit "/std/guard.c";

void create()
{
        set_name("小兵", ({ "xiao bing", "bing" }));
        set("age", 18+random(10));
        set("gender", "男性");
        set("long","这是一名士兵，这些士兵隶属御林军，是士兵中的精锐。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("combat_exp", 800000);
        
        set("guard","liyang");
        
        set_this_skills("high");
        set_all_skill(this_object(),180);

        setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
      
}
