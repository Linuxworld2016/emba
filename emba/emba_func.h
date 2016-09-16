#ifndef __EMBA_FUNC__
#define __EMBA_FUNC__

#include "emba_log.h"

#define emba_malloc(len) malloc(len); \
	emba_log_print(EMBA_LOG_DEBUG ,"malloc.Line:%d-file:%s\n" ,__LINE__ ,__FILE__);

#define emba_free(ptr)	free(ptr);ptr = NULL; emba_log_print(EMBA_LOG_DEBUG ,"free.Line:%d-file:%s\n" ,__LINE__ ,__FILE__);

#endif
