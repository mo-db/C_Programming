#include <stdio.h>

#include <stddef.h>
//#include "io.h"


int main()
{
    char test_char = 'a';
    //printf("testchar value: %i", (int)test_char);
    
    int test_int = 97;
    unsigned int b;
    b = (unsigned int)test_int;
    
    printf("testint value: %u", b);
    return 0;
}