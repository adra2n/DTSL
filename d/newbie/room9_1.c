
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","商人篇");
  set ("long", @LONG
做商人无疑是有很大赚头的，以后卖东西、买东西都可以比其他人
合算。要做商人，到乐寿找一个叫“买卖王”的人，然后向他qiuzhi，
就可以了。不过你请教(qingjiao)他的时候，每次要花掉10文铜钱----
无商不奸嘛！这样你就可以学习[讨价还价]技能了。如果此技能很高，
那你买卖东西就很赚了！商人另外一个作用是可以在行会拍卖东西，具
体请使用 help hanghui 来查看。
LONG);

  set("exits", ([ 
 "east":__DIR__"room9",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

