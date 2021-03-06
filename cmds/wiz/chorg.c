



string help()
{
  return "使用这个命令可以让你改变自己
  的帮会，如 chorg 天策府.
  使用chorg none 则不成为任何帮会的成员。
  
  目前的帮会有:
  
  天策府
  飞马牧场
  独尊堡
  大江联
  宋家堡
  海杀帮
  
  注意：在改变帮会之后，不要被PK，否则你所在
  的帮会会掉经验的。\n";
}
string convert(string arg)
{
   switch(arg){
   
   case "天策府": return "lifa_b";
   case "飞马牧场": return "feima_b";
   case "独尊堡": return "duzun_b";
   case "大江联": return "dajiang_b";
   case "宋家堡": return "songjia_b";
   case "海杀帮": return "haisha_b";
   default: return "none";}
}

int main(object ob,string arg)
{
  
  string org;
  if(!arg){
  tell_object(ob,help());
  return 1;}
  if(arg=="none"){
  ob->delete("shili");
  tell_object(ob,"你现在没有成为任何帮会的成员。\n");
  return 1;}
  org=convert(arg);
  if(org=="none"){
  tell_object(ob,help());
  return 1;}
  ob->set("shili/name",org);
  tell_object(ob,"帮会更改完毕。\n");
  return 1;
   
}

