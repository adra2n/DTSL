// /d/gaoli/nanchenglou
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "南城楼");
	set("long", @LONG
以合抱粗的木柱为梁，飞檐斗角，惜日也雕梁画柱，可惜被风霜腐
蚀的面目全非，朱红的柱子也露出青石的痕迹。俯身望去，一匹匹的快
马由远到近。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
	        "east" : __DIR__"chengqiangshang1",
            	"west" : __DIR__"chengqiangshang2",
	]));
       setup();
	replace_program(ROOM);
}	
