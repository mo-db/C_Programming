#include <stdio.h>
#define MAXLINE 1000

int getline(char current_line[], int limit);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
    int current_length;
    int max_length = 0;
    char current_line[MAXLINE];
    char longest_line[MAXLINE];

    while ((current_length = getline(current_line, MAXLINE)) > 0) {
        if (current_length > max_length) {
            max_length = current_length;
            copy(longest_line, current_line);
        }
    }
    if (max_length > 0) {
        printf("%s", longest_line);
    }
    return 0;
}

int getline(char current_line[], int limit)
{
    int c, current_length = 0;
    for (int i = 0; i < limit - 1 && (c = getchar()) != EOF
        && c != '\n'; ++i) {
        current_line[i] = c;
        ++current_length;
    }
    if (c == '\n') {

    }
    current_line[current_length] = '\0';
    return current_length;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}