#include <stdio.h>
#define MAXLINE 1000

int getline(char );
void copy();

/* print longest input line */
int main(void)
{
    int current_length;
    int max_length;
    char current_line[MAXLINE];
    char longest_line[MAXLINE];

    max_length = 0;
    while ((max_length = getline()))
}