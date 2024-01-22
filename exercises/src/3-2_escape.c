#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

void escape(char from[], u_int16_t size)
{
    char string_to[size];
    u_int16_t to_counter = 0;

    for (int i = 0; from[i] != '\0'; i++) {
        switch(from[i]) {
            case '\t':
                string_to[to_counter] = '\\';
                to_counter++;
                string_to[to_counter] ='t';
                to_counter++;
                break;
            case '\n':
                string_to[to_counter] = '\\';
                to_counter++;
                string_to[to_counter] ='n';
                to_counter++;
                break;
            default:
                string_to[to_counter] = from[i];
                to_counter++;
                break;
        }
    }

    printf("string: %s\n", string_to);
}

int main()
{
    char string_from[] = "hallo,    mein name is:\nmoritz\nhuber";
    u_int16_t from_size = sizeof(string_from);
    printf("string_from: %s\n\n", string_from);

    escape(string_from, from_size);

    return 0;
}