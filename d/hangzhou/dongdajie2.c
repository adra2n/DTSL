inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是杭州的东大街。东边是杭州的东门了。北边有一座园林，有
很多游人朝那里走去。只见那里正有几个人在吟诗做对，虽然如今时局
混乱，但杭州的宁静似乎让这几个人忘记了战乱的危机。
LONG);

  set("exits", ([ 

  "east":__DIR__"dongmen",
 "south":__DIR__"dangpu",
   "west":__DIR__"dongdajie1",
   "north":__DIR__"yuanlin",
         ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

