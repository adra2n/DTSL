/*
 * File    : ���� (/d/job/killhaidao/lev2/ship_0_2.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:17:05 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
��һ�����������һ�ɷ���ζ������ı��С������������һ��
����ͻȻ��о������ӹ����Ľ���������
LONG
);
        set("exits",([
	"south" : __DIR__"ship_2_2",
        ]));
        setup();
//        replace_program(ROOM);
}
