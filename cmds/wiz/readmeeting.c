inherit F_CLEAN_UP;
int main(object me)
{
	me->start_more( read_file("/log/meeting"));
	return 1;
}
int help(object me)
{
	write(@HELP
这个指令让你看最近的会议纪录。
HELP
	);
	return 1;
}

