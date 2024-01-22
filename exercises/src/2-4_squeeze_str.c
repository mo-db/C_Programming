#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>


void squeezePrint(char c_remove[], char str_sample[])
{
    u_int32_t i, j, k, to_remove;
    printf("sample string:      %s\n", str_sample);

    for (i = j = 0; str_sample[i] != '\0'; i++) {
        to_remove = 0;
        // Compare the string with the characters to remove and set boolean var
        for (k = 0; c_remove[k] != '\0'; k++) {
            if (str_sample[i] == c_remove[k]) {
                to_remove = 1;
            }
        }

        // if character is not in remove string 
        if (to_remove == 0) {
            str_sample[j++] = str_sample[i];
        }
    }
    str_sample[j] = '\0';
    printf("squeezed string:    %s\n", str_sample);
}


int main() 
{
    char c_remove[] = "bd37";
    char str_sample[] = "abcdef0123456789";
    squeezePrint(c_remove, str_sample);

}