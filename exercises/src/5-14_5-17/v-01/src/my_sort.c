#include <stdint.h>
#include <stdio.h>

void qs_01(int *, int);
void swap_01(int *, int *);

int main()
{
    int values[] = { 8, 19, 7, 88, -14, 82, 2, 11, 1, 5, 16, INT16_MAX };
    int high = 0;
    void *test;
    test = values;
    while (values[high] != INT16_MAX) {
        high++;
    }
    qs_01(test, high);

    printf("Sorted Array: ");
    for (int i = 0; values[i] != INT16_MAX; i++) {
        printf("%d ", values[i]);
    }
    return 0;
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

