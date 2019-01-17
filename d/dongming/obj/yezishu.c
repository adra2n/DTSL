
 
inherit ITEM;

void create()
{
   set_name("椰子树", ({"yezi shu","shu","tree"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一棵椰子树，上面长了很多椰子，\n"+
                            "或许摇几下能摇下来吧！\n");
                set("unit", "棵");
                set("yezi",200);
               
        }
}

int is_get_of(object ob,object obj)
{
  return notify_fail("\n只听有人喊道："+ob->name()+"偷椰子树了！大家快来看啊～～～～\n"+
                     ob->name()+"脸一红，连忙咳嗽两声，装做没有事情的样子。\n");
}                

void init()
{
  add_action("do_action1","yao");
  
}

int do_action1()
{
    object ob,obj;
    
    ob=this_player();
    
    if(ob->is_busy())
    return notify_fail("你正忙着呢！\n");
    ob->start_busy(3);
    
    if(random(query("yezi"))<100)
    return notify_fail("你摇了半天，发现什么也没有！\n");
    add("yezi",20);
    obj=new(__DIR__"yezi");
    obj->move(environment(ob));
    message_vision("\n只听乓的一声，一个椰子砸在了$N的头上！！\n",ob);
    return 1;
}