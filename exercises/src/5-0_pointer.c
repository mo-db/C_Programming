#include <stdio.h>

void test_func(int *);

int main()
{
    int test[3] = {8, 3, 9};
    for (int i = 0; i < 3; i++) {
        test_func(&test[i]);
        printf("%i ", test[i]);
    }
    

    return 0;
}

void test_func(int *test_val)
{
    *test_val += 3;
}