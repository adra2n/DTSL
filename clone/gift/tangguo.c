#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "月儿弯弯，无限星空。夜色，好美。",
        "Chris和Forever在这样美的夜色中，赏月。",
        "可是他们，发现一个问题... ... ...",
        "月亮上，有个象女人的家伙，也在看着他们。",
        "这个人是谁呢——当然是那个最爱男扮女装的Yanzi了！",
        "Yanzi正在月亮上偷吃嫦娥的糖果。",
        "而由于Yanzi不讲卫生，把糖果乱丢。",
        "正好砸到月亮下读书的Rain，Rain被砸昏了。",
        
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/quest/tangguo.c", 1,
                           HIM "\n“蓬”的一声一个糖果掉到你面前。\n\n" NOR);
        return HIM "一个神秘的糖果在江湖出现了。\n" NOR;
}
