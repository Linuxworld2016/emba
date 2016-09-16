#include "emba_log.h"
int emba_log_fd = 0;

int emba_log_init(void)
{
	emba_log_fd = open("emba_log.0" ,O_RDWR|O_CREAT|O_APPEND ,0644);
	if(emba_log_fd < 0){
		fprintf(stderr ,"open [emba_log.0] failed.erro:[%s]\n" ,strerror(errno));
	}
	return 0;
}

int emba_log_print(int level ,char *msg ,...)
{
	int n;
	va_list args;
	char emba_buf[1024] = {0};

	va_start(args, msg);
	n = vsprintf(emba_buf, msg, args);
	va_end(args);

	if(level > EMBA_LOG_DEBUG){
		write(2 ,emba_buf ,strlen(emba_buf));
	}
//	write(emba_log_fd ,emba_buf ,strlen(emba_buf));
	return 0;
}
int emba_log_exit(void)
{
	if(emba_log_fd > 0){
		close(emba_log_fd);
	}
	return 0;
}
