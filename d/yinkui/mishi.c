
#include <ansi.h>
inherit ROOM;


void create ()
{
  
  set ("short",HIM"极乐福地"NOR);
  set ("long", @LONG
这里是阴癸派辟守玄的住处，门上写个“极乐福地”四个大字。这
里地势隐蔽，屋子也不是很大，看起来更象是一个密室。屋子正中摆放
着一张大床，旁边还有许多华丽名贵的摆设。
LONG);
  set("exits",([
	  "southwest":__DIR__"chitang",
	  ]));
	  
  set("objects",([
    __DIR__"npc/pishouxuan":1,
    ]));
    
  set("valid_startroom", 1);
  setup();
 
}

/*
void reset()
{
   object *ob;
   object ob2;
    int i,j;
    
   ::reset();
   ob=children(__DIR__"obj/feibiao");
   j=0;
   for(i=0;i<sizeof(ob);i++)
      if(ob[i]&&environment(ob[i]))
      j +=ob[i]->query_amount();
      
   if(j<4){
   	
        ob2=new(__DIR__"obj/feibiao");
        ob2->set_amount(4-j);
        ob2->move((this_object()));
     }
    
}
*/
        
     
      