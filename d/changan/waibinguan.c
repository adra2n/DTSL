
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǳ����ǵ�����ݣ����������������Ƕ�Ҫס�����������
���൱����ƹ����Ա߲�ͣ�������ʱ�����С����������ȥ���к���
���Ŀ���æ����ͣ��
LONG);

  set("exits", ([ 
 "east":__DIR__"ahdajie5",
 "up":__DIR__"wofang",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="up")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("��С����ס���㣺�͹٣�����û��Ǯ��!\n");
		else return notify_fail("�ƹ�����溰�����͹٣���Ǯ��ס�갡!\n");
		return ::valid_leave(me,dir);
		return 1;
}