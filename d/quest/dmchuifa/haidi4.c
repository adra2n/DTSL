
inherit ROOM;

int do_jump(string arg);
void create ()
{
  set ("short","海底");
  set ("long", @LONG
这里是浅海的底部，这里光线明亮，道道光线从头顶直射下来。海
底礁石错综盘列，但乱中有序，似乎是隐藏着什么阵法。游鱼小虾在你
的身旁游来游去，别有一翻情趣。
LONG);

  set("exits", ([ 

  "east":__DIR__"haidi4",
  "west":__DIR__"haidi3",
  "north":__DIR__"haidi5",
  "south":__DIR__"haidi2",
      ]));

  set("valid_startroom", 1);
  setup();
 
}
