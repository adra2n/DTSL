
inherit ROOM;


void create ()
{
  set ("short","回龙寺");
  set ("long", @LONG
这里就是回龙寺的门口了。只见寺庙牌匾的颜色有些脱落了，只有
[回龙寺]三个字还看的清楚。庙门虚掩着，里面隐隐约约传来了颂经念
佛的声音。
LONG);

  set("exits", ([ 

  "eastdown":__DIR__"shijie",
  "enter":__DIR__"huilongsi",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

