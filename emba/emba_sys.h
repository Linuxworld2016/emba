#ifndef __MY_COMMON_HEADER__
#define __MY_COMMON_HEADER__

//base header file
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <stdarg.h>

#include <errno.h>

//dir op
#include <dirent.h>

//process
#include <sys/wait.h>

//thread
#include <pthread.h>

//dynamic library
#include <dlfcn.h>

//network header file
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <sys/select.h>
#include <sys/mman.h>
#include <arpa/inet.h>

//system call
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

//time
#include <sys/time.h>
#endif
