// /d/taiyuan/nroad1.c
// Room in 太原
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "大官道");
	set("long", @LONG
这是一条由青石铺成的驿道，因为还算太平的关系，来往的行人客
商还比较多，向下走就要进入河南的地界了，北面你可以看见太原的城
墙。
LONG
        );
set("outdoors", "/d/taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "northwest":__DIR__"nanmen", 
                "east":__DIR__"sroad2", 
                "southwest":__DIR__"sroad6", 
	]));
       setup();
	replace_program(ROOM);
}
