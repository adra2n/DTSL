#include <job_money.h>
#include <ansi.h>

string *names1 = ({
  WHT"陈"NOR,"chen",
  WHT"杜"NOR,"du",
  WHT"李"NOR,"li",
  WHT"张"NOR,"zhang",
  WHT"王"NOR,"wang",
  WHT"何"NOR,"he",
  WHT"欧"NOR,"ou",
  WHT"周"NOR,"zhou",
  WHT"胡"NOR,"hu",
  WHT"马"NOR,"ma",
  WHT"麦"NOR,"mai",
  WHT"史"NOR,"shi",
  WHT"廖"NOR,"liao",
  WHT"林"NOR,"lin",
  WHT"白"NOR,"bai",
  WHT"菜"NOR,"cai",
  WHT"金"NOR,"jin",
  WHT"朝"NOR,"chao",
  WHT"卢"NOR,"lu",
  WHT"吴"NOR,"wu",
  WHT"黄"NOR,"huang",
  WHT"严"NOR,"yan",
});

string *names2 = ({
  YEL"峰"NOR,"feng",
  YEL"飞"NOR,"fei",
  YEL"粱"NOR,"liang",
  YEL"慧"NOR,"hui",
  YEL"荣"NOR,"rong",
  YEL"阳"NOR,"yang",
  YEL"昆"NOR,"kun",
  YEL"威"NOR,"wei",
  YEL"宇"NOR,"yu",
  YEL"宙"NOR,"zhou",
  YEL"发"NOR,"fa",
  YEL"栋"NOR,"dong",
  YEL"然"NOR,"ran",
  YEL"平"NOR,"ping",
  YEL"凌"NOR,"ling",
  YEL"江"NOR,"jiang",
  YEL"仁"NOR,"ren",
  YEL"冉"NOR,"ran",
  YEL"庄"NOR,"zhuang",
  YEL"业"NOR,"ye",
});

string *names3=({
"呆","dai",
"史","shi",
"慈","ci",
"偶","ou",
"胜","sheng",
"盛","sheng",
"子","zi",
"轩","xuan",
"笑","xiao",
"剑","jian",
"刀","dao",
"平","ping",
"漠","mo",
"延","yan",
"霜","shuang",
"香","xiang",
"毫","hao",
"志","zhi"
});

string *name=({"林","山","清云","君仪"});
string *name1=({
"赵","zhao",
"钱","qian",
"孙","sun",
"李","li",
"周","zhou",
"吴","wu",
"郑","zheng",
"王","wang"
});

void add_killer_level(object killer,int damage,int armor,int dodge)
{
	killer->add_temp("apply/damage",damage);
	killer->add_temp("apply/armor",armor);
	killer->add_temp("apply/dodge",dodge);
}

//阴癸送信任务
int set_ygjob_killer(object killer,object ob)
{

	killer->set_name("傅"+name[random(sizeof(name))],({ "jian ke","jian","ke","fu" }) );
	killer->set("combat_exp",ob->query("combat_exp")/3);	
	if(ob->query("combat_exp")<150000)
		killer->set_this_skills("low");
	else
	if(ob->query("combat_exp")<800000)
  		killer->set_this_skills("middle");
	else{		
  		killer->set_this_skills("high");
  		add_killer_level(killer,50,100,150);
  		
  	}

	set_all_skill(killer,ob->query("max_pot")/3);
	copy_hp_item(ob,killer,"gin",1,2);
	copy_hp_item(ob,killer,"kee",1,2);
	copy_hp_item(ob,killer,"sen",1,2);
    	copy_force(ob,killer,1/3);
	killer->set("last",time());
		
	killer->set("target_id",ob->query("id"));	
	killer->set("pfm_rate",90);
	
}

int set_cyjsjob_killer(object killer,object ob)
{
	int i,j;
	i=random(sizeof(names1));
	if(i%2!=0) i++;
	if(i==sizeof(names1))
		i=i-2;
	j=random(sizeof(names2));
	if(j%2!=0) j++;
	if(j==sizeof(names2))
		j=j-2;
   
	killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
	killer->set("gender", "男性" );	
	killer->set("age", 30+random(10));
	killer->set("long", "这是一个飞贼，据说他刚刚偷了本经书。\n");
	
	if(ob->query("combat_exp")<150000){
    	killer->set_this_skills("low");
    	killer->set("combat_exp",ob->query("combat_exp"));
    	copy_hp_item(ob,killer,"gin");
    	copy_hp_item(ob,killer,"kee");
    	copy_hp_item(ob,killer,"sen");
    	set_all_skill(killer,ob->query("max_pot")/3);
  }
   else
   if(ob->query("combat_exp")<500000){
    	killer->set_this_skills("middle");
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	set_all_skill(killer,ob->query("max_pot")/3);
  }
  else
   if(ob->query("combat_exp")<1000000){
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	set_all_skill(killer,ob->query("max_pot")/3);
    	killer->set("jiali",2);
    	add_killer_level(killer,50,100,150);
  }
   else{
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	set_all_skill(killer,ob->query("max_pot")/3);
    	killer->set("jiali",2);
    	add_killer_level(killer,50,100,150);
  }
                
   		copy_force(ob,killer);
   		killer->set("target_id",ob->query("id"));
   		killer->set("last",time()+600);	
   		killer->set("pfm_rate",90);
   		return 1;
	
}

