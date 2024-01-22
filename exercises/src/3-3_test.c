#include <stdio.h>
#include <stdint.h>
#include <ctype.h>



int main()
{
    int i = 0;
    char c;
    char char_ary[] = "test";

    while ((c = char_ary[i++]) != '\0') {
        printf("Char: %c\n", c);
    }
    
    return 0;
}