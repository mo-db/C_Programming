#include <stdio.h>
#include <stdint.h>
#include <ctype.h>



int main()
{
    int n = 327;
    int res = 0;

    res = n % 10;
    printf("%i\n", res);

    res = n / 10;
    printf("%i\n", res);

    return 0;
}