int set_yunyanjob_killer(object killer,object ob)
{
	if(ob->query("combat_exp")<300000){
		killer->set_this_skills("low");
  		killer->set("combat_exp",ob->query("combat_exp")/3);
  		set_all_skill(killer,ob->query("max_pot")/3);
  		copy_hp_item(ob,killer,"kee",1,2);
  		copy_hp_item(ob,killer,"sen",1,2);
  		copy_hp_item(ob,killer,"gin",1,2);
	}
	else
	if(ob->query("combat_exp")<300000){
		killer->set_this_skills("middle");
  		killer->set("combat_exp",ob->query("combat_exp")/3);
  		set_all_skill(killer,ob->query("max_pot")/3);
  		copy_hp_item(ob,killer,"kee",1,2);
  		copy_hp_item(ob,killer,"sen",1,2);
  		copy_hp_item(ob,killer,"gin",1,2);
	}
	else{
		killer->set_this_skills("high");
  		killer->set("combat_exp",ob->query("combat_exp")/3);
  		set_all_skill(killer,ob->query("max_pot")/3);
  		copy_hp_item(ob,killer,"kee",1,2);
  		copy_hp_item(ob,killer,"sen",1,2);
  		copy_hp_item(ob,killer,"gin",1,2);
	}
	copy_force(ob,killer);
	killer->set("last",time());
	killer->set("target_id",ob->query("id"));
	killer->set("pfm_rate",95);
	return 1;
	
}

int set_xiangjob_killer(object killer,object ob)
{
	killer->set("last",time());
	killer->set("target_id",ob->query("id"));
  
	killer->set("combat_exp",ob->query("combat_exp")/3);
	if(ob->query("combat_exp")<150000)
		killer->set_this_skills("low");
   	else
	if(ob->query("combat_exp")<80000){		
		killer->set_this_skills("middle");
		copy_hp_item(ob,killer,"gin",1,2);
		copy_hp_item(ob,killer,"kee",1,2);
		copy_hp_item(ob,killer,"sen",1,2);
	}
	else{
		killer->set_this_skills("high");
		copy_hp_item(ob,killer,"gin",1,2);
		copy_hp_item(ob,killer,"kee",1,2);
		copy_hp_item(ob,killer,"sen",1,2);
		add_killer_level(killer,50,100,150);
	}
	set_all_skill(killer,ob->query("max_pot")/3);
	
  	killer->set("pfm_rate",90);
	copy_force(ob,killer);
	
	return 1;
	
}

int set_sjbptjob_killer(object killer,object ob)
{
	int i,j;
	i=random(sizeof(names1));
	if(i%2!=0) i++;
	if(i==sizeof(names1))
		i=i-2;
	j=random(sizeof(names2));
	if(j%2!=0) j++;
	if(j==sizeof(names2))
		j=j-2;
   
	killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
	killer->set("gender", "男性" );
        
	killer->set("age", 30+random(10));
	killer->set("long", "这是宋家堡的叛徒。\n");
	
	killer->set("combat_exp",ob->query("combat_exp")/3);
	if(ob->query("combat_exp")<150000)
    	killer->set_this_skills("low");
	else
	if(ob->query("combat_exp")<800000)
		killer->set_this_skills("middle");
	else
	    killer->set_this_skills("high");
	set_all_skill(killer,ob->query("max_pot")/3);
   
	copy_hp_item(ob,killer,"gin",1,2);
	copy_hp_item(ob,killer,"kee",1,2);
	copy_hp_item(ob,killer,"sen",1,2);
   
	killer->set("max_force",ob->query("max_force")/3);
	killer->set("force",ob->query("max_force"));
	killer->set("target_id",ob->query("id"));
	killer->set("last",time()+600);
	
	return 1;
	
}

