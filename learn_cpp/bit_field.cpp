#include<stdio.h>
int main()
{
    union
    {
        struct
        {
            unsigned short s1:3;
            unsigned short s2:3;
            unsigned short s3:2;
    }x;
    char c;
    }v;


    v.c=100;
    printf("%d\n",v.x.s3);
    printf("%hd %hd %hd\n",v.x.s1, v.x.s2, v.x.s3);
}
