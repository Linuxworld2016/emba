#ifndef __EMBA_LIST__
#define __EMBA_LIST__

#include "emba_basic.h"
#include "emba_func.h"

typedef struct emba_list_t emba_list;
struct emba_list_t{
	void *data;
	emba_list *prev;
	emba_list *next;	
};

emba_list *emba_list_init(void);
emba_list *emba_list_push(emba_list **head);
void emba_list_free(emba_list *head);

#endif
