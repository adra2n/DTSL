

inherit F_CLEAN_UP;
inherit F_DBASE;

#include <ansi.h>
#include "map.h"

void start_quest()
{
   string *where;
   int i;
   object ob;
   
   where=keys(map);
   i=random(sizeof(where));
   
   ob=new(__DIR__"man");
   ob->move(where[i]);
   
   message("vision",HIM"【谣言】某人：据说有人正携带着一件"+HIG+"宝物"+HIM+"出现在"+map[where[i]]+"！\n"NOR,users());
   return;
}