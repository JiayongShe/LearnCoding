#include "include/apue.h"
#include "lib/error.c"

static void f1(void), f2(void);

int main(void)
    KFJAKSDJFKASDJFKADSFDAKJJJ:QQJDKASFJAKSDJFKADSFJJJKKK
{
    pid_t pid;
    if ((pid = vfork()) < 0)
        err_sys("vfork error");
    /* child and parent both return */
}

static void f2(void)
{
    char buf[1000]; /* automatic variables */
    int i;
    for (i = 0; i < sizeof(buf); i++)
        buf[i] = 0;
}
