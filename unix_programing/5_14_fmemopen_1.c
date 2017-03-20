#include "include/apue.h"
#include "lib/error.c"

#define BSZ 48

int main()
{
    FILE *fp;
    char buf[BSZ];

    memset(buf, 'a', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    if ((fp = fmemopen(buf, BSZ, "w+")) == NULL)
        err_sys("fmemopen failed");
    printf("Initial buffer contents: %s\n", buf);
    fprintf(fp, "hello, world"); //写进缓存
    printf("Before flush: %s\n\n", buf);
    fflush(fp); //调用fflush、fclose、、fseek、fseeko、fsetpos会在当前位置添加null
    printf("After fflush: %s\n", buf);
    printf("Len of string in buf = %ld\n\n", (long)strlen(buf));

    memset(buf, 'b', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    fprintf(fp, "hello, world");
    fseek(fp, 0, SEEK_SET); //保持偏移值冲洗之后的位置
    printf("After  fseek: %s\n", buf);
    printf("Len of string in buf = %ld\n\n", (long)strlen(buf));

    memset(buf, 'c', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    fprintf(fp, "hello, world"); //继续写进去
    fseek(fp, 0, SEEK_CUR); //偏移值设为缓冲区开始位置
    printf("After fseek: %s\n", buf);
    printf("Len of string in buf = %ld\n\n", (long)strlen(buf));

    memset(buf, 'd', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    fprintf(fp, "hello, world"); //继续写进去
    fclose(fp); //然后fclose在当前位置也就是数据尾端添加一个null
    printf("After close: %s\n", buf);
    printf("Len of string in buf = %ld\n", (long)strlen(buf));

    return(0);
}
