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

typedef int cmp_func(void *, void *);
void line_qsort(char *[], int, int, int, cmp_func *cmp);
void swap_01(char *, char *);

int cmp_lexico(void *, void *);
int cmp_numeric(void *, void *);


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
    line_qsort(line_ptr, 0, n_lines, 2, cmp_lexico);

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


void line_qsort(char **lines, int low, int high, int field, cmp_func *cmp)
{
    int i = 0;
    int j = high;

    if (i >= j) {
        return;
    }

    while (i < j) {
        do {
            i++;
        } while (cmp(lines[i], *lines));
        do {
            j--;
        } while (!cmp(lines[i], *lines));
        if (i < j) {
            swap_01(lines[i], lines[j]);
        }

    }
    swap_01(*lines, lines[j]);

    line_qsort(values, j);
    line_qsort((values+j+1), (high-j-1));  
}


void swap_01(char *v1, char *v2) 
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int cmp_lexico(void *p1, void *p2)
{
    return strcmp((char *)p1, (char *)p2);
}

int cmp_numeric(void *p1, void *p2)
{
    if (atof((char *)p1) < atof((char *)p2)) {
        return -1;
    }
    return 1;
}