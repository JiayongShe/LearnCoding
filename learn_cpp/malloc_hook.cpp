#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

extern "C"{
    extern void *__libc_malloc(size_t size);
    void *my_malloc(size_t size);
    void *malloc(size_t size) __attribute__((alias("my_malloc")));
}

// printf会i申请内存，在fedora25 64bit上为1024（1k），size最好大点
void* my_malloc(size_t size) {
    if (size > (1 << 20)) {
        printf("size: %ld\n", size);
        abort();
    }
    return __libc_malloc(size);
}


static void foo(void)
{
    char *ptr1 = (char *)malloc(50);
    *ptr1 = 0x99;
    free(ptr1);
    char *ptr = (char *)malloc(2 << 20);
    *ptr = 0x99;
    free(ptr);
}

int main(void)
{
    foo();
}

