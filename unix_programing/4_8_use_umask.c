#include "include/apue.h"
#include "lib/error.c"
#include <fcntl.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
int
main(void)
{
    umask(0);
    if (creat("foo", RWRWRW) < 0)
        err_sys("creat error for foo");
    //sleep(100);
    mode_t i = umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    printf("%d\n", i);
    if (creat("bar", RWRWRW) < 0)
        err_sys("creat error for bar");
    exit(0);
}
