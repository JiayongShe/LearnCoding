#include "include/apue.h"
#include <errno.h>
int
main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    perror("Open error:");
    exit(0);
}
