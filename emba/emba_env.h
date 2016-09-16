#ifndef __EMBA_ENV__
#define __EMBA_ENV__
#include "emba_list.h"

struct module_info_t{
    int fd;
    unsigned int pid;
    int type;
    char *name;
    char *path;
    int version;
    int status;
};

struct module_handle_t{
    int (*init)(struct module_info_t *mit);
    int (*comu)(struct module_info_t *mit);
    int (*work)(struct module_info_t *mit);
    int (*exit)(struct module_info_t *mit);
};

struct module_t{
	struct module_info_t mit;
	struct module_handle_t mht;
	struct module_t *next;
};

int emba_get_libsname(char *emba_libs ,emba_list **head);
void emba_show_libsname(emba_list *head);
int emba_init_libs(emba_list **head);
#endif
