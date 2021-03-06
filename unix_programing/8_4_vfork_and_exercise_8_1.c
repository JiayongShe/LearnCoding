#include "include/apue.h"
#include "lib/error.c"

int globvar = 6; /* external variable in initialized data */

int
main(void)
{
    int var; /* automatic variable on the stack */
    pid_t pid;
    var = 88;
    printf("before vfork\n"); /* we don’t flush stdio */
    if ((pid = vfork()) < 0) {
//    if ((pid = fork()) < 0) {
        err_sys("vfork error");
    } else if (pid == 0) { /* child */
        globvar++; /* modify parent’s variables */
        var++;
//        _exit(0); /* child terminates */
        exit(0); /* child terminates */
    }
    /* parent continues here */
//    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    int i = 0;
    char buf[64];
    i = printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    sprintf(buf, "%d\n", i);
    write(STDOUT_FILENO, buf, strlen(buf));

    exit(0);
}
