
inherit NPC;

string *name1=({
"��","��","��","��","��","Ǯ","��","��","��","��","ŷ��"});
string *name2=({
"һ","��","��","��","��","��","��","��","��","��","��","��","��","��"});
string *id1=({
"ma","liu","chen","li","zhao","qian","sun","zhou","wu","wang","ouyang"});
string *id2=({
"yi","er","si","liu","ba","san","wu","feng","yu","lei","lang","wei","min","ji"});

string *gender=({"����","Ů��"});

void create()
{
   
   int i,j;
   
   i=random(10);
   j=random(10);
   
   set_name(name1[i]+name2[j],({id1[i]+" "+id2[j],id1[i],id2[j]}) );
        set("gender",gender[random(sizeof(gender))]);
        set("age",30+random(10));
   set("long", "����һλ�����ɵ�����ʹ�ߡ�\n"); 
   set("targt_id","####");
   setup();
  
}


//�����ά�� 300 ��
int clear()
{
  if(time()-query("last")<300) {
  call_out("clear",10);
  return 0;
  }
  if(!query("no_msg")){
  message_vision("$N�Ҵ����ˡ�\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
   
   if(clear())
   return 1;
   
   return ::chat();
}

int accept_fight(object who)
{
  return 0;
}

void kill_ob(object ob)
{
   ob->remove_killer(this_object());
   command("grin "+ob->query("id"));
  
   return;
}

int set_status(object ob)
{
   set("long",query("long")+"��˵�������Ѿ���"+ob->name()+"�����������ˡ�\n");
   set("last",time());
   set("target_id","####");
  call_out("clear",1);
   return 1;
}