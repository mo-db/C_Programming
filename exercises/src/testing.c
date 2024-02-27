#include <stdint.h>
#include <stdio.h>
#include <string.h>

// first iteration
void qs_01(int *, int);


int main()
{
    int values[] = { 8, 19, 7, 2, 11, 1, 5, 16, INT16_MAX };
    int high = 0;
    while (values[high] != INT16_MAX) {
        high++;
    }
    qs_01((values+4), high);

    return 0;
}


void qs_01(int *values, int high)
{
    printf("%d", values[4]);
}
