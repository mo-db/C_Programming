#include <stdint.h>
#include <stdio.h>
#include <string.h>

// first iteration
void qs_01(int *, int);
void swap_01(int *, int *);


int main()
{
    int values[] = { 8, 19, 7, 2, 11, 1, 5, 16, INT16_MAX };
    int length = 0;
    while (values[length] != INT16_MAX) {
        length++;
    }
    qs_01(values, length);
    for (int i = 0; values[i] != INT16_MAX; i++) {
        printf("%d ", values[i]);
    }
    return 0;
}


void qs_01(int *values, int length)
{
    int i, j;
    i= 0;
    j = length;

    if (length < 2) {
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
        } else {
            swap_01(values, &values[j]);
        }
    }

    qs_01(values, j-1);
    qs_01((values+j+1), (length-j)-1);
    if (j > 0) {
        //qs_01(values, j-1);
    }
    
    if (length-j > 0) {
        //qs_01((values+j+1), (length-j)-1);
    }
    
}


void swap_01(int *v1, int *v2) 
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}