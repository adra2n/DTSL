
inherit ROOM;

int do_move();
void create ()
{
  set ("short","�᷿");
  set ("long", @LONG
������һ��С�᷿��ֻ����������ɵģ�����������ʲô���ڡ���
�ߵ�ǽ�Ϲ���һ�����ӣ�����д�š��ޡ���������ȥ���Աߺ����м�
�����ӡ�ǽ�ϻ���һ�����ذ��֣��ƺ�������[move]һ�¡�
LONG);

 set("exits", ([ 
  "north":__DIR__"wu"+(1+random(8)),
  "west":__DIR__"wu"+(1+random(8)),
  "east":__DIR__"wu"+(1+random(8)),
  "south":__DIR__"wu"+6,
     ]));

  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_move","move");
}

int do_move()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_lev1_quest_chanzhang/step8"))
  return notify_fail("��ʹ��������Ҳ�Ʋ������֡�\n");
  ob->delete_temp("dtsl_lev1_quest_chanzhang/step8");
  ob->set_temp("dtsl_lev1_quest_chanzhang/step9",1);
  message_vision("$N���˰���һ�¡�\n",ob);
  return 1;
}