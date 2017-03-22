#include "include/apue.h"
#include "lib/error.c"

#include <sys/types.h>

#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd *
getpwnam(const char *name)
{
    struct passwd *ptr;
    setpwent();
    while ((ptr = getpwent()) != NULL)
        if (strcmp(name, ptr->pw_name) == 0)
            break; /* found a match */
    endpwent();
    return(ptr); /* ptr is NULL if no match found */
}


int main()
{
    struct passwd *user;
    while((user = getpwent()) != 0)
    {
        printf("%s:%d:%d:%s:%s:%s\n", user->pw_name, user->pw_uid, user->pw_gid,
        user->pw_gecos, user->pw_dir, user->pw_shell);
    }
    endpwent();
    printf("\n\n\n\n\n");

    if((user = getpwnam("yong")) != 0)
    {
        printf("%s:%d:%d:%s:%s:%s\n", user->pw_name, user->pw_uid, user->pw_gid,
        user->pw_gecos, user->pw_dir, user->pw_shell);
    }

    return 0;
}
