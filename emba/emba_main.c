#include "emba_env.h"
#include "emba_log.h"
#include "emba_list.h"

int main(int argc ,char **argv)
{
	pid_t pid;
	int status;
	
	emba_list *head = NULL ,*cur = NULL;
	
	head = emba_list_init();
	if(!head){
		printf("emba_list_init failed\n");
		return -1;
	}
	emba_get_libsname("test" ,&head);
	emba_show_libsname(head);

	emba_init_libs(&head);
	cur = head;
start_module:
	//start
	pid = fork();
	if(pid < 0){
		printf("fork failed.\n");
	}else if(!pid){
		if(cur->data){
			printf("child pid:[%d]-file(%s)\n" ,getpid() ,(char *)(cur->data));
		}
		sleep(20);
	}else{
		if(cur && cur->data){
			cur = cur->next;
			goto start_module;
		}
		printf("parent pud:[%d]-child pid:[%d]\n" ,getpid() ,pid);
	}

	while((pid = wait(&status)) > 0 ) { 
		printf("pid = %d\n", pid);
	} 

	return 0;
}
