#include "include/apue.h"
#include "lib/error.c"
#include "lib/pathalloc.c"
int
main(void)
{
    char *ptr;
    size_t size;
    printf("initial size = %d\n", size);
    size_t *psize = NULL;
    if (chdir("/tmp/tmux-1000") < 0)
        err_sys("chdir failed");
    ptr = path_alloc(&size); /* our own function */
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");
    printf("cwd = %s\n", ptr);
    printf("size = %d\n", size);
    exit(0);
}
