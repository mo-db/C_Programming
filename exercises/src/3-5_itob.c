#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>

void itob(int16_t n, int8_t b)
{
    // find max exponent that number can be divided by
    int k;
    int max_ex = 0;
    for (k = 0; n / pow(b, k) >= 1; k++) {
        max_ex = k;
    }

    // init array to hold converted number, fill first value
    // and save the difference of that value and original number in a var
    int s_size = max_ex + 1;
    char s[s_size];
    s[0] = n / pow(b, max_ex);
    int n_remain = n - (s[0] * pow(b, max_ex));
    printf("test: %i\n", n_remain);

    // iterate over remaining value from left to right
    int i, j;
    for (i = (max_ex - 1), j = 1; i >= 0 || n_remain != 0; i--, j++) {
        if (n_remain / pow(b, i) >= 1) {
            s[j] = n_remain / pow(b, i);
            n_remain -= s[j] * pow(b, i);
        } else {
            s[j] = 0;
        }
    }
    
    // print out original and converted number
    printf("original number: %i\n", n);
    printf("base%i number: ", b);
    int l;
    for (l = 0; l < s_size; l ++) {
        printf("%d", s[l]);
    }
}


int main()
{
    int16_t number = 8892;
    int8_t base = 8;

    itob(number, base);

    return 0;
}