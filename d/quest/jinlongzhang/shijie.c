
inherit ROOM;


void create ()
{
  set ("short","石阶");
  set ("long", @LONG
这里是一条石阶铺成的小路。抬头望去，前面有一家寺庙，看不清
楚牌匾上的字。石阶的两旁是碧绿的树木，旁边还立着一个石碑，上面
写着[回龙岗]三个大字。
LONG);

  set("exits", ([ 

  "southeast":__DIR__"suishilu1",
  "westup":__DIR__"miaodoor",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

