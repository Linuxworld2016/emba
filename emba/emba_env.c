#include "emba_env.h"

int emba_get_libsname(char *emba_libs ,emba_list **head)
{
	DIR *emba_pdir = NULL;  
	struct dirent *emba_entry = NULL;  
	emba_list *node = NULL;

	emba_pdir = opendir(emba_libs);
	if(!emba_pdir){
		emba_log_print(EMBA_LOG_DEBUG ,"opendir failed.error msg:[%s]\n" ,strerror(errno));
		return -1;
	}

	while((emba_entry = readdir(emba_pdir))){
		node = emba_list_push(head);
		if(!node){
			emba_log_print(EMBA_LOG_INFO ,"node list init failed\n");
			break;
		}
		node->data = emba_malloc(strlen(emba_entry->d_name)+1);
		if(!(node->data)){
			emba_log_print(EMBA_LOG_INFO ,"node data malloc failed\n");
			break;
		}
		memset(node->data ,0x00 ,strlen(emba_entry->d_name)+1);
		memcpy(node->data ,emba_entry->d_name ,strlen(emba_entry->d_name));
		emba_log_print(EMBA_LOG_INFO ,"file:[%s]\n" ,node->data);
	}
	closedir(emba_pdir);
	return 0;
}

void emba_show_libsname(emba_list *head)
{
	emba_list *cur = head;
	while(cur && cur->data){
                emba_log_print(EMBA_LOG_INFO ,"test list:[%s]\n" ,cur->data);
                cur = cur->next;
        }
}

int emba_init_libs(emba_list **head)
{
	struct module_t *node_mt = NULL;
	emba_list *node_list = *head;
	void *handle = NULL;	
			
	while(node_list && node_list->data){
		node_mt = emba_malloc(sizeof(struct module_t));
		if(!node_mt){
			emba_log_print(EMBA_LOG_INFO ,"module_t malloc failed\n");
			goto out;
		}

		handle = dlopen(node_list->data ,RTLD_LAZY);
		if(!handle){
			emba_log_print(EMBA_LOG_INFO ,"dlopen[%s] failed\n" ,node_list->data);
			goto out;
		}

		node_mt->mht.init = dlsym(handle, "init");
		node_mt->mht.comu = dlsym(handle, "comu");
		node_mt->mht.work = dlsym(handle, "work");
		node_mt->mht.exit = dlsym(handle, "exit");
		
		if(node_list->data){
			emba_free(node_list->data);
		}

		node_list->data = node_mt;
	out:
		node_list = node_list->next;
	}
	return 0;	
}
