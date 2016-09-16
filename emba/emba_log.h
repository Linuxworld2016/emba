#ifndef __EMBA_LOG__
#define __EMBA_LOG__

#include "emba_sys.h"

#define EMBA_LOG_WARN		0
#define EMBA_LOG_DEBUG		1
#define EMBA_LOG_INFO		2
#define EMBA_LOG_ERROR		3
#define EMBA_LOG_SUCCESS	4

int emba_log_init(void);
int emba_log_print(int level ,char *msg ,...);
int emba_log_exit(void);

#endif
