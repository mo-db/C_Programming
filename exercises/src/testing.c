#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char test[] = "blabla";
    char t1[] = "lu";
    char t2[] = "ha";
    char * t_ptr[2];
    t_ptr[0] = t1;
    t_ptr[1] = t2;

    printf("%s\n", t_ptr[1]);

    return 0;
}