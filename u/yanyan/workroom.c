/*
真冰河(Yanyan)的工作室。
*/
#include <ansi.h>
inherit ROOM;
string show_paper();
string show_self();
void create()
{
	set("short",HIC"真冰河的家"NOR);
        set("long", @LONG[1;36m
            .-"''-.  _
          .'       `( \
        @/            ')   ,--,__,-"
        /        /      \ /     /   _/
      __|           ,   |/         /
    .~  `\   / \ ,  |   /
  .~      `\    `  /  _/   _/
.~          `\  ~~`__/    /
~             `--'/
             /   /    /     真怀念那无忧无虑的日子……
            /  /'    /[2;37;0m
旁边的桌子上还有一个盘子 (pan)，墙上贴着一张纸 (paper)，
地上还放着一个大音响(yinxiang)，床头还摆着一个镜子(jing)。
LONG
);
        set("item_desc",([
        "bei":HIW"寒冰居\n\n"NOR,
        ]));
        set("objects",([
          __DIR__"box":1,
          ]));
        set("exits",([
	"out" : "/d/wiz/wizroom2",
        ]));
        set("no_quit",1);
        set("no_death",1);
        set("item_desc",([
        "pan":"
         _..,----,.._
      .-;'-.,____,.-';
     (( |            |
      `))            ;   要牛奶、咖啡、还是茶……
       ` |          | 
      .-' `,.____.,' '-.
     (     '------'     )
      `-=..________..--'
      \n",
      "paper":(:show_paper:),
       "yinxiang":"
    ●        ●）      ●       ● ）     ＼●／    ＼●
＜┃＞   （┃       （┃）   （）         ┃┃      （ ＞ 
 ／＼    ／ ）      （＼    ／ ）        ／ ＼       ／＼\n"+
BLINK+"=左三圈，右三圈，脖子扭扭，屁股扭扭，你就不会老= 
        \n"NOR,
       "jing":(:show_self:),
      ]));
      
        setup();
}

int valid_leave(object ob,string dir)
{
  if(!wizardp(ob))
   return notify_fail("到了主人家还是不要随处走动的好。\n");
  return ::valid_leave(ob,dir);
}

string show_paper()
{
  write(@LONG
   　　　　　 _/　 \_
 　　　　 _/　　　/\_
 　　　 _/　　　 / / \_
 　　 _/　　　　/ /　　\_
 　　/  __ ____/ /　　　 \
 　 | (__ ____/_/_()~~~~~|
 　　\_　　　/ /　　　　_/
 　　　\_　 / /不准吃烟_/
 　　　　\_/ /　 OK! _/
 　　　　　\/　　  _/
LONG);
return "\n";
}
string show_self()
{
  write(@LONG
    @@@@@
   @@. .@@
  @@@\=/@@@
  @.-- --.@
  /(.) (.)\
  \ ) . ( /
  '(  v  )`
    \ | /
    ( | )   你很性感
    '- -`
LONG);
return BLINK+HIC"嘿嘿...\n"NOR;
}