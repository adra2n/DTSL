// /d/gaoli/baihutang.c
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "白虎堂");
	set("long", @LONG
厅内正中一张几案，几案的后面有一张虎皮大椅，两侧放着十多把
椅子，墙上挂着一张猛虎下山图，这就是塞漠帮的权利中心--白虎堂。
LONG
	);
set("exits", ([
	        "west" : __DIR__"siheyuan",
            	"east" : __DIR__"shufang",
	]));
       setup();
	replace_program(ROOM);
}	
