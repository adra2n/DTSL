#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob,env;
        string pla, here;
	if( environment(me)->query("no_rideto")||
	 environment(me)->query("no_quit") )
		return notify_fail("这里天神不会理你。\n");
        

                
        if (! arg)
                return notify_fail("你要去哪里？\n");
        if (me->is_fighting())
                return notify_fail("你现在正在和人家动手， 天神不会理你。\n");
      
        if(me->query_temp("dtsl_job"))
                return notify_fail("你现在做任务， 天神不会理你。\n");
	if( me->is_ghost() )
		return notify_fail("做了鬼了，就老实点吧！\n");
       if (me->query_temp("quest_biao"))
                return notify_fail("好好运镖,别乱跑.\n");

           env = environment(me); 

       if (file_name(env)[0..5] == "/d/pk/") 
                return notify_fail("这里不能召唤天神！\n");        

        if (me->is_busy())
                return notify_fail("你上一个动作还没有完成，先等等吧。\n");

          else {
          message_vision(HIY
"$N大喝一声“天神，HELP”，天神出现在一阵烟雾中，用手一指,顿时$N消失在空气中！\n"NOR, me);
}
          if(arg=="yz") pla = "/d/yangzhou/hotel";
     else if(arg=="baling") pla = "/d/baling/kezhan";
     else if(arg=="changan") pla = "/d/changan/guangchang";
     else if(arg=="haisha") pla = "/d/haisha/cunxi";
     else if(arg=="changbaishan") pla = "/d/changbaishan/tianchi";
     else if(arg=="chanyuan") pla = "/d/chanyuan/miaodoor";
     else if(arg=="chengdu") pla = "/d/chengdu/kedian";
     else if(arg=="dabashan") pla = "/d/dabashan/shanjiao";
     else if(arg=="dajianglian") pla = "/d/dajianglian/mumen";
     else if(arg=="dingxiang") pla = "/d/dingxiang/kezhan.c";
     else if(arg=="dongming") pla = "/d/dongming/pinglu";
     else if(arg=="emeishan") pla = "/d/emeishan/liangting";
     else if(arg=="chatroom") pla = "/u/kouzhong/chatroom";
     else if(arg=="feima") pla = "/d/feima-muchang/door";
     else if(arg=="gaoli") pla = "/d/gaoli/qinglongmen";
     else if(arg=="haisha") pla = "/d/haisha/cunxi";
     else if(arg=="hangzhou") pla = "/d/hangzhou/center";
     else if(arg=="hefei") pla = "/d/hefei/ximen";
     else if(arg=="hengshan") pla = "/d/hengshan/beiyuedian";
     else if(arg=="huashan") pla = "/d/huashan/shanlu1";
     else if(arg=="jingzhai") pla = "/d/jingzhai/door";
     else if(arg=="jiujiang") pla = "/d/jiujiang/ximen";
     else if(arg=="leshou") pla = "/d/leshou/ximen";
     else if(arg=="lingnan") pla = "/d/lingnan/wuchang";
     else if(arg=="mayi") pla = "/d/mayi/beimen";
     else if(arg=="luoyang") pla = "/d/luoyang/kedian";
     else if(arg=="pengliang") pla = "/d/pengliang/kezhan";
     else if(arg=="taiyuan") pla = "/d/taiyuan/beimen";
     else if(arg=="xiangyang") pla = "/d/xiangyang/nanmen";
     else if(arg=="xucheng") pla = "/d/xucheng/ximen";
     else if(arg=="yinkui") pla = "/d/yinkui/door";
     else if(arg=="yuyang") pla = "/d/yuyang/guangchang";
             else {
               message_vision(HIR
"天神怒道：根本没有这个地方，你到底要去哪里?\n"NOR, me);
}
       me->move(pla);
     return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : milu <地点>
这个指令可以到达某个地点.
可以到达的地点有：
聊天室<chatroom> 

扬    州<yz>         巴    岭<baling>      洛    阳<luoyang>    渔    阳<yuyang>   
阴 癸 派<yinkui>     许    城<xucheng>     太    原<taiyuan>    彭    凉<pengliang>   
马    邑<mayi>       宋    家<lingnan>     乐    寿<leshou>     九    江<jiujiang>  
慈航静斋<jingzhai>   华    山<huashan>     衡    山<hengshan>   合    肥<hefei>      
杭    州<hangzhou>   高    丽<gaoli>       飞马牧场<feima>      峨    嵋<emeishan>
东 溟 派<dongming>   东 突 厥<dingxiang>   长    安<changan>    长 白 山<changbaishan>
净念禅院<chanyuan>   成    都<chengdu>     大 巴 山<dabashan>   大 江 联<dajianglian>
襄  阳<xiangyang>  
 
HELP
    );
    return 1;
}


