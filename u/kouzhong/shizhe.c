// By Spiderii 改版，暂时这样，以后随时变动！
#include <ansi.h>
#define SKILLS_LEVEL            182
#define KNOWLEDGE_LEVEL            120
#define GIVE_EXP                600000
#define MAX_NEILI               3500
#define MAX_JINGLI              2100
inherit NPC;
string ask_xx();
string ask_sk();
string ask_tianzi();
object ob = this_object();
void create()
{
    set_name(HIC"嫦娥仙子"NOR, ({"change xianzi","change","xianzi" }));
    set("title", ""HIY"月"HIM"宫"HIC"天"HIG"使"NOR"");   
    set("gender", "女性");
    set("age", 22);
    set("per", 100);
    set("str", 40);
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("qi",5000);
    set("jingli",6000);
    set("max_qi", 8000);
    set("max_jing", 5000);
    set("eff_jingli", 6000);
    set("jiali", 190);
    set("combat_exp", 9000000);
    set("shen", 25000);
    set("chat_chance_combat", 60);
    setup();
    set("inquiry", ([
        "中秋快乐" : "也祝你中秋快乐，请问你想要什么礼物呢？（ask xianzi about 〈礼物类型〉）\n属性各2点？经验潜能？隐藏属性？\n",
   "属性各2点" : (: ask_xx :),
   "经验潜能" : (: ask_sk :),
   "隐藏属性" : (: ask_tianzi :),
      ]) );
}

void greeting(object ob)
{
 if (!ob || !present(ob, environment())) return;
            write(HBRED"请ask xianzi about 中秋快乐 来的到奖励！\n"NOR);

}

string ask_xx()
{
    if (this_player()->query("shizhe_拜师")) return "你不是要过一次礼物了嘛！？\n";
    message_vision(HIY "嫦娥"+ NOR "一挥手，你感觉身体起了些变化。"+ NOR "\n",this_player());
    this_player()->add("str",2);
    this_player()->add("int",2);
    this_player()->add("dex",2);
    this_player()->add("shizhe_拜师",1);
    this_player()->add("con",2);
    return "祝你玩得愉快!";
}
string ask_tianzi()
{
    if (this_player()->query("shizhe_拜师")) return "你不是要过一次礼物了嘛！？\n";
    message_vision(HIY "嫦娥"+ NOR "一挥手，你感觉今天的运气肯定很好，人也感觉漂亮了很多。"+ NOR "\n",this_player());
    this_player()->set("kar",30);
    this_player()->set("per",30);
    this_player()->set("shizhe_拜师",1);
    return "你现在的富源和容貌是大唐第一哟！祝你玩得愉快!";
}
string ask_sk()
{
    if (this_player()->query("shizhe_拜师")) return "你不是要过一次礼物了嘛！？\n";
    message_vision(HIY "嫦娥"+ NOR "一挥手，你感觉对武学的经验增强了，想通了很多平时想不通的地方!"+ NOR "\n",this_player());
    this_player()->add("combat_exp",GIVE_EXP);
    this_player()->add("potential",2000);
    this_player()->set("shizhe_拜师",1);
    return "潜能请在下线前用完，掉了不要找我啊!";
}
