
#include <ansi.h>
inherit ROOM;

#define JOBNAME "����"

void create ()
{
  set ("short","�ξ�");
  set ("long", @LONG
�����Ǹ������ξ֣��ܹܸ��������ˡ���������ս�ң���䷷��˽
�ε������Ž���ֹ�������ξֵ����Ⲣ���Ǻܺá������ٸ�����һЩ��
�������Σ����ǻ�Ҫ��ֹ���˰�·�����γ���������Ӧ�ٵĴ󲿷ֶ���
�����е����ֻ��һ���ξֵĹٲ��������ݵ�վ�������ʱ���˴�
�����������γ�������ȥ��
LONG);

  set("exits", ([ 
 "north":__DIR__"qinglong-2",
       ]));
  set("objects",([
	  "/d/job/yunyanjob/guanchai":1,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}
