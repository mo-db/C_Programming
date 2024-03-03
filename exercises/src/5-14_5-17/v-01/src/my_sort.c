#include <stdio.h>

#define MAX_LINES 5

void my_qsort(void *[]);
int comp_descending(int);
int comp_ascending(int);
void my_swap(int *, int *);

char *lineptr[MAX_LINES];

int main(int argc, char * argv[])
{
    int sample_ary[] = { 4, 8};
    my_qsort((void **)lineptr);
    return 0;
}

void my_qsort(char *sample_ary[])
{
    if (0) {
        comp_ascending(1);
    } else {
        comp_descending(1);
    }
}

int comp_ascending(int v1)
{
    printf("asc");
    return 1;
}

int comp_descending(int v1)
{
    printf("desc");
    return 1;
}
