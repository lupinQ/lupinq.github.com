#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
void new_op(int);
int main(int argc,char**argv)
{   
    int sig,pid;
    union sigval bug;
    bug.sival_int=0;
   // bug.sival_ptr=NULL;
    
    sig=atoi(argv[1]);
    pid=atoi(argv[2]);
    
    while(1){
    if(sigqueue(pid,sig,bug) < 0)
        printf("seng sigal error\n");
	new_op(sig);
    
    }
	return 0;
}
void new_op(int sig)
{
    printf("send signal %d\n", sig);
    sleep(10);
}
