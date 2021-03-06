//skill.c
//datang-shuanglong
inherit F_CLEAN_UP;

void create()
{
   seteuid(getuid());
}

//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill.

int valid_learn(object me) { return 1; }

int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
   return 1;
}

// 
// type()
//
// This function should return the type of the skill. The skill type now
// affects if the skill requires combat exp in order to be learned (see
// /cmds/std/learn.c ) and the ranking of a skill level (see 
// /cmds/usr/skills.c )。
// Currently we have only 2 types of skill: "martial" and "knowledge".

string type() { return "martial"; }

//
// skill_improved()
//
// This function is called when a character's skill has gained a new level.
// You can make some modify to a character according to the skill.

void skill_improved(object me) {}

//
// exert_function()
//
//     This function is used by the "exert" command as specific skill's 
// command parser. This function parses the arguments in the standard form
// (that is, exert <function> [<target>]). When <target> is not present,
// use the character himself as default.
//     In order to use this default exert command parser, you must define
// a function called exert_function_file(string func) in the skill object
// that takes the function name as argument and return the file name that
// defines the specified function. 

int exert_function(object me, string arg)
{
   string func, target, file;
   object target_ob;

   if( sscanf(arg, "%s %s", func, target)==2 ) {
     target_ob = present(target, environment(me));
     if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
   } else {
     func = arg;
     target_ob = me;
   }

   if( !stringp(file = (string)this_object()->exert_function_file(func))
   ||   file_size(file + ".c") <= 0 )
     return 0;

   return (int)call_other( file, "exert", me, target_ob);
}

int perform_action(object me, string arg)
{
   string action,file,victim;
   object target,*enemys;
   
   if( sscanf(arg, "%s %s", action, victim)==2 )
   {
        target=present(victim,environment(me));
      	if(!objectp(target)) return notify_fail("这里没有"+victim+"!\n");
	if(me->is_fighting()&&!me->is_fighting(target))
        return notify_fail("这不是你正在战斗的目标！\n");
   }
   else
   {
     target=me->select_opponent();
     action=arg;
   }
   if( !stringp(file = (string)this_object()->perform_action_file(action)))
	   return 0;
      if(file_size(file + ".c") <= 0 )
     return notify_fail("武功文件出了问题，请报告巫师!\n");

   return (int)call_other( file, "perform", me, target);
}

int execute_action(object me, string arg)
{
   string action,file,victim;
   object target;
   if( sscanf(arg, "%s %s", action, victim)==2 )
   {
        target=present(victim,environment(me));
      	if(!objectp(target)) return notify_fail("这里没有"+victim+"!\n");
	if(!me->is_fighting(target))
        return notify_fail("这不是你正在战斗的目标！\n");
   }
   else{
   target=me;   	  
   action=arg;
   }
   
   if( !stringp(file = (string)this_object()->execute_action_file(action)))
	   return 0;
      if(file_size(file + ".c") <= 0 )
     return notify_fail("心法文件出了问题，请报告巫师!\n");

   return (int)call_other( file, "execute", me, target);
}
// The following two functions are used to modify the random function
// for shaolin wugong.

int sum(int n,int base,int d)
{
  return (n*(2*base+(n-1)*d)/2);
}

int NewRandom(int n,int base,int d)
{
  int i = 1;
  int randnum = random(sum(n,base,d));

  if (sum(6,base,d) < randnum)
   {
    i = 7;
    while (sum(i,base,d) < randnum)
          i++;
    }
  else {
    while (sum(i,base,d) < randnum)
        i++;
   }
  return (i-1);
}

