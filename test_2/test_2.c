#include <stddef.h>
#include <stdio.h>

int main(int argc, char* argv[])
{   long x[3] = {12345, 54321, 112233};
    printf("Hi, print here some infos!\n");
    printf("Strange: %hd %hd %hd\n", x[0], x[1], x[2]);
    printf("But: %d %d %d\n", x[0], x[1], x[2]);
// hex dump
    int i; char *p = (char *)&x;
    printf("Start hex-dump, addr %x :\n", p);
    for (i = 0; i < sizeof(x); i++) printf("%02hd ", *(p++));
    puts("");
// some various checks
    long *lp = (long *)&x;
    if (*lp > *(++lp)) puts("0 > 1");
    else puts("1 > 0");
    lp++;
    if (*lp > *(--lp)) puts("2 > 1");
    else puts("1 > 2");
    return 0;
}
