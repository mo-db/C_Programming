#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>

uint32_t strdex(char string_sample[], char string_pattern[]);

// Way to complicated, just use var for position instead of going
// form right to left,,,, but works so continue
int main()
{
    char string_sample[] = "lultestlutestleltestlu";
    char string_pattern[] = "lul";

    printf("Position: %i", strdex(string_sample, string_pattern));

    return 0;
}

uint32_t strdex(char string_sample[], char string_pattern[])
{
    int i, m;
    for (i = 0; string_sample[i] != '\0'; i++) {
        ;
    }
    u_int32_t length_sample = i;

    for (m = 0; string_pattern[m] != '\0'; m++) {
        ;
    }
    u_int32_t length_pattern = m;

    int j;
    for (j = length_sample - 1; j >= 0; j--) {
        int k, l;
        for (k = j, l = length_pattern - 1; 
        l >= 0 && string_sample[k] == string_pattern[l]; 
        k--, l--) {
            //printf("test\n");
        }
        printf("l: %i\n", l);
        if (l == -1) {
            return j;
        }
    }
    return i;   
}
