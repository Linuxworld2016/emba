C=gcc
Master=emba_agent
CFLAGS= -Wall -g -DLINUX -L./libs
LDFLAGS= -lpthread -ldl 

mobjs = emba_main.o emba_env.o emba_log.o emba_list.o 

all: $(Master)

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<
$(Master): $(mobjs)
	$(CC) $(mobjs) $(LDFLAGS) -o $@  
clean:
	rm -f *.o $(Master) 
