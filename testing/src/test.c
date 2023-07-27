#include <stdio.h>

int main(void)
{
    int c;
    printf("testing EOF it is %d\n", EOF);
    while ((c = getchar()) != EOF) 
        putchar(c);
    if ((c = getchar()) == EOF)
        printf("int size is %lu\n", sizeof(long));
}