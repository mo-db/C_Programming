#include <stdio.h>
#include <stdint.h>
#include <ctype.h>


int main()
{
    int value;
 
    if (scanf("%d", &value) == 1) {
        if (value & 0x1 != 0) {
            /* Take action if value is odd */
        }
    }
    return 0;
}