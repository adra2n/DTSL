
inherit ROOM;
void create()	
{
	set("short","花园");
	set("long", @LONG
这里是一个小型的花园。这里花草繁多，均是名贵的品种。
因为这里气候四季如春，所以这里总是鲜花盛开。不时有武林侠
侣从这里走过。
LONG);
    set("exits", ([
	        "west" : __DIR__"nandajie4",
	        "north":__DIR__"asc/xsl",
	       
 	]));
 	
      setup();
      replace_program(ROOM);
	
}
