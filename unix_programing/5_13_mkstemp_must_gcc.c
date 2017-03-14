#include "include/apue.h"
#include "lib/error.c"
#include <errno.h>

void make_temp(char *template_p);

int
main()
{
    char good_template[] = "/tmp/dirXXXXXX"; /* right way */
    char *bad_template = "/tmp/dirXXXXXX"; /* wrong way*/
    printf("trying to create first temp file...\n");
    make_temp(good_template);
    printf("trying to create second temp file...\n");
    make_temp(bad_template);
    exit(0);
}

void
make_temp(char *template_p)
{
    int fd;
    struct stat sbuf;
    if ((fd = mkstemp(template_p)) < 0)
        err_sys("can’t create temp file");
    printf("temp name = %s\n", template_p);
    close(fd);
    if (stat(template_p, &sbuf) < 0) {
        if (errno == ENOENT)
            printf("file doesn’t exist\n");
        else
            err_sys("stat failed");
    } else {
        printf("file exists\n");
        unlink(template_p);
    }
}
