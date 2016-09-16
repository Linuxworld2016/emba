#include "emba_list.h"

emba_list *emba_list_init()
{
	emba_list *head = emba_malloc(sizeof(emba_list));
	
	head->data = NULL;
	head ->prev = NULL;
	head->next = NULL;

	return head;
}

emba_list *emba_list_push(emba_list **head)
{
	emba_list *node;
	
	node = emba_list_init();
	if(!node){
		emba_log_print(EMBA_LOG_DEBUG ,"%s:%d:%s list init failed\n" ,__FILE__ ,__LINE__ ,__FUNCTION__);
		goto out;
	}

	node->next = *head;
	node->prev = NULL;
	(*head)->prev = node;
	*head = node;
out:
	return node;
}

