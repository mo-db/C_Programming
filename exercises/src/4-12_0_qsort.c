#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

void q_sort(int [], int, int);
void swap(int [], int, int);

int main()
{
    int value_array[] = {8, 3, 4, 6, 2, 7, 1};
    int value_array_size = 7;
    //printf("test: %lu\n", sizeof(value_array));
    q_sort(value_array, 0, value_array_size - 1);

    printf("sorted array: ");
    for (int i = 0; i <= value_array_size - 1; i++) {
        printf("%i ", value_array[i]);
    }
    printf("\n");
    return 0;
}

void q_sort(int value_array[], int leftmost_index, int rightmost_index)
{
    int i, last;
    if (leftmost_index >= rightmost_index) {
        return;
    }
    swap(value_array, leftmost_index, (leftmost_index + rightmost_index) / 2);
    last = leftmost_index;
    for (i = leftmost_index + 1; i <= rightmost_index; i++) {
        if (value_array[i] < value_array[leftmost_index]) {
            swap(value_array, ++last, i);
        }
    }
    for (int i = 0; i <= 6; i++) {
        printf("%i ", value_array[i]);
    }
    printf("last: %i\n", last);

    swap(value_array, leftmost_index, last);
    q_sort(value_array, leftmost_index, last - 1);
    q_sort(value_array, last + 1, rightmost_index);
}

void swap(int value_array[], int i, int j)
{
    int temp;
    temp = value_array[i];
    value_array[i] = value_array[j];
    value_array[j] = temp;
}