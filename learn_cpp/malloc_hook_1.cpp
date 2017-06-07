// test.cpp
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

static void* (*old_malloc_hook)(size_t, const void*); // 函数指针，用于保存原始的malloc钩子

static void* my_malloc(size_t size, const void *caller) // 自定义malloc钩子
{
    static int malloc_time = 0; // 记录malloc钩子调用了几次
    __malloc_hook = old_malloc_hook; // 还原malloc钩子，否则下面真正的malloc调用会造成递归死循环
    void *ptr = malloc(size); // 真正的内存分配
    printf("%s, addr: %p, size: %lu, time:%d\n", __func__, ptr, size, ++malloc_time);
    __malloc_hook = my_malloc; // 重置malloc钩子为自定义值
    return ptr;
}

void __attribute__((constructor)) malloc_init() // __attribute__((constructor)) 是gcc的一个特性
    // 意思是在进入main主方法之前会首先调用这个函数，我们用它来初始化malloc钩子
{
    old_malloc_hook = __malloc_hook; // 保存原始的malloc钩子
    __malloc_hook = my_malloc; // 设置malloc钩子为自定义值
}

int main()
{
    char *c = (char*)malloc(sizeof(char)); // malloc
    free(c);

    int *i = new int; // new
    delete i;

    FILE *f = fopen("./file", "r"); //fopen
    if (NULL != f) {
        fclose(f);
    }

    return 0;
}
