#include <stdio.h>
char * month_name(int);

int main()
{
    int a[] = { 1, 2, 3, 4, 5};
    int b[] = { 9, 8, 7, 6, 5};
    int test = 100;
    int * p = &test;
    int * c[2];
    c[0] = a;
    c[1] = p;
    printf("%d %d\n", c[0][3], *c[1]);
    printf("%s\n", month_name(3));
    return 0;
}

char * month_name(int n)
{
    static char *name[] = {
        "Illegal Month", "January",
        "February", "March", "April",
        "May", "June", "July",
        "August", "September", "October",
        "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}