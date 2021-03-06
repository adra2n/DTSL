

#include <ansi.h>
#include "vocation.h"

inherit F_CLEAN_UP;

#include <medicine.h>


string *msg=({
HIY"$N"+HIY+"慢慢地用扇子扇着，药鼎上冒出阵阵热气。\n"NOR,
HIY"$N"+HIY+"慢慢地用扇子扇着，药鼎上冒出阵阵热气。\n"NOR,
HIY"$N"+HIY+"慢慢地用扇子扇着，药鼎上冒出阵阵热气。\n"NOR,
YEL"一阵阵药香飘了出来，$N"+YEL+"连忙将火稳了些。\n"NOR,
YEL"$N"+YEL+"用扇子小心的扇着，药香已经布满了四周。\n"NOR,
YEL"$N"+YEL+"打开药鼎看了看，发现还差一些火候。\n"NOR,
WHT"$N"+WHT+"看火候差不多了，又往里面放了药材。\n"NOR,
WHT"$N"+WHT+"轻轻地用药勺搅拌着。\n"NOR,
WHT"$N"+WHT+"盖上了药鼎的盖子，继续用扇子扇火。\n"NOR,
HIC"$N"+HIC+"用鼻子嗅了嗅，发现药马上就要炼好了。\n"NOR,
HIC"$N"+HIC+"将火势压小了一些，慢慢用扇子扇着。\n"NOR,
RED"$N"+RED+"放下了扇子，逐渐让火熄灭。\n"NOR,

});

int main(object me,string arg)
{
        string name,toolname,msg;
	object tool,*medicine;	
	int lev;
	
	if(!arg||sscanf(arg,"%s with %s",name,toolname)!=2)
	return notify_fail("请使用 lianzhi 药的名字 with 炼药工具。\n");
	
	if(!is_leagel_name(name))
	 return 1;
	
	if(!objectp(tool=present(toolname,me)))
		return notify_fail("你身上没有"+toolname+"这个工具。\n");
	
	if(!tool->query("yaoshi_tool"))
	return notify_fail("你只能拿药鼎炼药！\n");
        
        if(me->query("vocation")!="药师")
	  return notify_fail("你不是药师，不能炼制药!\n");	
        lev=(int)me->query_skill("bencao-shuli",1);
	if(lev<60)
	return notify_fail("你的本草术理太低了，怎么炼药？\n");
	
	medicine=all_inventory(tool);
	if(sizeof(medicine)<=0)
	return notify_fail(tool->query("name")+"里面是空的。\n");
		
	if(me->is_busy())
		return notify_fail("你现在很忙，歇歇吧!\n");
	if(me->is_fighting())
		return notify_fail("你还是先打完仗再说吧！\n");
	
	if(me->query("gin")<me->query("max_gin")/2)
	 return notify_fail("你的精血太低了，无法炼药。\n");
	if(me->query("kee")<me->query("max_kee")/2)
	 return notify_fail("你的精血太低了，无法炼药。\n");
	if(me->query("sen")<me->query("max_sen")/2)
	 return notify_fail("你的精血太低了，无法炼药。\n");
	
	msg="$N把"+tool->query("name")+"放到了地上，在下面点了堆火。\n\n"+
	    HIR"$N"+HIR+"用扇子煽了煽，火渐渐旺了起来。\n\n"NOR;
	
	message_vision(msg,me);
	
	me->start_busy(2);
	
	call_out("do_msg",2,me,tool,name,lev,0);
	return 1;
}

void do_msg(object me,object tool,string name,int lev,int times)
{
	if(!me||!tool||environment(tool)!=me)
        return;
      
      if(times==sizeof(msg)){
      	call_out("do_msg2",5,me,tool,name,lev);
      	me->start_busy(2);
      	return;
      }
      message_vision(msg[times]+"\n",me);
      
      if(lev>=250)
      	call_out("do_msg",1,me,tool,name,lev,times+1);
      else
      	call_out("do_msg",1,me,tool,name,lev,times+1);
      me->start_busy(1);
      return;
}

void do_msg2(object me,object tool,string name,int lev)
{
	mapping type;
	string *makeby;	
	object *medicine,new_med;
	int i;
	string longs;
	
	if(!me||!tool||environment(tool)!=me)
        return;
	
	type=([]);
	makeby=({});
		
	medicine=all_inventory(tool);
	if(sizeof(medicine)<=0)
	return;
	for(i=0;i<sizeof(medicine);i++){
	   type+=([ medicine[i]->query("medicine_type/type"):
	            lev*(1+random(7))*medicine[i]->query("medicine_type/gongxiao")/100+
	            random(tool->query("dlev")) ]);
	   // 药的功效=技能*药材功效/100+random(药鼎的效果，由铁匠打造决定的)
	   makeby+=({ medicine[i]->query("name") });
	   if(medicine[i]->query_amount()&&
	      medicine[i]->query_amount()>1)
	      medicine[i]->set_amount(medicine[i]->query_amount()-1);
	   else
           destruct(medicine[i]);
	}
	
	set_medicine_add_type(me,type);	
	
	longs="\n"+name+"炼制好了！\n";
	message_vision(longs,me);
	
	new_med=new("/obj/medicine/medicine");
	new_med->set("name",name);
	new_med->set("long","这是"+me->name()+"炼制的【"+name+"】\n");
	new_med->set("heal_up",type);
	new_med->set("makeby",makeby);
		
	if(!new_med->move(me)){
	  tell_object(me,"你的负重不够了！\n");
	  new_med->move(environment(me));
	}
	
	me->receive_damage("kee",me->query("max_kee")/2);
	me->receive_damage("gin",me->query("max_gin")/2);
	me->receive_damage("sen",me->query("max_sen")/2);
	
	me->add("vocation_score",random(lev/10));
		
	if(me->query_skill("bencao-shuli",1)>=100)
        me->improve_skill("bencao-shuli",(me->query_int()/3)+me->query("max_pot"));
	else me->improve_skill("bencao-shuli",random(10));
	
    return;
}

int help(object me)
{
write(@HELP
指令格式 : lianzhi <药物名字> with <工具>

这个指令让你炼制一些药物，当然前提是你必须是一名药师。
炼药的工具可以从多种途径得到，请参考职业的帮助文件以获得详细
的说明。
HELP
    );
    return 1;
}
