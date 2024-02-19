#include <stdint.h>
#include <stdio.h>

#define STRING_BUFFER_LEN_MAX 1000

uint16_t string_buffer_pos = 5;

void strcat_ptr(char *, char *);

int main()
{
    char string_buffer[STRING_BUFFER_LEN_MAX] = "Hey: ";
    char string_sample[] = "this is a sample!";
    //char *test;
    //test = string_sample;
    strcat_ptr(string_buffer, string_sample);

    /*
    for (int i = 0; i < string_buffer_pos; i++) {
        printf("%c", string_buffer[i]);
    }
    return 0;
    */
}

void strcat_ptr(char *buffer, char *sample)
{
    while (*buffer) {
        buffer++;
    }

    while ((*buffer++ = *sample++)) {
        ;
    }
    printf("what %c", *(buffer + 2));

    for (int i = 0; *(buffer + i) != '\0'; i++) {
        printf("%c", *(buffer + i));
    }

    /*
    for (int i = 0; *sample != '\0'; sample++) {
        *(buffer + string_buffer_pos) = *sample;
        string_buffer_pos++;
    }
    */
}