#include <stdio.h>

#define MAX_SIZE 1000
int ptr_getline(char *);

int ptr_atoi(char *);


int main()
{
    char buffer[MAX_SIZE];
    //printf("lenght: %d\n", ptr_getline(buffer));
    //puts(buffer);

    char str_atoi[] = "145";
    //printf("converted: %d", ptr_atoi(str_atoi));

    char int_str[MAX_SIZE];
    return 0;
}

int ptr_getline(char *buffer)
{
    int line_length = 0;
    while ((*buffer = getchar()) != EOF 
        && *buffer != '\n' 
        && line_length < MAX_SIZE) 
    {
        buffer++;
        line_length++;
    }
    return line_length;
}

int ptr_atoi(char *str_atoi)
{
    int integer = 0;

    while (*str_atoi != '\0')
    {
        integer = integer * 10 + (*str_atoi++ - '0');
    }
    return integer;
}