#include "include/apue.h"
#include "lib/error.c"
#ifdef SOLARIS
#define PSCMD "ps -a -o pid,ppid,s,tty,comm"
#else
#define PSCMD "ps -o pid,ppid,state,tty,command"
#endif

int main(void)
{
    pid_t pid;
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0) /* child */
        exit(0);
    /* parent */
    sleep(5);
    system(PSCMD);
    exit(0);
}
