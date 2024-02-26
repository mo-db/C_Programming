#include <stdio.h>
#include <string.h>

#define MAX_CHARS 50000
#define MAX_LINES 5000
#define MAX_LENGHT 1000

char *lines_ptr[MAX_LINES];

int read_lines(char * [], char [], int);
//int read_lines(char *[]);
void write_lines(char * [], int);
//void q_sort(char *[], int, int);
int get_line(char *, int);
char *alloc(int);

int main()
{
    char line_buffer[MAX_CHARS];
    int buffer_pos = 0;

    int n_lines;
    if ((n_lines = read_lines(lines_ptr, line_buffer, buffer_pos)) >= 0) {
        //q_sort(lines_ptr, 0, n_lines-1);
        write_lines(lines_ptr, n_lines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
    return 0;
}


int read_lines(char *lines_ptr[], char line_buffer[], int buffer_pos)
{
    int lenght, n_lines;
    char * p, line[MAX_LENGHT];

    n_lines = 0;
    while ((lenght = get_line(line, MAX_LENGHT)) > 0) {
        if (n_lines >= MAX_LINES || (buffer_pos + lenght) > MAX_CHARS) {
            return -1;
        } else {
            p = &line_buffer[buffer_pos];
            line[lenght-1] = '\0';
            strcpy(p, line);
            lines_ptr[n_lines++] = p;
            buffer_pos += lenght;
        }
    }
    return n_lines;
}

/*
int read_lines(char *lines_ptr[])
{
    int lenght, n_lines;
    char *p, line[MAX_LENGHT];

    n_lines = 0;
    while ((lenght = get_line(line, MAX_LENGHT)) > 0) {
        if (n_lines >= MAX_LINES || (p = alloc(lenght)) == NULL) {
            return -1;
        } else {
            line[lenght-1] = '\0';
            strcpy(p, line);
            lines_ptr[n_lines++] = p;
        }
    }
    return n_lines;
}
*/


void write_lines(char * lines_ptr[], int n_lines)
{
    while (n_lines-- > 0) {
        printf("%s\n", *lines_ptr++);
    }
}


int get_line(char line[], int limit)
{
    int c, i;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF
        && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
/*
// seperate source file
#define ALLOC_SIZE 10000

static char alloc_buffer[ALLOC_SIZE];
static char * alloc_ptr = alloc_buffer;

char * alloc(int n)
{
    if (alloc_buffer + ALLOC_SIZE - alloc_ptr >= n) { // it fits
        alloc_ptr += n;
        return alloc_ptr - n; // old ptr
    } else {
        return 0;
    }
}
*/
