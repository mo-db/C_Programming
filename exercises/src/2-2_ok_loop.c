#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 1;
    enum loop { NO, YES };
    enum loop okloop = YES;

    while (okloop == YES) {
        if (i == 1) {
            okloop = YES;
            printf("1. Print");
        }
        else if (i == 1) {
            okloop = YES;
            printf("2. Print");
        }
        else if (i == 1) {
            okloop = NO;
            printf("3. Print");
        }
    }

    return 0;
}