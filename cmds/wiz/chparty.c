
string help()
{
  return "使用这个命令可以让你改变自己
  的门派，如 chparty 宋家堡.
  使用chorg none 则不成为任何门派的成员。
  \n";
}

int main(object ob,string arg)
{
  
  if(!arg){
  tell_object(ob,help());
  return 1;}
  if(arg=="none"){
  ob->delete("family");
  tell_object(ob,"不加入任何门派.\n");
  return 1;}
  ob->set("family/family_name",arg);
  tell_object(ob,"门派更改完毕。\n");
  return 1;
   
}

