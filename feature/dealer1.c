// 当铺npc
//for dtsl
//by yanyan

#include <dbase.h>
#include <ansi.h>

#define EVENT_D "/obj/event.c"
/*
int query_goods_value(object goods, string method)
{
        object me = this_player();
        int value, trade_level;

        value = goods->query("value");        
        
        trade_level = me->query_skill("trade", 1);
        if(trade_level>300)
        	trade_level = 300;
        if(trade_level<=0)
        	trade_level = 1;

        if (method == "buy")
                value = value-value*trade_level/(1200);
        else if (method == "sell" || method == "value")
                value = value *trade_level / (400);
        
        value=EVENT_D->get_trade_value(goods,value);      
        
        return value;
}
*/
int query_goods_value(object goods, string method)
{
        object me = this_player();
        int value, trade_level;

        value = goods->query("value");
        trade_level = me->query_skill("trade", 1) / 5;
        if (trade_level > 40) trade_level = 40;
        if (method == "buy")
                value = value * (140 - trade_level) / 100;
        else if (method == "sell" || method == "value")
                value = value * (50 + trade_level) / 100;
        return value;
}
string is_vendor_good(string arg)
{
        string *goods;
        int i;

        if (arrayp(goods = query("vendor_goods"))) 
                for (i = 0; i < sizeof(goods); i++) 
                        if (goods[i]->id(arg)) return goods[i];
        return "";
}

int do_value(string arg)
{
        object ob;
        int value;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要估什么价？\n");

        if (ob->query("money_id"))
                return notify_fail("你没用过钱啊？\n");

        value = query_goods_value(ob, "value");
        if (value < 30)
                write(ob->name() + "一文不值！\n");
        else 
                write(ob->name() + "值" + MONEY_D->price_str(value) + "。\n");
        return 1;
}

int do_sell(string arg)
{
        object ob;
        object me = this_player();
        int value, value1, improve;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
        if (!arg || !(ob = present(arg, me)))
                return notify_fail("你要卖什么？\n");

        if (ob->query("money_id"))
                return notify_fail("你想卖「钱」？\n");

        if (ob->query("no_drop") || ob->query("no_get"))
                return notify_fail("这样东西我买了怕卖不掉。\n");

        if (ob->query("unique"))
                return notify_fail("这样的宝物我可买不起。\n");

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

        if (is_vendor_good(arg) != "") 
                return notify_fail("我卖给你好不好？\n");

        if (ob->query("food_supply"))
                return notify_fail("剩菜剩饭留给您自己用吧。\n");
        if(ob->query("super")||ob->query("rumor"))
        return notify_fail("这样的东西我们这里可不敢买。\n");  
        if(ob->query("no_drop")||ob->query("no_get")||ob->query("no_steal"))
        return notify_fail("这个东西不能卖。\n");        
        value = ob->query("value");
        value1 = query_goods_value(ob, "sell");
        if (value < 30)
                write(ob->name() + "一文不值！\n");
        else if (value >= 500000)
                write(ob->name() + "我们可买不起。\n");
        else {
         if (value < 200 || ob->query_amount()) {
                        message_vision("$N卖掉了一" + ob->query("unit") + 
                                ob->name() + "给$n。\n", me, this_object());
                        message_vision("$N把$n随手一扔，说道：这么个不值钱的玩意也拿来当。\n",
                                this_object(), ob);
                        destruct(ob);
                } else {
                        if (ob->move(this_object())) {
                                message_vision("$N以"+MONEY_D->money_str(value1)+"的价格卖掉了一" + ob->query("unit") + 
                                        ob->name() + "给$n。\n", me, this_object());
                                if(ob->query("weapon_prop"))
                ob->set("type","weapon");
               else
               if(ob->query("armor_prop"))
                ob->set("type","armor");
               else
               if(ob->query("weapon"))
                ob->set("type","iron");
               else
               if(ob->query("heal_up"))
                ob->set("type","medicine");
               else
                ob->set("type","other");
               ob->set("no_get",1);
               ob->set("no_drop",1);
               ob->set("no_steal",1);
                        }
                        else return notify_fail("我这货物已经太多了，暂时停止收购。\n");
                }
                MONEY_D->pay_player(me, value1);
               if(me->query_skill("trade",1)<300)
               	me->improve_skill("trade",random(me->query("kar")*2));
        }
        return 1;
}
string no_color(string arg)
{
        arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}

string left(string str,int long)
{
	int space,len,i;
	string s,oldstr;
	s="";oldstr=str;
	str=no_color(str);
	len=strlen(str);
	space=(long-len);
	for(i=0;i<space;i++) s+=" ";
	return sprintf("%s%s",oldstr,s);
}  
  
int do_list(string arg)
{
        object *inv;
     int i;
     string msg;
     
     if(!arg||
         (arg!="weapon"&&arg!="armor"&&arg!="iron"&&
          arg!="medicine"&&arg!="other"))
     return notify_fail("你要看哪类物品？\n"+
     "兵器[weapon]、盔甲[armor]、矿石[iron]、药物[medicine]、其他[other]。\n\n");
     msg="";
     inv=all_inventory();
     i=sizeof(inv);
     for(i=0;i<sizeof(inv);i++)
      if(inv[i]->query("type")==arg){
        msg+=left(inv[i]->name()+"("+inv[i]->query("id")+")",50);
        msg+=MONEY_D->price_str(query_goods_value(inv[i], "buy") * 2);
        msg+="\n";}
     if(sizeof(msg)<=0)
     return notify_fail("目前没有这种类型的物品出售。\n");
     msg="━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"+msg;
     msg+="━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
     this_player()->start_more(msg);
     return 1;
}

int do_buy(string arg)
{
        int i, val_factor = 5, improve;
        string ob_file;
        object *inv;
        object ob;
        object me = this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

        if (!arg) return notify_fail("你想买什么？\n");
        inv = all_inventory();
        i = sizeof(inv);
        if (i)
                while (i--) if (inv[i]==present(arg,this_object())
                 && inv[i]->query("no_get")) 
                 { ob = inv[i]; val_factor = 10; break; }

        if (!ob)
           return notify_fail("你想买的东西我这里没有。\n");
       
        switch (MONEY_D->player_pay(me, query_goods_value(ob, "buy") *  val_factor )) {
                case 0:
                        if (val_factor == 5) destruct(ob);
                        return notify_fail("穷光蛋，一边呆着去！\n");
                case 2:
                        if (val_factor == 5) destruct(ob);
                        return notify_fail("您的零钱不够了，银票又没人找得开。\n");
                default:
                        if (!ob->move(me)) {
                                if (val_factor == 5) destruct(ob);
                                return 0;
                        }
                        ob->delete("no_get");
                        ob->delete("no_drop");
                        ob->delete("no_steal");
                        ob->delete("type");
                        message_vision("$N从$n那里买下了一" + ob->query("unit") +
                                ob->name() + "。\n", me, this_object());
                       if(me->query_skill("trade",1)<300)
               						me->improve_skill("trade",random(me->query("kar")*2));
        }
        me->start_busy(1);
        return 1;
}
