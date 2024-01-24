#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

int main()
{
    int size = 3;
    int8_t n = INT8_MIN;
    int i, sign;
    int save_bit = 0;
    
    

    if ((sign = n) < 0) {
        n += 1;
        save_bit = 1;
        n = -n;
        size++;
    }

    char s[++size];

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while (( n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    
    // reverse
    int j, k;
    for (k = 0; k < 2; k++) {
        int8_t temp = s[k];
        s[k] = s[(size - 2) - k];
        s[(size - 2) - k] = temp;
    }

    for (j = 0; s[j] != '\0'; j++) {
        if (j == (size - 2)) {
            s[j] += 1;
        }
        printf("%c", s[j]);
    }

    return 0;
}