int set_timejob_killer(object killer,object ob)
{
	killer->set("combat_exp",ob->query("combat_exp")/3);
	if(ob->query("combat_exp")<150000)
    	killer->set_this_skills("low");
	else
	if(ob->query("combat_exp")<800000)
    	killer->set_this_skills("middle");
	else
    	killer->set_this_skills("high");
	set_all_skill(killer,ob->query("max_pot")/3);
   
	copy_hp_item(ob,killer,"gin",1,2);
	copy_hp_item(ob,killer,"kee",1,2);
	copy_hp_item(ob,killer,"sen",1,2);
   
    	copy_force(ob,killer,1/3);
   
	killer->set("target_id",ob->query("id"));
   
	killer->set("last",time());
	killer->set("pfm_rate",85);
	return 1;
}

int set_gaolijob_killer(object killer,object ob)
{
	if(ob->query("combat_exp")<200000){
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	killer->set_this_skills("low");
    	set_all_skill(killer,ob->query("max_pot")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	killer->set("max_force",ob->query("max_force")/3);
   }
   else
   if(ob->query("combat_exp")<500000){
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	killer->set_this_skills("middle");
    	set_all_skill(killer,ob->query("max_pot")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	killer->set("max_force",ob->query("max_force")/3);
    	
   }
   else
   if(ob->query("combat_exp")<1000000){
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	killer->set_this_skills("high");
    	set_all_skill(killer,ob->query("max_pot")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	killer->set("max_force",ob->query("max_force")/3);
    	killer->set("jiali",10);
    	add_killer_level(killer,50,100,150);
   }
   else{
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	set_all_skill(killer,ob->query("max_pot")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	killer->set("max_force",ob->query("max_force")/3);
    	killer->set("jiali",2);
    	add_killer_level(killer,50,100,150);
   }
      
   killer->set("force",ob->query("max_force")/3);
   killer->set("target_id",ob->query("id"));
   killer->set("last",time()+600);
   
   killer->set("long",killer->query("long")+"据说高丽官府已经派"+ob->name()+"来杀他了。\n");
   killer->set("pfm_rate",90);
   return 1;
}

int set_dmszjob_killer(object killer,object ob)
{
	int i,j;
	i=random(sizeof(names1));
	if(i%2!=0) i++;
	if(i==sizeof(names1))
		i=i-2;
	j=random(sizeof(names2));
	if(j%2!=0) j++;
	if(j==sizeof(names2))
		j=j-2;
   
	killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
	killer->set("gender", "男性" );
        
	killer->set("age", 30+random(10));
	killer->set("nickname","护卫");
	killer->set("long", "这是一个受雇于兵器店的护卫。\n");
	
	if(ob->query("combat_exp")<500000){
		killer->set_this_skills("middle");	
		killer->set("combat_exp",ob->query("combat_exp")/3);
		set_all_skill(killer,ob->query("max_pot")/3);
     	copy_hp_item(ob,killer,"gin");
     	copy_hp_item(ob,killer,"kee");
     	copy_hp_item(ob,killer,"sen");
   }
   else
   if(ob->query("combat_exp")<1000000){
     	killer->set_this_skills("high");	
     	killer->set("combat_exp",ob->query("combat_exp")/3);
     	set_all_skill(killer,ob->query("max_pot")/3);
     	copy_hp_item(ob,killer,"gin",3,2);
     	copy_hp_item(ob,killer,"kee",3,2);
     	copy_hp_item(ob,killer,"sen",3,2);
     	killer->set("jiali",10);
     	add_killer_level(killer,50,100,150);
   }
   else{
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	killer->set_this_skills("high");
    	set_all_skill(killer,ob->query("max_pot")/3);
    	copy_hp_item(ob,killer,"gin",3,2);
    	copy_hp_item(ob,killer,"kee",2);
    	copy_hp_item(ob,killer,"sen",3,2);
    	killer->set("jiali",3);
        add_killer_level(killer,50,100,150);	
   }
  
	killer->set("max_pot",ob->query("max_pot")/3);
  
    killer->set("force",killer->query("force")/3);
	killer->set("target_id",ob->query("id"));
	killer->set_temp("apply/armor",10+random(10));
	killer->set("last",time());
	killer->set("pfm_rate",85);
	return 1;
	
}

int set_tjjyjob_killer(object killer,object ob)
{
	int i;
   
   	i=random(sizeof(name1));
   
   	if(i%2!=0)
   		i++;
   	if(i==sizeof(name1))
   		i=i-2;
   	killer->set_name(name1[i]+"侠客",({name1[i+1]+" "+"xiake",name1[i+1]}) );
   	
   	if(ob->query("combat_exp")<150000){
    	killer->set_this_skills("low");
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	set_all_skill(killer,ob->query("max_pot")/3);
        copy_hp_item(ob,killer,"gin",1,2);
        copy_hp_item(ob,killer,"kee",1,2);
        copy_hp_item(ob,killer,"sen",1,2);
    	copy_force(ob,killer,1/3);
   	}
   	else
   	if(ob->query("combat_exp")<500000){
    	killer->set_this_skills("middle");
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	set_all_skill(killer,ob->query("max_pot")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	copy_force(ob,killer,1/3);
    	
   	}
   	else
   	if(ob->query("combat_exp")<1000000){
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	set_all_skill(killer,ob->query("max_pot")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	copy_force(ob,killer,1/3);
    	killer->set("jiali",10);
    	add_killer_level(killer,50,100,150);
   	}
   	else{
    	killer->set_this_skills("high");
    	killer->set("combat_exp",ob->query("combat_exp")/3);
    	set_all_skill(killer,ob->query("max_pot")/3);
    	copy_hp_item(ob,killer,"gin",1,2);
    	copy_hp_item(ob,killer,"kee",1,2);
    	copy_hp_item(ob,killer,"sen",1,2);
    	copy_force(ob,killer,1/3);
    	killer->set("jiali",10);    	
    	add_killer_level(killer,50,100,150);
  	}
      
   	killer->set("target_id",ob->query("id"));
   	killer->set("last",time());
   	killer->set("pfm_rate",75);
   	return 1;
	
}

int set_butoujob_killer(object killer,object ob)
{
	int i,j,k,flag;
	int exp;
   
   	flag=0;
   
   	if(random(10)<6){
    	i=random(sizeof(names1));
    	if(i%2!=0)
     		i++;
    	if(i==sizeof(names1))
     		i=i-2;
    	j=random(sizeof(names2));
    	if(j%2!=0)
     		j++;
    	if(j==sizeof(names2))
     		j -=2;
   	}
   	else{
     	i=random(sizeof(names1));
    	if(i%2!=0)
     		i++;
    	if(i==sizeof(names1))
     		i -=2;
    	j=random(sizeof(names2));
    	if(j%2!=0)
     		j++;
    	if(j==sizeof(names2))
     		j -=2;
   	 	k=random(sizeof(names3));
    	if(k%2!=0)
     		k++;
    	if(k==sizeof(names3))
     		k -=2;
    	flag=1;
	}
    
   	if(!flag)
   		killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
   	else
   		killer->set_name(names1[i]+names2[j]+names3[k],({names1[i+1]+" "+names2[j+1]+" "+names3[k+1],
         	names1[i+1],names2[j+1],names3[k+1]}) );
	

    
    exp=random(3000000);
    
    killer->set("combat_exp",exp/3);
    "/cmds/usr/hp.c"->get_pot(killer);
    
    if(exp<100000)
     	killer->set_this_skills("lowe");
    else
    if(exp<600000)
     	killer->set_this_skills("middle");
    else
     	killer->set_this_skills("high");
    
    set_all_skill(killer,killer->query("max_pot")/3);
    
    killer->set("max_kee",killer->query("max_kee")/3);
    killer->set("eff_kee",killer->query("eff_kee")/3);
    killer->set("kee",killer->query("kee")/3);
    
    killer->set("max_gin",killer->query("max_gin")/3);
    killer->set("eff_gin",killer->query("eff_gin")/3);
    killer->set("gin",killer->query("gin")/3);
    
    killer->set("max_sen",killer->query("max_sen")/3);
    killer->set("eff_sen",killer->query("eff_sen")/3);
    killer->set("sen",killer->query("sen")/3);
    
    killer->set("max_force",killer->query("max_force")/3);
    killer->set("force",killer->query("force")/3);
    killer->set("pfm_rate",80);
    return 1;
	
}

int set_bsyquest_killer(object killer,object ob,int lev)
{
	int i,j;
	i=random(sizeof(names1));
	if(i%2!=0) i++;
	if(i==sizeof(names1))
		i=i-2;
	j=random(sizeof(names2));
	if(j%2!=0) j++;
	if(j==sizeof(names2))
		j=j-2;
   
	killer->set_name(names1[i]+names2[j],({names1[i+1]+" "+names2[j+1],names1[i+1],names2[j+1]}) );
	killer->set("gender", "男性" );
        
	killer->set("age", 30+random(10));
	killer->set("long", "这是一名杀手。\n");
	
    killer->set("combat_exp",ob->query("combat_exp")/3);
    killer->set_this_skills("high");
    set_all_skill(killer,ob->query("max_pot")/3);
    copy_hp_item(ob,killer,"gin",1,2);
    copy_hp_item(ob,killer,"kee",1,2);
    copy_hp_item(ob,killer,"sen",1,2);
    killer->set("jiali",1);
    
    killer->set("force",killer->query("force")/3);
	killer->set("target_id",ob->query("id"));
	killer->set_temp("apply/armor",10+random(10));
	
	return 1;
	
}
