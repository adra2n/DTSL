// /d/shanhaiguan/dadao1.c
// Room in 山海关
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "北厢房");
	set("long", @LONG
这是的饮马驿北厢房。这儿比起外面院子里安静了一些, 床上收拾
得干干净净。
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                 "south":__DIR__"kezhan",  
                	]));
       setup();
	replace_program(ROOM);
}
