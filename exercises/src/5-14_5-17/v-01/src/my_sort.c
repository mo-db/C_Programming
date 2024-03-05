#include <stdint.h>
#include <stdio.h>

//https://en.cppreference.com/w/c/error/errno
//https://www.youtube.com/watch?v=xedk5KXg0VI

#define ALLOC_SIZE 10000
#define MAX_LINES 100

char alloc_buffer[ALLOC_SIZE];
char *line_ptr[MAX_LINES];

int file_contetn_to_line_buffer(const char *);
void qs_01(int *, int);
void swap_01(int *, int *);


int main()
{
    const char *file_name = 
    //"C:/Users/moritz/Documents/Repos/C_Programming/"
    //"exercises/src/5-14_5-17/v-01/input01.txt";
    "/Users/moritz/Repos/C_Prog/C_Programming/exercises/src/5-14_5-17/v-01/input01.txt";

    int n_lines = file_contetn_to_line_buffer(file_name);
    if (!n_lines) {
        return 1;
    }

    printf("Buffer: \n\n");
    printf("%d\n", n_lines);
    for (int i = 0; i <= n_lines; i++) {
        printf("%s\n", line_ptr[i]);
    }

    int values[] = { 8, 19, 7, 88, -14, 82, 2, 11, 1, 5, 16, INT16_MAX };
    int high = 0;
    void *test;
    test = values;
    while (values[high] != INT16_MAX) {
        high++;
    }
    qs_01(test, high);

    // lwowowowow
    printf("test");
    printf("tut");
    //test

    /*
    printf("Sorted Array: ");
    for (int i = 0; values[i] != INT16_MAX; i++) {
        printf("%d ", values[i]);
    }
    */
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


void qs_01(int *values, int high)
{
    int i = 0;
    int j = high;

    if (i >= j) {
        return;
    }

    while (i < j) {
        do {
            i++;
        } while (values[i] < *values);
        do {
            j--;
        } while (values[j] > *values);
        if (i < j) {
            swap_01(&values[i], &values[j]);
        }

    }
    swap_01(values, &values[j]);

    qs_01(values, j);
    qs_01((values+j+1), (high-j-1));  
}


void swap_01(int *v1, int *v2) 
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}