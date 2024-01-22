#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

// upper and lower case letters and digets, (take leading or trailing - literaly) a-f-e-z-d-9-3--8
void expand(char short_s[])
{
    u_int16_t i, j;
    int sign = 1;
    u_int16_t in_group = 0;

    // Convert all letters to lower case
    for (int k = 0; short_s[k] != '\0'; k++) {
        if ('A' <= short_s[i] <='Z') {
            short_s[i] = tolower(short_s[i]);
        }
    }

    for (i = 0; short_s[i] != '\0'; i++) {
        if (isdigit(short_s[i])) {

        } else if ('a' <= short_s[i] <= 'z') {
            short_s[i] = tolower(short_s[i]);
        }
        // actions for trailing sign not in group
        if (in_group == 0 && short_s[i] == '-') {
            if (!isdigit(short_s[i+1])) {
                continue;
            } else {
                sign = -1;
                continue;
            }
        }
        // iterate over group, only break group if letter follows digit or vice versa
        // zahl wo ich bin anschauen, nächste anschauen
        int j;
        if (isdigit(short_s[i])) {
            in_group = 1;
            for (j = 0; sign * (short_s[i] - '0') + j; );
        }
    }   
}


int main()
{
    char shorthand_string[] = "a-z0-9";

    return 0;
}