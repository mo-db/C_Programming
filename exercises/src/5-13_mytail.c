#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_LENGTH 80
#define MAX_LINES 10
#define BUFFER_SIZE MAX_LINES*LINE_MAX_LENGTH

int get_line(char []);
int read_lines(char * [], char [], int buffer_pos, int *);

int main(int argc, char * argv[])
{
    int n, arg_length;
    if (argc == 1) {
        n = 2;
    } else if (**(++argv) == '-') {
        n = atoi(++(*argv));
    } else {
        printf("invalid argument!");
    }
    printf("Length: %d\n", n);

    char * line_ary[MAX_LINES];
    char line_buffer[BUFFER_SIZE];
    int buffer_pos = 0;
    int n_lines = 0;

    if (read_lines(line_ary, line_buffer, buffer_pos, &n_lines) == 1) {
        printf("error: input exeedes allocated storage");
        return 1;
    }

    printf("\nLast %d lines:\n", n);
    if (n > n_lines) {
        n = n_lines;
    }
    for (int i = (n_lines-n); i <= n_lines; i++) {
        printf("%s\n", line_ary[i]);
    }

    return EXIT_SUCCESS;
}

int read_lines(char * line_ary[], char line_buffer[], int buffer_pos, int * n_lines)
{
    int lenght;
    char line[LINE_MAX_LENGTH], *p;

    while ((lenght = get_line(line)) > 0) {
        if (*n_lines >= MAX_LINES) {
            return 1;
        }
        p = &line_buffer[buffer_pos];
        strcpy(p, line);
        line_ary[(*n_lines)++] = p;
        buffer_pos += lenght;
    }
    return 0;
}

int get_line(char line[])
{
    char c;
    int i;

    for (i = 0; (c = getchar()) != '\n' && c != EOF; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        i++;
        line[i-1] = '\0';
    }

    return i;
}
