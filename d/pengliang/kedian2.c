// Room: /d/city/kedian2.c

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�
����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ�
����Ǯ������˯����
LONG
	);

	set("exits", ([
		"down" : __DIR__"kezhan",
		"enter" : __DIR__"kedian3",
	]));

	setup();
	replace_program(ROOM);
}
