#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "一日fire从理发店扮酷回来，一进泥巴，众女生惊呼：“酷哥来也！”",
        "fire不好意思的挠挠头：“哪里！哪里！只是剪了个酷头而已。”",
        "恰巧lying从一旁走过，一本正经的说：“捡个裤头也要交公！”",
        "fire往巫师工作室走去，走到楼下，看到了fhq，高声吹嘘说，看，我剪了一个酷头。",
        "二楼马上有yanyan伸出头来说，我的裤头，你拣的是我的裤头……！！！！",
       
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
        STORY_D->give_gift("/clone/quest/kutou.c", 1,
                           HIM "\n“蓬”的一声一个裤头掉到你面前。\n\n" NOR);
        return HIM "一个裤头在江湖出现了。\n" NOR;
}
