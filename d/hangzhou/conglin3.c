
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ��Ƭ���֣������дУ�һ����������ͷ����������������
��ȥ���ߣ���Ҫ�ҵ�������·���������˰�����ֻ���û���ҵ�����
��·��
LONG);

  set("exits", ([ 
  "west":__DIR__"guandao2",
  "east":__DIR__"conglin1",
  "north":__DIR__"conglin1",
  "south":__DIR__"shidong",
        ]));
 
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}
