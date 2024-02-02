#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>

#define MAXLINE 10

void write_chars(char line[]);
void print_line(char line[]);

int main() 
{
    char line[MAXLINE];
    write_chars(line);
    print_line(line);
    return 0;
}

void write_chars(char s[])
{
    s[0] = 4;
    s[1] = 9;
}

void print_line(char y[])
{
    printf("Line 0: %d", y[0]);
}