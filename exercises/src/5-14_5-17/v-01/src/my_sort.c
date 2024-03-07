#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://en.cppreference.com/w/c/error/errno
//https://www.youtube.com/watch?v=xedk5KXg0VI

#define ALLOC_SIZE 10000
#define MAX_LINES 100

char alloc_buffer[ALLOC_SIZE];
char *line_ptr[MAX_LINES];

int file_contetn_to_line_buffer(const char *);

typedef int cmp_func(void *, void *, int);
void line_qsort(char *[], int, int, cmp_func *cmp);
void swap_01(char *, char *);

int cmp_lexico(void *, void *, int);
int cmp_numeric(void *, void *, int);
char * select_field(char *, int);


int main(int argc, char *argv[])
{
    const char *file_name = 
    //"C:/Users/moritz/Documents/Repos/C_Programming/"
    //"exercises/src/5-14_5-17/v-01/input01.txt";
    "/Users/moritz/Repos/C_Prog/C_Programming/exercises/src/5-14_5-17/v-01/input01.txt";

    int n_lines = file_contetn_to_line_buffer(file_name);
    if (!n_lines) {
        return 1;
    }
    line_qsort(line_ptr, n_lines, 2, cmp_lexico);

    printf("Sorted: \n");
    for (int i = 0; i <= n_lines; i++) {
        printf("%s \n", line_ptr[i]);
    }

    return 0;
}


int file_contetn_to_line_buffer(const char * file_name)
{
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wdeprecated-declarations"
    FILE *input_file = fopen(file_name, "r");
    #pragma clang diagnostic pop
    if (input_file == NULL) {
        printf("ERROR: file opening failed!\n");
        return 0;
    }

    char c;
    int n_lines = 0;
    char *alloc_pos, *old_alloc_pos;
    alloc_pos = old_alloc_pos = alloc_buffer;
    while ((c = fgetc(input_file))) {
        if (c == '\n') {
            *alloc_pos++ = '\0';
            line_ptr[n_lines++] = old_alloc_pos;
            old_alloc_pos = alloc_pos;
            continue;
        } else if (c == EOF) {
            *alloc_pos = '\0';
            line_ptr[n_lines] = old_alloc_pos;
            break;
        }
        *alloc_pos++ = c;
    }

    fclose(input_file);
    return n_lines;
}


void line_qsort(char **lines, int high, int field, cmp_func *cmp)
{
    int i = 0;
    int j = high;

    if (i >= j) {
        return;
    }

    while (i < j) {
        do {
            i++;
        } while (cmp(lines[i], *lines, field) <= 0);
        do {
            j--;
        } while (cmp(lines[j], *lines, field) > 0);
        if (i < j) {
            swap_01(lines[i], lines[j]);
        }

    }
    swap_01(*lines, lines[j]);

    line_qsort(lines, j, field, cmp);
    line_qsort((lines+j+1), (high-j-1), field, cmp);  
}


void swap_01(char *v1, char *v2) 
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int cmp_lexico(void *p1, void *p2, int field)
{
    return strcmp(select_field((char *)p1, field), select_field((char *)p2, field));
}

int cmp_numeric(void *p1, void *p2, int field)
{
    return (atof(select_field((char *) p1, field)) 
            < atof(select_field((char *) p2, field))) ? -1 : 1;
}

char * select_field(char * line, int field)
{
    char field_seperator = ' ';
    char * ptr = line;
    int n_blanks = 0;
    while (n_blanks < (field - 1)) {
        if (*ptr++ == field_seperator) {
            n_blanks++;
        }
    }
    return ptr;
}