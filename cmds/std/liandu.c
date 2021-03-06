

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg=({
HIY"$N"+HIY+"慢慢地用扇子扇着，药鼎上冒出阵阵热气。\n"NOR,
HIY"$N"+HIY+"慢慢地用扇子扇着，药鼎上冒出阵阵热气。\n"NOR,
HIY"$N"+HIY+"慢慢地用扇子扇着，药鼎上冒出阵阵热气。\n"NOR,
HIR"一阵阵药香飘了出来，$N"+HIR+"连忙将火稳了些。\n"NOR,
RED"$N"+RED+"用扇子小心的扇着，药味已经布满了四周。\n"NOR,
HIB"$N"+HIB+"感到有些眩晕，连忙捂住口鼻。\n"NOR,
BLU"$N"+BLU+"看火候差不多了，又往里面放了些毒虫。\n"NOR,
BLU"$N"+BLU+"轻轻地用药勺搅拌着。\n"NOR,
HIB"$N"+HIB+"盖上了药鼎的盖子，已经有些站立不稳了。\n"NOR,
HIW"$N"+HIW+"用药勺盛出一些药，泼在地上，滋地一声冒出一阵白烟。\n"NOR,
HIR"$N"+HIR+"将火势压小了一些，慢慢用扇子扇着。\n"NOR,
RED"$N"+RED+"放下了扇子，逐渐让火熄灭。\n"NOR,

});

string *levs=({
BLU"微弱"NOR,BLU"不强"NOR,HIB"普通"NOR,HIB"较强"NOR,
HIR"强烈"NOR,HIR"很强"NOR,HIM"极强"NOR,HIM"猛烈"NOR,
RED"剧烈"NOR,RED"致命"NOR,


});

int main(object me,string arg)
{
        string name,toolname,msg;
	object *medicine,tool;
	int i;
	int lev;
	
	if(!arg||sscanf(arg,"%s with %s",name,toolname)!=2)
	return notify_fail("请使用 liandu 药的名字 with 炼药工具。\n");
		
	if(!objectp(tool=present(toolname,me)))
		return notify_fail("你身上没有"+toolname+"这个工具。\n");
        
        if(!tool->query("yaoshi_tool"))
	return notify_fail("你只能拿药鼎炼毒！\n");
        
        if(me->query("vocation")!="药师")
	  return notify_fail("你不是药师，不能炼制药!\n");	
        lev=(int)me->query_skill("poison",1);
	if(lev<60)
	return notify_fail("你的毒术太低了，怎么炼毒？\n");
		
	if(me->is_busy())
		return notify_fail("你现在很忙，歇歇吧!\n");
	if(me->is_fighting())
		return notify_fail("你还是先打完仗再说吧！\n");
	
	medicine=all_inventory(tool);
	if(sizeof(medicine)<=0)
	return notify_fail(tool->query("name")+"里面是空的。\n");
	
	for(i=0;i<sizeof(medicine);i++)
	  if(!medicine[i]->query("poison_type"))
	   return notify_fail(medicine[i]->query("name")+"不能被用来炼制毒药！\n");
	
	if(me->query("gin")<me->query("max_gin")/2)
	 return notify_fail("你的精血太低了，无法炼药。\n");
	if(me->query("kee")<me->query("max_kee")/2)
	 return notify_fail("你的精血太低了，无法炼药。\n");
	if(me->query("sen")<me->query("max_sen")/2)
	 return notify_fail("你的精血太低了，无法炼药。\n");
	
	if(me->query("liandu_times")>=1000){
	  tell_object(me,"你体内的毒素过多，无法继续炼制毒药了！\n");
	  me->unconcious();
	  return 1;
	}
	
	msg="$N把"+tool->query("name")+"放到了地上，在下面点了堆火。\n\n"+
	    HIR"$N"+HIR+"用扇子煽了煽，火渐渐旺了起来。\n\n"NOR;
	
	message_vision(msg,me);
	
	me->start_busy(5);
	
	call_out("do_msg",5,me,tool,name,lev,0);
	return 1;
}

void do_msg(object me,object tool,string name,int lev,int times)
{
	if(!me||!tool||environment(tool)!=me)
        return;
      
      if(times==sizeof(msg)){
      	call_out("do_msg2",5,me,tool,name,lev);
      	me->start_busy(5);
      	return;
      }
      message_vision(msg[times]+"\n",me);
      
      if(lev>=250)
      	call_out("do_msg",5,me,tool,name,lev,times+1);
      else
      	call_out("do_msg",2,me,tool,name,lev,times+1);
      me->start_busy(5);
      return;
}

void do_msg2(object me,object tool,string name,int lev)
{
	
	mapping type;
	string long_msg,*types;
	object *medicine,new_med;
	int i;
	
	if(!me||!tool||environment(tool)!=me)
        return;
	
	type=([]);
	long_msg="\n";
	
	medicine=all_inventory(tool);
	if(sizeof(medicine)<=0)
	return;
	
	for(i=0;i<sizeof(medicine);i++){
	   type+=([ medicine[i]->query("poison_type/type"):
	            lev*medicine[i]->query("poison_type/gongxiao")/100+
	            random(tool->query("dlev")) ]);
	   // 药的功效=技能*药材功效/100+random(药鼎的效果，由铁匠打造决定的)                 
	   if(medicine[i]->query_amount()&&
	      medicine[i]->query_amount()>1)
	      medicine[i]->set_amount(medicine[i]->query_amount()-1);
	   else
           destruct(medicine[i]);
	}
	
	long_msg="这是"+me->name()+"炼制的"+name+"。\n";
	long_msg+="功效：\n";
		
	types=keys(type);
	for(i=0;i<sizeof(types);i++){
	  long_msg+="【"+types[i]+"】【"
	           +levs[type[types[i]]/30>sizeof(levs)-1?sizeof(levs)-1:type[types[i]]/30]+"】\n";
	}
	
	type+=([ "times":lev/10 ]);//毒药持续次数，一般为 15* lev/10 秒
	type+=([ "names":name ]);//毒药名字
		
	message_vision("\n"+name+"炼制好了！\n",me);
	
	new_med=new("/obj/medicine/poison");
	new_med->set("name",name);
	new_med->set("long",long_msg);
	new_med->set("heal_up",type);
		
	if(!new_med->move(me)){
          tell_object(me,"你的负重不够了！\n");
	  new_med->move(environment(me));
	}
	
	me->add("liandu_times",1);//增加一次炼毒记录。
	
	me->receive_damage("kee",me->query("max_kee")/2);
	me->receive_damage("gin",me->query("max_gin")/2);
	me->receive_damage("sen",me->query("max_sen")/2);
	
	me->add("vocation_score",random(lev/10));
	
	if(me->query_skill("poison",1)>=100)
	me->improve_skill("poison",(me->query_int()/3)+me->query("max_pot"));
	else me->improve_skill("poison",random(10));
	
    return;
}
