
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghe_dukou1"
#define TO __DIR__"huanghe_dukou2"
#include "/std/shiproom.c"

void create ()
{
  set ("short","�ƺӶɿ�");
  set ("long", @LONG
�����ǻƺӵĶɿڡ���ǰ�ƺӹ��������ƾ��ˡ�ֻ��һҶ��������
�������ˡ�
LONG);

  set("exits", ([ 

  "north":"/d/liyang/dadao7",
  "east":__DIR__"huanghe4",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}