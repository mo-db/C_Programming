#include <stdio.h>

void my_qsort(int *);
int comp_descending(int, int);
int comp_ascending(int, int);
void my_swap(int *, int *);

int main(int argc, char * argv[])
{
    int sample_ary[] = { 4, 8};
    my_qsort(sample_ary);
    return 0;
}

void my_qsort(int *sample_ary)
{
    if (0) {
        comp_ascending(sample_ary[0], sample_ary[1]);
    } else {
        comp_descending(sample_ary[0], sample_ary[1]);
    }
}

int comp_ascending(int v1, int v2)
{
    return 1;
}

int comp_descending(int v1, int v2)
{
    return 1;
}

void my_swap(int *v1, int *v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}