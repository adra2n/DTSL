
inherit ROOM;
void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路，蜿蜒曲折。四周是苍翠的树木，不时传来几声鸟
鸣叫的声音。两旁杂草丛生，经常会有野兔从你的脚前窜过。
LONG);

  set("exits", ([ 
 "south":"/d/quest/bawangdao/xiaojing",
 "northeast":__DIR__"xiaolu2",
 "west":__DIR__"chitang",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
