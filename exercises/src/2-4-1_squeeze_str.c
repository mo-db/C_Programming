#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>


void squeezePrint(char c_remove, char str_sample[], u_int32_t str_sample_size)
{
    u_int32_t i, j;
    printf("sample string:  %s\n", str_sample);

    for (i = j = 0; str_sample[i] != '\0'; i++) {
        if (str_sample[i] != c_remove) {
            str_sample[j++] = str_sample[i];
        }
    }
    str_sample[j] = '\n';
    printf("squeezed string: %s\n", str_sample);
}


int main() 
{
    char c_remove = 'd';
    char str_sample[] = "abcdef0123456789";
    u_int32_t str_sample_size = sizeof(str_sample);

    squeezePrint(c_remove, str_sample, str_sample_size);
    printf("sizestr: %i\n", str_sample_size);

}